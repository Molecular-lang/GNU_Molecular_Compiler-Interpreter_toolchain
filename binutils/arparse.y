%{
/* arparse.y - Strange script language parser */

/* Please review: $(src-dir)/SPL-README for Licencing info. */

#define DONTDECLARE_MALLOC
#include "sysdep.h"
#include "bfd.h"
#include "arsup.h"
extern int verbose;
extern int yylex (void);
static void yyerror (const char *);
%}

%union {
  char *name;
struct list *list ;

};

%token NEWLINE
%token VERBOSE
%token <name> FILENAME
%token ADDLIB
%token LIST
%token ADDMOD
%token CLEAR
%token CREATE
%token DELETE
%token DIRECTORY
%token END
%token EXTRACT
%token FULLDIR
%token HELP
%token QUIT
%token REPLACE
%token SAVE
%token OPEN

%type <list> modulelist
%type <list> modulename
%type <name> optional_filename
%%

start:
	{ prompt(); } session
	;

session:
	    session command_line
	|
	;

command_line:
		command NEWLINE { prompt(); }
	;

command:
		open_command
	|	create_command
	| 	verbose_command
	|	directory_command
	|	addlib_command
	|	clear_command
	|	addmod_command
	| 	save_command
        |       extract_command
	|	replace_command
	|	delete_command
	|	list_command
	| 	END	 { ar_end(); return 0; }
	| 	error
	|       FILENAME { yyerror("foo"); }
	|
	;


extract_command:
                EXTRACT modulename
		{ ar_extract($2); }
	;

replace_command:
		REPLACE modulename
		{ ar_replace($2); }
	;

clear_command:
		CLEAR
		{ ar_clear(); }
	;

delete_command:
		DELETE modulename
		{ ar_delete($2); }
	;
addmod_command:
	ADDMOD modulename
		{ ar_addmod($2); }
	;

list_command:
		LIST
		{ ar_list(); }
	;

save_command:
		SAVE
		{ ar_save(); }
	;



open_command:
		OPEN FILENAME
		{ ar_open($2,0); }
	;

create_command:
		CREATE FILENAME
		{ ar_open($2,1); }
	;


addlib_command:
		ADDLIB FILENAME modulelist
		{ ar_addlib($2,$3); }
	;
directory_command:
		DIRECTORY FILENAME modulelist optional_filename
		{ ar_directory($2, $3, $4); }
	;



optional_filename:
		FILENAME
		{ $$ = $1; }
	|	{ $$ = 0; }
	;

modulelist:
	'(' modulename ')'
		{ $$ = $2; }
	|
		{ $$ = 0; }
	;

modulename:
		modulename optcomma FILENAME
		{ 	struct list *n  = (struct list *) malloc(sizeof(struct list));
			n->next = $1;
			n->name = $3;
			$$ = n;
		 }
	|	{ $$ = 0; }
	;


optcomma:
		','
	|
	;


verbose_command:
	VERBOSE
		{ verbose = !verbose; }
	;


%%

static void
yyerror (const char *x ATTRIBUTE_UNUSED)
{
  extern int linenumber;

  printf (_("Syntax error in archive script, line %d\n"), linenumber + 1);
}
