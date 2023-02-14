/* A Bison parser, made by GNU Bison 3.8.2.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_ITBL_PARSE_H_INCLUDED
# define YY_YY_ITBL_PARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DREG = 258,                    /* DREG  */
    CREG = 259,                    /* CREG  */
    GREG = 260,                    /* GREG  */
    IMMED = 261,                   /* IMMED  */
    ADDR = 262,                    /* ADDR  */
    INSN = 263,                    /* INSN  */
    NUM = 264,                     /* NUM  */
    ID = 265,                      /* ID  */
    NL = 266,                      /* NL  */
    PNUM = 267                     /* PNUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DREG 258
#define CREG 259
#define GREG 260
#define IMMED 261
#define ADDR 262
#define INSN 263
#define NUM 264
#define ID 265
#define NL 266
#define PNUM 267

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 282 "./itbl-parse.y"

    char *str;
    int num;
    int processor;
    unsigned long val;
  

#line 99 "itbl-parse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_ITBL_PARSE_H_INCLUDED  */
