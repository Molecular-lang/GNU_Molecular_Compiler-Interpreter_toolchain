/* A Bison parser, made by GNU Bison 3.8.2.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_MCPARSE_H_INCLUDED
# define YY_YY_MCPARSE_H_INCLUDED
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
    NL = 258,                      /* NL  */
    MCIDENT = 259,                 /* MCIDENT  */
    MCFILENAME = 260,              /* MCFILENAME  */
    MCLINE = 261,                  /* MCLINE  */
    MCCOMMENT = 262,               /* MCCOMMENT  */
    MCTOKEN = 263,                 /* MCTOKEN  */
    MCENDLINE = 264,               /* MCENDLINE  */
    MCLANGUAGENAMES = 265,         /* MCLANGUAGENAMES  */
    MCFACILITYNAMES = 266,         /* MCFACILITYNAMES  */
    MCSEVERITYNAMES = 267,         /* MCSEVERITYNAMES  */
    MCOUTPUTBASE = 268,            /* MCOUTPUTBASE  */
    MCMESSAGEIDTYPEDEF = 269,      /* MCMESSAGEIDTYPEDEF  */
    MCLANGUAGE = 270,              /* MCLANGUAGE  */
    MCMESSAGEID = 271,             /* MCMESSAGEID  */
    MCSEVERITY = 272,              /* MCSEVERITY  */
    MCFACILITY = 273,              /* MCFACILITY  */
    MCSYMBOLICNAME = 274,          /* MCSYMBOLICNAME  */
    MCNUMBER = 275                 /* MCNUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NL 258
#define MCIDENT 259
#define MCFILENAME 260
#define MCLINE 261
#define MCCOMMENT 262
#define MCTOKEN 263
#define MCENDLINE 264
#define MCLANGUAGENAMES 265
#define MCFACILITYNAMES 266
#define MCSEVERITYNAMES 267
#define MCOUTPUTBASE 268
#define MCMESSAGEIDTYPEDEF 269
#define MCLANGUAGE 270
#define MCMESSAGEID 271
#define MCSEVERITY 272
#define MCFACILITY 273
#define MCSYMBOLICNAME 274
#define MCNUMBER 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 44 "mcparse.y"

  rc_uint_type ival;
  unichar *ustr;
  const mc_keyword *tok;
  mc_node *nod;

#line 114 "mcparse.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_MCPARSE_H_INCLUDED  */
