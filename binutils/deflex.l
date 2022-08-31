%option noinput nounput noyywrap

%{/* deflex.l - Lexer for .def files */

/* Please review: $(src-dir)/SPL-README for Licencing info. */

#define DONTDECLARE_MALLOC
#include "libiberty.h"
#include "defparse.h"
#include "dlltool.h"

int linenumber;

%}
%%
"NAME" 		{ return NAME;}
"LIBRARY"	{ return LIBRARY;}
"DESCRIPTION" 	{ return DESCRIPTION;}
"STACKSIZE"	{ return STACKSIZE;}
"HEAPSIZE" 	{ return HEAPSIZE;}
"CODE" 		{ return CODE;}
"DATA"		{ return DATA;}
"SECTIONS"	{ return SECTIONS;}
"EXPORTS"	{ return EXPORTS;}
"IMPORTS"	{ return IMPORTS;}
"VERSION"	{ return VERSIONK;}
"BASE"		{ return BASE;}
"CONSTANT"	{ return CONSTANT; }
"NONAME"	{ return NONAME; }
"PRIVATE"	{ return PRIVATE; }
"READ"		{ return READ;}
"WRITE"		{ return WRITE;}
"EXECUTE"	{ return EXECUTE;}
"SHARED"	{ return SHARED;}
"NONSHARED"	{ return NONSHARED;}
"SINGLE"	{ return SINGLE;}
"MULTIPLE"	{ return MULTIPLE;}
"INITINSTANCE"	{ return INITINSTANCE;}
"INITGLOBAL"	{ return INITGLOBAL;}
"TERMINSTANCE"	{ return TERMINSTANCE;}
"TERMGLOBAL"	{ return TERMGLOBAL;}

[0-9][x0-9A-Fa-f]* { yylval.number = strtol (yytext,0,0);
		return NUMBER; }

(@)?[A-Za-z$:\-\_?][A-Za-z0-9/$:\<\>\-\_@?+]* {
		yylval.id =  xstrdup (yytext);
		return ID;
		}

"\""[^\"]*"\"" {
		yylval.id = xmemdup (yytext + 1, yyleng - 2, yyleng - 1);
		return ID;
		}

"\'"[^\']*"\'" {
		yylval.id = xmemdup (yytext + 1, yyleng - 2, yyleng - 1);
		return ID;
		}
"*".* 		{ }
";".* 		{ }
" "		{ }
"\t"		{ }
"\r"		{ }
"\n"	 	{ linenumber ++ ;}
"=="		{ return EQUAL;}
"=" 		{ return '=';}
"." 		{ return '.';}
"@"	 	{ return '@';}
","		{ return ',';}
%%
