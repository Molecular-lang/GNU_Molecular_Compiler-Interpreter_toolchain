/* A Bison parser, made by GNU Bison 3.8.2.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DEFPARSE_H_INCLUDED
# define YY_YY_DEFPARSE_H_INCLUDED
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
    NAME = 258,                    /* NAME  */
    LIBRARY = 259,                 /* LIBRARY  */
    DESCRIPTION = 260,             /* DESCRIPTION  */
    STACKSIZE = 261,               /* STACKSIZE  */
    HEAPSIZE = 262,                /* HEAPSIZE  */
    CODE = 263,                    /* CODE  */
    DATA = 264,                    /* DATA  */
    SECTIONS = 265,                /* SECTIONS  */
    EXPORTS = 266,                 /* EXPORTS  */
    IMPORTS = 267,                 /* IMPORTS  */
    VERSIONK = 268,                /* VERSIONK  */
    BASE = 269,                    /* BASE  */
    CONSTANT = 270,                /* CONSTANT  */
    READ = 271,                    /* READ  */
    WRITE = 272,                   /* WRITE  */
    EXECUTE = 273,                 /* EXECUTE  */
    SHARED = 274,                  /* SHARED  */
    NONSHARED = 275,               /* NONSHARED  */
    NONAME = 276,                  /* NONAME  */
    PRIVATE = 277,                 /* PRIVATE  */
    SINGLE = 278,                  /* SINGLE  */
    MULTIPLE = 279,                /* MULTIPLE  */
    INITINSTANCE = 280,            /* INITINSTANCE  */
    INITGLOBAL = 281,              /* INITGLOBAL  */
    TERMINSTANCE = 282,            /* TERMINSTANCE  */
    TERMGLOBAL = 283,              /* TERMGLOBAL  */
    EQUAL = 284,                   /* EQUAL  */
    ID = 285,                      /* ID  */
    NUMBER = 286                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NAME 258
#define LIBRARY 259
#define DESCRIPTION 260
#define STACKSIZE 261
#define HEAPSIZE 262
#define CODE 263
#define DATA 264
#define SECTIONS 265
#define EXPORTS 266
#define IMPORTS 267
#define VERSIONK 268
#define BASE 269
#define CONSTANT 270
#define READ 271
#define WRITE 272
#define EXECUTE 273
#define SHARED 274
#define NONSHARED 275
#define NONAME 276
#define PRIVATE 277
#define SINGLE 278
#define MULTIPLE 279
#define INITINSTANCE 280
#define INITGLOBAL 281
#define TERMINSTANCE 282
#define TERMGLOBAL 283
#define EQUAL 284
#define ID 285
#define NUMBER 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "defparse.y"

  char *id;
  const char *id_const;
  int number;

#line 135 "defparse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DEFPARSE_H_INCLUDED  */
