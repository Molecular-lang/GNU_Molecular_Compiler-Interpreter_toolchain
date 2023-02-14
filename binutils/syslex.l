%option noinput nounput noyywrap

%{

/* Note: config.h is #included via syslex_wrap.c.  */

#include <string.h>
#include "sysinfo.h"

#ifndef YY_NO_UNPUT
#define YY_NO_UNPUT
#endif

extern int yylex (void);
%}
%%
"(" { return '(';}
")" { return ')';}
"[" { return '[';}
"]" { return ']';}
" " { ; }
";".* { ; }
"\t" { ; }
"\n" { ; }
"\""[^\"]*"\"" {
	yylval.s = malloc (yyleng - 1);
	memcpy (yylval.s, yytext + 1, yyleng - 2);
	yylval.s[yyleng - 2] = '\0';
        return NAME;
	}

0x[0-9a-f]+ {
        yylval.i = strtol(yytext,0,16);
	return  NUMBER;
	}

[0-9]+ {
        yylval.i = atoi(yytext);
	return  NUMBER;
	}


"bits" { yylval.i =1 ;return UNIT;}
"bit" { yylval.i = 1; return UNIT;}
"bytes" { yylval.i= 8; return UNIT;}
"byte" { yylval.i = 8; return UNIT;}

"int" { yylval.s = "INT"; return TYPE;}
"barray" { yylval.s = "BARRAY"; return TYPE;}
"chars" { yylval.s = "CHARS"; return TYPE;}
"variable" { yylval.i = 0; return NUMBER;}
"counted" { yylval.i = -4; return NUMBER;}
"addrsize" { yylval.i = -2; return NUMBER; }
"segsize" { yylval.i = -1; return NUMBER; }
"cond" { return COND;}
"repeat" { return REPEAT;}
