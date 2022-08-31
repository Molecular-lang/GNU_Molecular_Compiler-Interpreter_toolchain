/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "../../Scpel-0.0.7/ld/ldgram.y"


#define DONTDECLARE_MALLOC

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "ctf-api.h"
#include "ld.h"
#include "ldexp.h"
#include "ldver.h"
#include "ldlang.h"
#include "ldfile.h"
#include "ldemul.h"
#include "ldmisc.h"
#include "ldmain.h"
#include "mri.h"
#include "ldctor.h"
#include "ldlex.h"

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

static enum section_type sectype;
static lang_memory_region_type *region;

static bool ldgram_had_keep = false;
static char *ldgram_vers_current_lang = NULL;

#define ERROR_NAME_MAX 20
static char *error_names[ERROR_NAME_MAX];
static int error_index;
#define PUSH_ERROR(x) if (error_index < ERROR_NAME_MAX) error_names[error_index] = x; error_index++;
#define POP_ERROR()   error_index--;

#line 108 "../../Scpel-0.0.7/ld/ldgram.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY__SCPEL_LD_LDGRAM_H_INCLUDED
# define YY_YY__SCPEL_LD_LDGRAM_H_INCLUDED
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
    INT = 258,                     /* INT  */
    NAME = 259,                    /* NAME  */
    LNAME = 260,                   /* LNAME  */
    PLUSEQ = 261,                  /* PLUSEQ  */
    MINUSEQ = 262,                 /* MINUSEQ  */
    MULTEQ = 263,                  /* MULTEQ  */
    DIVEQ = 264,                   /* DIVEQ  */
    LSHIFTEQ = 265,                /* LSHIFTEQ  */
    RSHIFTEQ = 266,                /* RSHIFTEQ  */
    ANDEQ = 267,                   /* ANDEQ  */
    OREQ = 268,                    /* OREQ  */
    OROR = 269,                    /* OROR  */
    ANDAND = 270,                  /* ANDAND  */
    EQ = 271,                      /* EQ  */
    NE = 272,                      /* NE  */
    LE = 273,                      /* LE  */
    GE = 274,                      /* GE  */
    LSHIFT = 275,                  /* LSHIFT  */
    RSHIFT = 276,                  /* RSHIFT  */
    UNARY = 277,                   /* UNARY  */
    END = 278,                     /* END  */
    ALIGN_K = 279,                 /* ALIGN_K  */
    BLOCK = 280,                   /* BLOCK  */
    BIND = 281,                    /* BIND  */
    QUAD = 282,                    /* QUAD  */
    SQUAD = 283,                   /* SQUAD  */
    LONG = 284,                    /* LONG  */
    SHORT = 285,                   /* SHORT  */
    BYTE = 286,                    /* BYTE  */
    SECTIONS = 287,                /* SECTIONS  */
    PHDRS = 288,                   /* PHDRS  */
    INSERT_K = 289,                /* INSERT_K  */
    AFTER = 290,                   /* AFTER  */
    BEFORE = 291,                  /* BEFORE  */
    DATA_SEGMENT_ALIGN = 292,      /* DATA_SEGMENT_ALIGN  */
    DATA_SEGMENT_RELRO_END = 293,  /* DATA_SEGMENT_RELRO_END  */
    DATA_SEGMENT_END = 294,        /* DATA_SEGMENT_END  */
    SORT_BY_NAME = 295,            /* SORT_BY_NAME  */
    SORT_BY_ALIGNMENT = 296,       /* SORT_BY_ALIGNMENT  */
    SORT_NONE = 297,               /* SORT_NONE  */
    SORT_BY_INIT_PRIORITY = 298,   /* SORT_BY_INIT_PRIORITY  */
    SIZEOF_HEADERS = 299,          /* SIZEOF_HEADERS  */
    OUTPUT_FORMAT = 300,           /* OUTPUT_FORMAT  */
    FORCE_COMMON_ALLOCATION = 301, /* FORCE_COMMON_ALLOCATION  */
    OUTPUT_ARCH = 302,             /* OUTPUT_ARCH  */
    INHIBIT_COMMON_ALLOCATION = 303, /* INHIBIT_COMMON_ALLOCATION  */
    FORCE_GROUP_ALLOCATION = 304,  /* FORCE_GROUP_ALLOCATION  */
    SEGMENT_START = 305,           /* SEGMENT_START  */
    INCLUDE = 306,                 /* INCLUDE  */
    MEMORY = 307,                  /* MEMORY  */
    REGION_ALIAS = 308,            /* REGION_ALIAS  */
    LD_FEATURE = 309,              /* LD_FEATURE  */
    NOLOAD = 310,                  /* NOLOAD  */
    DSECT = 311,                   /* DSECT  */
    COPY = 312,                    /* COPY  */
    INFO = 313,                    /* INFO  */
    OVERLAY = 314,                 /* OVERLAY  */
    READONLY = 315,                /* READONLY  */
    DEFINED = 316,                 /* DEFINED  */
    TARGET_K = 317,                /* TARGET_K  */
    SEARCH_DIR = 318,              /* SEARCH_DIR  */
    MAP = 319,                     /* MAP  */
    ENTRY = 320,                   /* ENTRY  */
    NEXT = 321,                    /* NEXT  */
    SIZEOF = 322,                  /* SIZEOF  */
    ALIGNOF = 323,                 /* ALIGNOF  */
    ADDR = 324,                    /* ADDR  */
    LOADADDR = 325,                /* LOADADDR  */
    MAX_K = 326,                   /* MAX_K  */
    MIN_K = 327,                   /* MIN_K  */
    STARTUP = 328,                 /* STARTUP  */
    HLL = 329,                     /* HLL  */
    SYSLIB = 330,                  /* SYSLIB  */
    FLOAT = 331,                   /* FLOAT  */
    NOFLOAT = 332,                 /* NOFLOAT  */
    NOCROSSREFS = 333,             /* NOCROSSREFS  */
    NOCROSSREFS_TO = 334,          /* NOCROSSREFS_TO  */
    ORIGIN = 335,                  /* ORIGIN  */
    FILL = 336,                    /* FILL  */
    LENGTH = 337,                  /* LENGTH  */
    CREATE_OBJECT_SYMBOLS = 338,   /* CREATE_OBJECT_SYMBOLS  */
    INPUT = 339,                   /* INPUT  */
    GROUP = 340,                   /* GROUP  */
    OUTPUT = 341,                  /* OUTPUT  */
    CONSTRUCTORS = 342,            /* CONSTRUCTORS  */
    ALIGNMOD = 343,                /* ALIGNMOD  */
    AT = 344,                      /* AT  */
    SUBALIGN = 345,                /* SUBALIGN  */
    HIDDEN = 346,                  /* HIDDEN  */
    PROVIDE = 347,                 /* PROVIDE  */
    PROVIDE_HIDDEN = 348,          /* PROVIDE_HIDDEN  */
    AS_NEEDED = 349,               /* AS_NEEDED  */
    CHIP = 350,                    /* CHIP  */
    LIST = 351,                    /* LIST  */
    SECT = 352,                    /* SECT  */
    ABSOLUTE = 353,                /* ABSOLUTE  */
    LOAD = 354,                    /* LOAD  */
    NEWLINE = 355,                 /* NEWLINE  */
    ENDWORD = 356,                 /* ENDWORD  */
    ORDER = 357,                   /* ORDER  */
    NAMEWORD = 358,                /* NAMEWORD  */
    ASSERT_K = 359,                /* ASSERT_K  */
    LOG2CEIL = 360,                /* LOG2CEIL  */
    FORMAT = 361,                  /* FORMAT  */
    PUBLIC = 362,                  /* PUBLIC  */
    DEFSYMEND = 363,               /* DEFSYMEND  */
    BASE = 364,                    /* BASE  */
    ALIAS = 365,                   /* ALIAS  */
    TRUNCATE = 366,                /* TRUNCATE  */
    REL = 367,                     /* REL  */
    INPUT_SCRIPT = 368,            /* INPUT_SCRIPT  */
    INPUT_MRI_SCRIPT = 369,        /* INPUT_MRI_SCRIPT  */
    INPUT_DEFSYM = 370,            /* INPUT_DEFSYM  */
    CASE = 371,                    /* CASE  */
    EXTERN = 372,                  /* EXTERN  */
    START = 373,                   /* START  */
    VERS_TAG = 374,                /* VERS_TAG  */
    VERS_IDENTIFIER = 375,         /* VERS_IDENTIFIER  */
    GLOBAL = 376,                  /* GLOBAL  */
    LOCAL = 377,                   /* LOCAL  */
    VERSIONK = 378,                /* VERSIONK  */
    INPUT_VERSION_SCRIPT = 379,    /* INPUT_VERSION_SCRIPT  */
    KEEP = 380,                    /* KEEP  */
    ONLY_IF_RO = 381,              /* ONLY_IF_RO  */
    ONLY_IF_RW = 382,              /* ONLY_IF_RW  */
    SPECIAL = 383,                 /* SPECIAL  */
    INPUT_SECTION_FLAGS = 384,     /* INPUT_SECTION_FLAGS  */
    ALIGN_WITH_INPUT = 385,        /* ALIGN_WITH_INPUT  */
    EXCLUDE_FILE = 386,            /* EXCLUDE_FILE  */
    CONSTANT = 387,                /* CONSTANT  */
    INPUT_DYNAMIC_LIST = 388       /* INPUT_DYNAMIC_LIST  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define INT 258
#define NAME 259
#define LNAME 260
#define PLUSEQ 261
#define MINUSEQ 262
#define MULTEQ 263
#define DIVEQ 264
#define LSHIFTEQ 265
#define RSHIFTEQ 266
#define ANDEQ 267
#define OREQ 268
#define OROR 269
#define ANDAND 270
#define EQ 271
#define NE 272
#define LE 273
#define GE 274
#define LSHIFT 275
#define RSHIFT 276
#define UNARY 277
#define END 278
#define ALIGN_K 279
#define BLOCK 280
#define BIND 281
#define QUAD 282
#define SQUAD 283
#define LONG 284
#define SHORT 285
#define BYTE 286
#define SECTIONS 287
#define PHDRS 288
#define INSERT_K 289
#define AFTER 290
#define BEFORE 291
#define DATA_SEGMENT_ALIGN 292
#define DATA_SEGMENT_RELRO_END 293
#define DATA_SEGMENT_END 294
#define SORT_BY_NAME 295
#define SORT_BY_ALIGNMENT 296
#define SORT_NONE 297
#define SORT_BY_INIT_PRIORITY 298
#define SIZEOF_HEADERS 299
#define OUTPUT_FORMAT 300
#define FORCE_COMMON_ALLOCATION 301
#define OUTPUT_ARCH 302
#define INHIBIT_COMMON_ALLOCATION 303
#define FORCE_GROUP_ALLOCATION 304
#define SEGMENT_START 305
#define INCLUDE 306
#define MEMORY 307
#define REGION_ALIAS 308
#define LD_FEATURE 309
#define NOLOAD 310
#define DSECT 311
#define COPY 312
#define INFO 313
#define OVERLAY 314
#define READONLY 315
#define DEFINED 316
#define TARGET_K 317
#define SEARCH_DIR 318
#define MAP 319
#define ENTRY 320
#define NEXT 321
#define SIZEOF 322
#define ALIGNOF 323
#define ADDR 324
#define LOADADDR 325
#define MAX_K 326
#define MIN_K 327
#define STARTUP 328
#define HLL 329
#define SYSLIB 330
#define FLOAT 331
#define NOFLOAT 332
#define NOCROSSREFS 333
#define NOCROSSREFS_TO 334
#define ORIGIN 335
#define FILL 336
#define LENGTH 337
#define CREATE_OBJECT_SYMBOLS 338
#define INPUT 339
#define GROUP 340
#define OUTPUT 341
#define CONSTRUCTORS 342
#define ALIGNMOD 343
#define AT 344
#define SUBALIGN 345
#define HIDDEN 346
#define PROVIDE 347
#define PROVIDE_HIDDEN 348
#define AS_NEEDED 349
#define CHIP 350
#define LIST 351
#define SECT 352
#define ABSOLUTE 353
#define LOAD 354
#define NEWLINE 355
#define ENDWORD 356
#define ORDER 357
#define NAMEWORD 358
#define ASSERT_K 359
#define LOG2CEIL 360
#define FORMAT 361
#define PUBLIC 362
#define DEFSYMEND 363
#define BASE 364
#define ALIAS 365
#define TRUNCATE 366
#define REL 367
#define INPUT_SCRIPT 368
#define INPUT_MRI_SCRIPT 369
#define INPUT_DEFSYM 370
#define CASE 371
#define EXTERN 372
#define START 373
#define VERS_TAG 374
#define VERS_IDENTIFIER 375
#define GLOBAL 376
#define LOCAL 377
#define VERSIONK 378
#define INPUT_VERSION_SCRIPT 379
#define KEEP 380
#define ONLY_IF_RO 381
#define ONLY_IF_RW 382
#define SPECIAL 383
#define INPUT_SECTION_FLAGS 384
#define ALIGN_WITH_INPUT 385
#define EXCLUDE_FILE 386
#define CONSTANT 387
#define INPUT_DYNAMIC_LIST 388

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 40 "../../Scpel-0.0.7/ld/ldgram.y"

  bfd_vma integer;
  struct big_int
    {
      bfd_vma integer;
      char *str;
    } bigint;
  fill_type *fill;
  char *name;
  const char *cname;
  struct wildcard_spec wildcard;
  struct wildcard_list *wildcard_list;
  struct name_list *name_list;
  struct flag_info_list *flag_info_list;
  struct flag_info *flag_info;
  int token;
  union etree_union *etree;
  struct phdr_info
    {
      bool filehdr;
      bool phdrs;
      union etree_union *at;
      union etree_union *flags;
    } phdr;
  struct lang_nocrossref *nocrossref;
  struct lang_output_section_phdr_list *section_phdr;
  struct bfd_elf_version_deps *deflist;
  struct bfd_elf_version_expr *versyms;
  struct bfd_elf_version_tree *versnode;

#line 458 "../../Scpel-0.0.7/ld/ldgram.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SCPEL_LD_LDGRAM_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_NAME = 4,                       /* NAME  */
  YYSYMBOL_LNAME = 5,                      /* LNAME  */
  YYSYMBOL_PLUSEQ = 6,                     /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 7,                    /* MINUSEQ  */
  YYSYMBOL_MULTEQ = 8,                     /* MULTEQ  */
  YYSYMBOL_DIVEQ = 9,                      /* DIVEQ  */
  YYSYMBOL_10_ = 10,                       /* '='  */
  YYSYMBOL_LSHIFTEQ = 11,                  /* LSHIFTEQ  */
  YYSYMBOL_RSHIFTEQ = 12,                  /* RSHIFTEQ  */
  YYSYMBOL_ANDEQ = 13,                     /* ANDEQ  */
  YYSYMBOL_OREQ = 14,                      /* OREQ  */
  YYSYMBOL_15_ = 15,                       /* '?'  */
  YYSYMBOL_16_ = 16,                       /* ':'  */
  YYSYMBOL_OROR = 17,                      /* OROR  */
  YYSYMBOL_ANDAND = 18,                    /* ANDAND  */
  YYSYMBOL_19_ = 19,                       /* '|'  */
  YYSYMBOL_20_ = 20,                       /* '^'  */
  YYSYMBOL_21_ = 21,                       /* '&'  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_24_ = 24,                       /* '<'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_LE = 26,                        /* LE  */
  YYSYMBOL_GE = 27,                        /* GE  */
  YYSYMBOL_LSHIFT = 28,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 29,                    /* RSHIFT  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_UNARY = 35,                     /* UNARY  */
  YYSYMBOL_END = 36,                       /* END  */
  YYSYMBOL_37_ = 37,                       /* '('  */
  YYSYMBOL_ALIGN_K = 38,                   /* ALIGN_K  */
  YYSYMBOL_BLOCK = 39,                     /* BLOCK  */
  YYSYMBOL_BIND = 40,                      /* BIND  */
  YYSYMBOL_QUAD = 41,                      /* QUAD  */
  YYSYMBOL_SQUAD = 42,                     /* SQUAD  */
  YYSYMBOL_LONG = 43,                      /* LONG  */
  YYSYMBOL_SHORT = 44,                     /* SHORT  */
  YYSYMBOL_BYTE = 45,                      /* BYTE  */
  YYSYMBOL_SECTIONS = 46,                  /* SECTIONS  */
  YYSYMBOL_PHDRS = 47,                     /* PHDRS  */
  YYSYMBOL_INSERT_K = 48,                  /* INSERT_K  */
  YYSYMBOL_AFTER = 49,                     /* AFTER  */
  YYSYMBOL_BEFORE = 50,                    /* BEFORE  */
  YYSYMBOL_DATA_SEGMENT_ALIGN = 51,        /* DATA_SEGMENT_ALIGN  */
  YYSYMBOL_DATA_SEGMENT_RELRO_END = 52,    /* DATA_SEGMENT_RELRO_END  */
  YYSYMBOL_DATA_SEGMENT_END = 53,          /* DATA_SEGMENT_END  */
  YYSYMBOL_SORT_BY_NAME = 54,              /* SORT_BY_NAME  */
  YYSYMBOL_SORT_BY_ALIGNMENT = 55,         /* SORT_BY_ALIGNMENT  */
  YYSYMBOL_SORT_NONE = 56,                 /* SORT_NONE  */
  YYSYMBOL_SORT_BY_INIT_PRIORITY = 57,     /* SORT_BY_INIT_PRIORITY  */
  YYSYMBOL_58_ = 58,                       /* '{'  */
  YYSYMBOL_59_ = 59,                       /* '}'  */
  YYSYMBOL_SIZEOF_HEADERS = 60,            /* SIZEOF_HEADERS  */
  YYSYMBOL_OUTPUT_FORMAT = 61,             /* OUTPUT_FORMAT  */
  YYSYMBOL_FORCE_COMMON_ALLOCATION = 62,   /* FORCE_COMMON_ALLOCATION  */
  YYSYMBOL_OUTPUT_ARCH = 63,               /* OUTPUT_ARCH  */
  YYSYMBOL_INHIBIT_COMMON_ALLOCATION = 64, /* INHIBIT_COMMON_ALLOCATION  */
  YYSYMBOL_FORCE_GROUP_ALLOCATION = 65,    /* FORCE_GROUP_ALLOCATION  */
  YYSYMBOL_SEGMENT_START = 66,             /* SEGMENT_START  */
  YYSYMBOL_INCLUDE = 67,                   /* INCLUDE  */
  YYSYMBOL_MEMORY = 68,                    /* MEMORY  */
  YYSYMBOL_REGION_ALIAS = 69,              /* REGION_ALIAS  */
  YYSYMBOL_LD_FEATURE = 70,                /* LD_FEATURE  */
  YYSYMBOL_NOLOAD = 71,                    /* NOLOAD  */
  YYSYMBOL_DSECT = 72,                     /* DSECT  */
  YYSYMBOL_COPY = 73,                      /* COPY  */
  YYSYMBOL_INFO = 74,                      /* INFO  */
  YYSYMBOL_OVERLAY = 75,                   /* OVERLAY  */
  YYSYMBOL_READONLY = 76,                  /* READONLY  */
  YYSYMBOL_DEFINED = 77,                   /* DEFINED  */
  YYSYMBOL_TARGET_K = 78,                  /* TARGET_K  */
  YYSYMBOL_SEARCH_DIR = 79,                /* SEARCH_DIR  */
  YYSYMBOL_MAP = 80,                       /* MAP  */
  YYSYMBOL_ENTRY = 81,                     /* ENTRY  */
  YYSYMBOL_NEXT = 82,                      /* NEXT  */
  YYSYMBOL_SIZEOF = 83,                    /* SIZEOF  */
  YYSYMBOL_ALIGNOF = 84,                   /* ALIGNOF  */
  YYSYMBOL_ADDR = 85,                      /* ADDR  */
  YYSYMBOL_LOADADDR = 86,                  /* LOADADDR  */
  YYSYMBOL_MAX_K = 87,                     /* MAX_K  */
  YYSYMBOL_MIN_K = 88,                     /* MIN_K  */
  YYSYMBOL_STARTUP = 89,                   /* STARTUP  */
  YYSYMBOL_HLL = 90,                       /* HLL  */
  YYSYMBOL_SYSLIB = 91,                    /* SYSLIB  */
  YYSYMBOL_FLOAT = 92,                     /* FLOAT  */
  YYSYMBOL_NOFLOAT = 93,                   /* NOFLOAT  */
  YYSYMBOL_NOCROSSREFS = 94,               /* NOCROSSREFS  */
  YYSYMBOL_NOCROSSREFS_TO = 95,            /* NOCROSSREFS_TO  */
  YYSYMBOL_ORIGIN = 96,                    /* ORIGIN  */
  YYSYMBOL_FILL = 97,                      /* FILL  */
  YYSYMBOL_LENGTH = 98,                    /* LENGTH  */
  YYSYMBOL_CREATE_OBJECT_SYMBOLS = 99,     /* CREATE_OBJECT_SYMBOLS  */
  YYSYMBOL_INPUT = 100,                    /* INPUT  */
  YYSYMBOL_GROUP = 101,                    /* GROUP  */
  YYSYMBOL_OUTPUT = 102,                   /* OUTPUT  */
  YYSYMBOL_CONSTRUCTORS = 103,             /* CONSTRUCTORS  */
  YYSYMBOL_ALIGNMOD = 104,                 /* ALIGNMOD  */
  YYSYMBOL_AT = 105,                       /* AT  */
  YYSYMBOL_SUBALIGN = 106,                 /* SUBALIGN  */
  YYSYMBOL_HIDDEN = 107,                   /* HIDDEN  */
  YYSYMBOL_PROVIDE = 108,                  /* PROVIDE  */
  YYSYMBOL_PROVIDE_HIDDEN = 109,           /* PROVIDE_HIDDEN  */
  YYSYMBOL_AS_NEEDED = 110,                /* AS_NEEDED  */
  YYSYMBOL_CHIP = 111,                     /* CHIP  */
  YYSYMBOL_LIST = 112,                     /* LIST  */
  YYSYMBOL_SECT = 113,                     /* SECT  */
  YYSYMBOL_ABSOLUTE = 114,                 /* ABSOLUTE  */
  YYSYMBOL_LOAD = 115,                     /* LOAD  */
  YYSYMBOL_NEWLINE = 116,                  /* NEWLINE  */
  YYSYMBOL_ENDWORD = 117,                  /* ENDWORD  */
  YYSYMBOL_ORDER = 118,                    /* ORDER  */
  YYSYMBOL_NAMEWORD = 119,                 /* NAMEWORD  */
  YYSYMBOL_ASSERT_K = 120,                 /* ASSERT_K  */
  YYSYMBOL_LOG2CEIL = 121,                 /* LOG2CEIL  */
  YYSYMBOL_FORMAT = 122,                   /* FORMAT  */
  YYSYMBOL_PUBLIC = 123,                   /* PUBLIC  */
  YYSYMBOL_DEFSYMEND = 124,                /* DEFSYMEND  */
  YYSYMBOL_BASE = 125,                     /* BASE  */
  YYSYMBOL_ALIAS = 126,                    /* ALIAS  */
  YYSYMBOL_TRUNCATE = 127,                 /* TRUNCATE  */
  YYSYMBOL_REL = 128,                      /* REL  */
  YYSYMBOL_INPUT_SCRIPT = 129,             /* INPUT_SCRIPT  */
  YYSYMBOL_INPUT_MRI_SCRIPT = 130,         /* INPUT_MRI_SCRIPT  */
  YYSYMBOL_INPUT_DEFSYM = 131,             /* INPUT_DEFSYM  */
  YYSYMBOL_CASE = 132,                     /* CASE  */
  YYSYMBOL_EXTERN = 133,                   /* EXTERN  */
  YYSYMBOL_START = 134,                    /* START  */
  YYSYMBOL_VERS_TAG = 135,                 /* VERS_TAG  */
  YYSYMBOL_VERS_IDENTIFIER = 136,          /* VERS_IDENTIFIER  */
  YYSYMBOL_GLOBAL = 137,                   /* GLOBAL  */
  YYSYMBOL_LOCAL = 138,                    /* LOCAL  */
  YYSYMBOL_VERSIONK = 139,                 /* VERSIONK  */
  YYSYMBOL_INPUT_VERSION_SCRIPT = 140,     /* INPUT_VERSION_SCRIPT  */
  YYSYMBOL_KEEP = 141,                     /* KEEP  */
  YYSYMBOL_ONLY_IF_RO = 142,               /* ONLY_IF_RO  */
  YYSYMBOL_ONLY_IF_RW = 143,               /* ONLY_IF_RW  */
  YYSYMBOL_SPECIAL = 144,                  /* SPECIAL  */
  YYSYMBOL_INPUT_SECTION_FLAGS = 145,      /* INPUT_SECTION_FLAGS  */
  YYSYMBOL_ALIGN_WITH_INPUT = 146,         /* ALIGN_WITH_INPUT  */
  YYSYMBOL_EXCLUDE_FILE = 147,             /* EXCLUDE_FILE  */
  YYSYMBOL_CONSTANT = 148,                 /* CONSTANT  */
  YYSYMBOL_INPUT_DYNAMIC_LIST = 149,       /* INPUT_DYNAMIC_LIST  */
  YYSYMBOL_150_ = 150,                     /* ','  */
  YYSYMBOL_151_ = 151,                     /* ';'  */
  YYSYMBOL_152_ = 152,                     /* ')'  */
  YYSYMBOL_153_ = 153,                     /* '['  */
  YYSYMBOL_154_ = 154,                     /* ']'  */
  YYSYMBOL_155_ = 155,                     /* '!'  */
  YYSYMBOL_156_ = 156,                     /* '~'  */
  YYSYMBOL_YYACCEPT = 157,                 /* $accept  */
  YYSYMBOL_file = 158,                     /* file  */
  YYSYMBOL_filename = 159,                 /* filename  */
  YYSYMBOL_defsym_expr = 160,              /* defsym_expr  */
  YYSYMBOL_161_1 = 161,                    /* $@1  */
  YYSYMBOL_mri_script_file = 162,          /* mri_script_file  */
  YYSYMBOL_163_2 = 163,                    /* $@2  */
  YYSYMBOL_mri_script_lines = 164,         /* mri_script_lines  */
  YYSYMBOL_mri_script_command = 165,       /* mri_script_command  */
  YYSYMBOL_166_3 = 166,                    /* $@3  */
  YYSYMBOL_ordernamelist = 167,            /* ordernamelist  */
  YYSYMBOL_mri_load_name_list = 168,       /* mri_load_name_list  */
  YYSYMBOL_mri_abs_name_list = 169,        /* mri_abs_name_list  */
  YYSYMBOL_casesymlist = 170,              /* casesymlist  */
  YYSYMBOL_extern_name_list = 171,         /* extern_name_list  */
  YYSYMBOL_script_file = 172,              /* script_file  */
  YYSYMBOL_173_4 = 173,                    /* $@4  */
  YYSYMBOL_ifile_list = 174,               /* ifile_list  */
  YYSYMBOL_ifile_p1 = 175,                 /* ifile_p1  */
  YYSYMBOL_176_5 = 176,                    /* $@5  */
  YYSYMBOL_177_6 = 177,                    /* $@6  */
  YYSYMBOL_178_7 = 178,                    /* $@7  */
  YYSYMBOL_input_list = 179,               /* input_list  */
  YYSYMBOL_180_8 = 180,                    /* $@8  */
  YYSYMBOL_input_list1 = 181,              /* input_list1  */
  YYSYMBOL_182_9 = 182,                    /* @9  */
  YYSYMBOL_183_10 = 183,                   /* @10  */
  YYSYMBOL_184_11 = 184,                   /* @11  */
  YYSYMBOL_sections = 185,                 /* sections  */
  YYSYMBOL_sec_or_group_p1 = 186,          /* sec_or_group_p1  */
  YYSYMBOL_statement_anywhere = 187,       /* statement_anywhere  */
  YYSYMBOL_188_12 = 188,                   /* $@12  */
  YYSYMBOL_wildcard_name = 189,            /* wildcard_name  */
  YYSYMBOL_wildcard_maybe_exclude = 190,   /* wildcard_maybe_exclude  */
  YYSYMBOL_filename_spec = 191,            /* filename_spec  */
  YYSYMBOL_section_name_spec = 192,        /* section_name_spec  */
  YYSYMBOL_sect_flag_list = 193,           /* sect_flag_list  */
  YYSYMBOL_sect_flags = 194,               /* sect_flags  */
  YYSYMBOL_exclude_name_list = 195,        /* exclude_name_list  */
  YYSYMBOL_section_name_list = 196,        /* section_name_list  */
  YYSYMBOL_input_section_spec_no_keep = 197, /* input_section_spec_no_keep  */
  YYSYMBOL_input_section_spec = 198,       /* input_section_spec  */
  YYSYMBOL_199_13 = 199,                   /* $@13  */
  YYSYMBOL_statement = 200,                /* statement  */
  YYSYMBOL_201_14 = 201,                   /* $@14  */
  YYSYMBOL_202_15 = 202,                   /* $@15  */
  YYSYMBOL_statement_list = 203,           /* statement_list  */
  YYSYMBOL_statement_list_opt = 204,       /* statement_list_opt  */
  YYSYMBOL_length = 205,                   /* length  */
  YYSYMBOL_fill_exp = 206,                 /* fill_exp  */
  YYSYMBOL_fill_opt = 207,                 /* fill_opt  */
  YYSYMBOL_assign_op = 208,                /* assign_op  */
  YYSYMBOL_separator = 209,                /* separator  */
  YYSYMBOL_assignment = 210,               /* assignment  */
  YYSYMBOL_opt_comma = 211,                /* opt_comma  */
  YYSYMBOL_memory = 212,                   /* memory  */
  YYSYMBOL_memory_spec_list_opt = 213,     /* memory_spec_list_opt  */
  YYSYMBOL_memory_spec_list = 214,         /* memory_spec_list  */
  YYSYMBOL_memory_spec = 215,              /* memory_spec  */
  YYSYMBOL_216_16 = 216,                   /* $@16  */
  YYSYMBOL_217_17 = 217,                   /* $@17  */
  YYSYMBOL_origin_spec = 218,              /* origin_spec  */
  YYSYMBOL_length_spec = 219,              /* length_spec  */
  YYSYMBOL_attributes_opt = 220,           /* attributes_opt  */
  YYSYMBOL_attributes_list = 221,          /* attributes_list  */
  YYSYMBOL_attributes_string = 222,        /* attributes_string  */
  YYSYMBOL_startup = 223,                  /* startup  */
  YYSYMBOL_high_level_library = 224,       /* high_level_library  */
  YYSYMBOL_high_level_library_NAME_list = 225, /* high_level_library_NAME_list  */
  YYSYMBOL_low_level_library = 226,        /* low_level_library  */
  YYSYMBOL_low_level_library_NAME_list = 227, /* low_level_library_NAME_list  */
  YYSYMBOL_floating_point_support = 228,   /* floating_point_support  */
  YYSYMBOL_nocrossref_list = 229,          /* nocrossref_list  */
  YYSYMBOL_paren_script_name = 230,        /* paren_script_name  */
  YYSYMBOL_231_18 = 231,                   /* $@18  */
  YYSYMBOL_mustbe_exp = 232,               /* mustbe_exp  */
  YYSYMBOL_233_19 = 233,                   /* $@19  */
  YYSYMBOL_exp = 234,                      /* exp  */
  YYSYMBOL_235_20 = 235,                   /* $@20  */
  YYSYMBOL_236_21 = 236,                   /* $@21  */
  YYSYMBOL_memspec_at_opt = 237,           /* memspec_at_opt  */
  YYSYMBOL_opt_at = 238,                   /* opt_at  */
  YYSYMBOL_opt_align = 239,                /* opt_align  */
  YYSYMBOL_opt_align_with_input = 240,     /* opt_align_with_input  */
  YYSYMBOL_opt_subalign = 241,             /* opt_subalign  */
  YYSYMBOL_sect_constraint = 242,          /* sect_constraint  */
  YYSYMBOL_section = 243,                  /* section  */
  YYSYMBOL_244_22 = 244,                   /* $@22  */
  YYSYMBOL_245_23 = 245,                   /* $@23  */
  YYSYMBOL_246_24 = 246,                   /* $@24  */
  YYSYMBOL_247_25 = 247,                   /* $@25  */
  YYSYMBOL_248_26 = 248,                   /* $@26  */
  YYSYMBOL_249_27 = 249,                   /* $@27  */
  YYSYMBOL_250_28 = 250,                   /* $@28  */
  YYSYMBOL_251_29 = 251,                   /* $@29  */
  YYSYMBOL_252_30 = 252,                   /* $@30  */
  YYSYMBOL_253_31 = 253,                   /* $@31  */
  YYSYMBOL_254_32 = 254,                   /* $@32  */
  YYSYMBOL_type = 255,                     /* type  */
  YYSYMBOL_atype = 256,                    /* atype  */
  YYSYMBOL_opt_exp_with_type = 257,        /* opt_exp_with_type  */
  YYSYMBOL_opt_exp_without_type = 258,     /* opt_exp_without_type  */
  YYSYMBOL_opt_nocrossrefs = 259,          /* opt_nocrossrefs  */
  YYSYMBOL_memspec_opt = 260,              /* memspec_opt  */
  YYSYMBOL_phdr_opt = 261,                 /* phdr_opt  */
  YYSYMBOL_overlay_section = 262,          /* overlay_section  */
  YYSYMBOL_263_33 = 263,                   /* $@33  */
  YYSYMBOL_264_34 = 264,                   /* $@34  */
  YYSYMBOL_265_35 = 265,                   /* $@35  */
  YYSYMBOL_phdrs = 266,                    /* phdrs  */
  YYSYMBOL_phdr_list = 267,                /* phdr_list  */
  YYSYMBOL_phdr = 268,                     /* phdr  */
  YYSYMBOL_269_36 = 269,                   /* $@36  */
  YYSYMBOL_270_37 = 270,                   /* $@37  */
  YYSYMBOL_phdr_type = 271,                /* phdr_type  */
  YYSYMBOL_phdr_qualifiers = 272,          /* phdr_qualifiers  */
  YYSYMBOL_phdr_val = 273,                 /* phdr_val  */
  YYSYMBOL_dynamic_list_file = 274,        /* dynamic_list_file  */
  YYSYMBOL_275_38 = 275,                   /* $@38  */
  YYSYMBOL_dynamic_list_nodes = 276,       /* dynamic_list_nodes  */
  YYSYMBOL_dynamic_list_node = 277,        /* dynamic_list_node  */
  YYSYMBOL_dynamic_list_tag = 278,         /* dynamic_list_tag  */
  YYSYMBOL_version_script_file = 279,      /* version_script_file  */
  YYSYMBOL_280_39 = 280,                   /* $@39  */
  YYSYMBOL_version = 281,                  /* version  */
  YYSYMBOL_282_40 = 282,                   /* $@40  */
  YYSYMBOL_vers_nodes = 283,               /* vers_nodes  */
  YYSYMBOL_vers_node = 284,                /* vers_node  */
  YYSYMBOL_verdep = 285,                   /* verdep  */
  YYSYMBOL_vers_tag = 286,                 /* vers_tag  */
  YYSYMBOL_vers_defns = 287,               /* vers_defns  */
  YYSYMBOL_288_41 = 288,                   /* @41  */
  YYSYMBOL_289_42 = 289,                   /* @42  */
  YYSYMBOL_opt_semicolon = 290             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1968

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  157
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  376
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  802

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   388


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   155,     2,     2,     2,    34,    21,     2,
      37,   152,    32,    30,   150,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,   151,
      24,    10,    25,    15,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   153,     2,   154,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,    19,    59,   156,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    11,    12,    13,    14,    17,
      18,    22,    23,    26,    27,    28,    29,    35,    36,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   146,   146,   147,   148,   149,   150,   154,   158,   158,
     165,   165,   178,   179,   183,   184,   185,   188,   191,   192,
     193,   195,   197,   199,   201,   203,   205,   207,   209,   211,
     213,   215,   216,   217,   219,   221,   223,   225,   227,   228,
     230,   229,   232,   234,   238,   239,   240,   244,   246,   250,
     252,   257,   258,   259,   263,   265,   267,   272,   272,   278,
     279,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   296,   298,   300,   303,   305,   307,   309,   311,
     313,   315,   314,   318,   321,   320,   323,   327,   331,   331,
     333,   335,   337,   339,   344,   344,   349,   352,   355,   358,
     361,   364,   368,   367,   373,   372,   378,   377,   385,   389,
     390,   391,   395,   397,   398,   398,   404,   411,   418,   428,
     429,   434,   442,   443,   448,   453,   458,   463,   468,   473,
     478,   485,   503,   524,   537,   546,   557,   566,   577,   586,
     595,   599,   608,   612,   620,   622,   621,   628,   629,   630,
     634,   638,   643,   644,   649,   654,   653,   661,   660,   668,
     669,   672,   674,   678,   680,   682,   684,   686,   691,   698,
     700,   704,   706,   708,   710,   712,   714,   716,   718,   723,
     723,   728,   732,   740,   744,   748,   756,   756,   760,   763,
     763,   766,   767,   772,   771,   777,   776,   782,   789,   802,
     803,   807,   808,   812,   814,   819,   824,   825,   830,   832,
     837,   841,   843,   847,   849,   855,   858,   867,   878,   878,
     882,   882,   888,   890,   892,   894,   896,   898,   901,   903,
     905,   907,   909,   911,   913,   915,   917,   919,   921,   923,
     925,   927,   929,   931,   933,   935,   937,   939,   941,   943,
     946,   948,   950,   952,   954,   956,   958,   960,   962,   964,
     966,   968,   969,   968,   978,   980,   982,   984,   986,   988,
     990,   992,   998,   999,  1003,  1004,  1008,  1009,  1013,  1014,
    1018,  1019,  1023,  1024,  1025,  1026,  1030,  1037,  1047,  1049,
    1029,  1067,  1069,  1071,  1077,  1066,  1092,  1094,  1091,  1100,
    1099,  1107,  1108,  1109,  1110,  1111,  1112,  1116,  1117,  1118,
    1122,  1123,  1128,  1129,  1134,  1135,  1140,  1141,  1146,  1148,
    1153,  1156,  1169,  1173,  1180,  1182,  1171,  1194,  1197,  1199,
    1203,  1204,  1203,  1213,  1262,  1265,  1278,  1287,  1290,  1297,
    1297,  1309,  1310,  1314,  1318,  1327,  1327,  1341,  1341,  1351,
    1352,  1356,  1360,  1364,  1371,  1375,  1383,  1386,  1390,  1394,
    1398,  1405,  1409,  1413,  1417,  1422,  1421,  1435,  1434,  1444,
    1448,  1452,  1456,  1460,  1464,  1470,  1472
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT", "NAME", "LNAME",
  "PLUSEQ", "MINUSEQ", "MULTEQ", "DIVEQ", "'='", "LSHIFTEQ", "RSHIFTEQ",
  "ANDEQ", "OREQ", "'?'", "':'", "OROR", "ANDAND", "'|'", "'^'", "'&'",
  "EQ", "NE", "'<'", "'>'", "LE", "GE", "LSHIFT", "RSHIFT", "'+'", "'-'",
  "'*'", "'/'", "'%'", "UNARY", "END", "'('", "ALIGN_K", "BLOCK", "BIND",
  "QUAD", "SQUAD", "LONG", "SHORT", "BYTE", "SECTIONS", "PHDRS",
  "INSERT_K", "AFTER", "BEFORE", "DATA_SEGMENT_ALIGN",
  "DATA_SEGMENT_RELRO_END", "DATA_SEGMENT_END", "SORT_BY_NAME",
  "SORT_BY_ALIGNMENT", "SORT_NONE", "SORT_BY_INIT_PRIORITY", "'{'", "'}'",
  "SIZEOF_HEADERS", "OUTPUT_FORMAT", "FORCE_COMMON_ALLOCATION",
  "OUTPUT_ARCH", "INHIBIT_COMMON_ALLOCATION", "FORCE_GROUP_ALLOCATION",
  "SEGMENT_START", "INCLUDE", "MEMORY", "REGION_ALIAS", "LD_FEATURE",
  "NOLOAD", "DSECT", "COPY", "INFO", "OVERLAY", "READONLY", "DEFINED",
  "TARGET_K", "SEARCH_DIR", "MAP", "ENTRY", "NEXT", "SIZEOF", "ALIGNOF",
  "ADDR", "LOADADDR", "MAX_K", "MIN_K", "STARTUP", "HLL", "SYSLIB",
  "FLOAT", "NOFLOAT", "NOCROSSREFS", "NOCROSSREFS_TO", "ORIGIN", "FILL",
  "LENGTH", "CREATE_OBJECT_SYMBOLS", "INPUT", "GROUP", "OUTPUT",
  "CONSTRUCTORS", "ALIGNMOD", "AT", "SUBALIGN", "HIDDEN", "PROVIDE",
  "PROVIDE_HIDDEN", "AS_NEEDED", "CHIP", "LIST", "SECT", "ABSOLUTE",
  "LOAD", "NEWLINE", "ENDWORD", "ORDER", "NAMEWORD", "ASSERT_K",
  "LOG2CEIL", "FORMAT", "PUBLIC", "DEFSYMEND", "BASE", "ALIAS", "TRUNCATE",
  "REL", "INPUT_SCRIPT", "INPUT_MRI_SCRIPT", "INPUT_DEFSYM", "CASE",
  "EXTERN", "START", "VERS_TAG", "VERS_IDENTIFIER", "GLOBAL", "LOCAL",
  "VERSIONK", "INPUT_VERSION_SCRIPT", "KEEP", "ONLY_IF_RO", "ONLY_IF_RW",
  "SPECIAL", "INPUT_SECTION_FLAGS", "ALIGN_WITH_INPUT", "EXCLUDE_FILE",
  "CONSTANT", "INPUT_DYNAMIC_LIST", "','", "';'", "')'", "'['", "']'",
  "'!'", "'~'", "$accept", "file", "filename", "defsym_expr", "$@1",
  "mri_script_file", "$@2", "mri_script_lines", "mri_script_command",
  "$@3", "ordernamelist", "mri_load_name_list", "mri_abs_name_list",
  "casesymlist", "extern_name_list", "script_file", "$@4", "ifile_list",
  "ifile_p1", "$@5", "$@6", "$@7", "input_list", "$@8", "input_list1",
  "@9", "@10", "@11", "sections", "sec_or_group_p1", "statement_anywhere",
  "$@12", "wildcard_name", "wildcard_maybe_exclude", "filename_spec",
  "section_name_spec", "sect_flag_list", "sect_flags", "exclude_name_list",
  "section_name_list", "input_section_spec_no_keep", "input_section_spec",
  "$@13", "statement", "$@14", "$@15", "statement_list",
  "statement_list_opt", "length", "fill_exp", "fill_opt", "assign_op",
  "separator", "assignment", "opt_comma", "memory", "memory_spec_list_opt",
  "memory_spec_list", "memory_spec", "$@16", "$@17", "origin_spec",
  "length_spec", "attributes_opt", "attributes_list", "attributes_string",
  "startup", "high_level_library", "high_level_library_NAME_list",
  "low_level_library", "low_level_library_NAME_list",
  "floating_point_support", "nocrossref_list", "paren_script_name", "$@18",
  "mustbe_exp", "$@19", "exp", "$@20", "$@21", "memspec_at_opt", "opt_at",
  "opt_align", "opt_align_with_input", "opt_subalign", "sect_constraint",
  "section", "$@22", "$@23", "$@24", "$@25", "$@26", "$@27", "$@28",
  "$@29", "$@30", "$@31", "$@32", "type", "atype", "opt_exp_with_type",
  "opt_exp_without_type", "opt_nocrossrefs", "memspec_opt", "phdr_opt",
  "overlay_section", "$@33", "$@34", "$@35", "phdrs", "phdr_list", "phdr",
  "$@36", "$@37", "phdr_type", "phdr_qualifiers", "phdr_val",
  "dynamic_list_file", "$@38", "dynamic_list_nodes", "dynamic_list_node",
  "dynamic_list_tag", "version_script_file", "$@39", "version", "$@40",
  "vers_nodes", "vers_node", "verdep", "vers_tag", "vers_defns", "@41",
  "@42", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      61,   265,   266,   267,   268,    63,    58,   269,   270,   124,
      94,    38,   271,   272,    60,    62,   273,   274,   275,   276,
      43,    45,    42,    47,    37,   277,   278,    40,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   297,   298,   123,   125,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
      44,    59,    41,    91,    93,    33,   126
};
#endif

#define YYPACT_NINF (-708)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-348)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     174,  -708,  -708,  -708,  -708,  -708,    52,  -708,  -708,  -708,
    -708,  -708,    39,  -708,   -16,  -708,    20,  -708,   926,  1730,
     537,    86,    94,   113,  -708,   131,   201,   -16,  -708,   149,
      20,  -708,   207,   208,    78,   251,  -708,   265,  -708,  -708,
     309,   257,   279,   280,   281,   282,   284,   287,   288,   289,
     300,  -708,  -708,   303,   304,   305,  -708,   306,  -708,   316,
    -708,  -708,  -708,  -708,     1,  -708,  -708,  -708,  -708,  -708,
    -708,  -708,   200,  -708,   350,   309,   351,   780,  -708,   352,
     354,   358,  -708,  -708,   359,   360,   361,   780,   362,   367,
     369,   371,   373,   262,  -708,  -708,  -708,  -708,  -708,  -708,
    -708,  -708,  -708,  -708,   377,   380,   383,  -708,   384,  -708,
     381,   388,   330,   245,   131,  -708,  -708,  -708,   341,   258,
    -708,  -708,  -708,   406,   410,   415,   416,  -708,  -708,    42,
     422,   423,   425,   309,   309,   430,   309,     9,  -708,   431,
     431,  -708,   399,   309,   400,  -708,  -708,  -708,  -708,   382,
      45,  -708,    81,  -708,  -708,   780,   780,   780,   405,   418,
     419,   420,   421,  -708,  -708,   426,   427,  -708,  -708,  -708,
    -708,   428,   429,  -708,  -708,   433,   434,   435,   436,   780,
     780,  1536,   364,  -708,   293,  -708,   318,    34,  -708,  -708,
     522,  1907,   325,  -708,  -708,   326,  -708,    40,  -708,  -708,
    -708,   780,  -708,   449,   464,   469,   438,   149,   149,   329,
     275,   432,   335,   275,   324,    46,  -708,  -708,   -18,   336,
    -708,  -708,   309,   440,   -10,  -708,   331,   337,   345,   353,
     355,   356,   363,  -708,  -708,   108,   128,    41,   365,   366,
     372,    23,  -708,   376,   780,   371,   -16,   780,   780,  -708,
     780,   780,  -708,  -708,   890,   780,   780,   780,   780,   780,
     467,   512,   780,  -708,   484,  -708,  -708,  -708,   780,   780,
    -708,  -708,   780,   780,   780,   519,  -708,  -708,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
     780,   780,   780,   780,   780,   780,   780,   780,   780,   780,
    1907,   525,   526,  -708,   527,   780,   780,  1907,   229,   529,
    -708,   530,  1907,  -708,  -708,  -708,  -708,   385,   387,  -708,
    -708,   533,  -708,  -708,  -708,   -77,  -708,   537,  -708,   309,
    -708,  -708,  -708,  -708,  -708,  -708,  -708,   535,  -708,  -708,
     993,   503,  -708,  -708,  -708,    42,   550,  -708,  -708,  -708,
    -708,  -708,  -708,  -708,   309,  -708,   309,   431,  -708,  -708,
    -708,  -708,  -708,  -708,   504,    19,   403,  -708,  1556,    15,
     -22,  1907,  1907,  1754,  1907,  1907,  -708,   219,  1128,  1576,
    1596,  1148,   552,   412,  1168,   553,  1616,  1636,  1188,  1670,
    1208,   413,   936,  1751,  1108,   773,  1242,  1377,   687,   687,
     302,   302,   302,   302,   240,   240,    43,    43,  -708,  -708,
    -708,  1907,  1907,  1907,  -708,  -708,  -708,  1907,  1907,  -708,
    -708,  -708,  -708,   414,   417,   424,   149,   285,   275,   500,
    -708,  -708,   -69,   608,  -708,   694,   608,   780,   437,  -708,
       3,   546,    42,  -708,   448,  -708,  -708,  -708,  -708,  -708,
    -708,   531,    28,  -708,   563,  -708,  -708,  -708,   780,  -708,
    -708,   780,   780,  -708,  -708,  -708,  -708,   450,   780,   780,
    -708,   566,  -708,  -708,   780,  -708,  -708,  -708,   462,   555,
    -708,  -708,  -708,   224,   541,  1781,   565,   334,  -708,  -708,
    1879,   485,  -708,  1907,    25,   579,  -708,   580,     2,  -708,
     489,   578,  -708,    23,  -708,  -708,  -708,   549,   463,  1228,
    1264,  1284,   439,  -708,  1304,  1324,   465,  1907,   275,   542,
     149,   149,  -708,  -708,  -708,  -708,  -708,  -708,  -708,   471,
     780,   276,   600,  -708,   582,   586,   402,  -708,  -708,   334,
     567,   589,   591,  -708,   477,  -708,  -708,  -708,   620,   481,
    -708,    26,    23,  -708,  -708,  -708,  -708,  -708,   780,  -708,
    -708,  -708,  -708,   482,   462,  -708,  1344,  -708,   780,   595,
     488,  -708,   534,  -708,   780,    25,   780,   486,  -708,  -708,
     543,  -708,    35,    23,  1364,   275,   576,   100,  1400,   780,
    -708,   534,   607,  -708,   386,  1420,  -708,  1440,  -708,  -708,
     639,  -708,  -708,    49,  -708,  -708,   614,   636,  -708,  1460,
       0,   780,   596,  -708,  -708,    25,  -708,  -708,   780,  -708,
    -708,  -708,  -708,  -708,  -708,  1480,  -708,  -708,  -708,  1500,
     597,  -708,  -708,   616,   830,    58,   640,   584,  -708,  -708,
    -708,  -708,  -708,   621,   625,   309,   626,  -708,  -708,  -708,
     627,   628,   629,  -708,    30,  -708,  -708,   630,    13,  -708,
    -708,  -708,   830,   598,   632,     1,  -708,   646,  -708,     8,
      16,  -708,  -708,   638,  -708,   669,   672,  -708,   642,   643,
     644,   645,  -708,  -708,   -38,    30,   647,   649,    30,   650,
    -708,  -708,  -708,  -708,   631,   679,   594,   548,   551,   556,
     830,   571,  -708,   780,    17,  -708,   105,  -708,    21,    47,
      53,    16,    16,  -708,    30,   141,    16,   -32,    30,   646,
     574,   830,  -708,   676,  -708,  -708,  -708,  -708,   666,  -708,
    1690,   575,   583,   701,  -708,   672,  -708,   670,   693,   585,
     697,   699,   587,   588,   590,  -708,  -708,  -708,   142,   594,
    -708,   682,   734,    82,  -708,   739,  -708,  -708,  -708,    16,
      16,  -708,    16,    16,  -708,  -708,  -708,  -708,  -708,  -708,
    -708,  -708,   740,  -708,   599,   601,   603,   605,   606,    82,
    -708,  -708,  -708,   481,     1,   609,   610,   613,   615,  -708,
      82,  -708,  -708,  -708,  -708,  -708,  -708,   481,  -708,  -708,
     481,  -708
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,    57,    10,     8,   345,   339,     0,     2,    60,     3,
      13,     6,     0,     4,     0,     5,     0,     1,    58,    11,
       0,     0,     0,     0,     9,   356,     0,   346,   349,     0,
     340,   341,     0,     0,     0,     0,    77,     0,    79,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   213,   214,     0,     0,     0,    81,     0,   114,     0,
      70,    59,    62,    68,     0,    61,    64,    65,    66,    67,
      63,    69,     0,    16,     0,     0,     0,     0,    17,     0,
       0,     0,    19,    46,     0,     0,     0,     0,     0,     0,
      51,     0,     0,     0,   171,   172,   173,   174,   220,   175,
     176,   177,   178,   220,     0,     0,     0,   362,   373,   361,
     369,   371,     0,     0,   356,   350,   369,   371,     0,     0,
     342,   111,   328,     0,     0,     0,     0,     7,    84,   190,
       0,     0,     0,     0,     0,     0,     0,     0,   212,   215,
     215,    94,     0,     0,     0,    88,   180,   179,   113,     0,
       0,    40,     0,   248,   265,     0,     0,     0,     0,     0,
       0,     0,     0,   249,   261,     0,     0,   218,   218,   218,
     218,     0,     0,   218,   218,     0,     0,     0,     0,     0,
       0,    14,     0,    49,    31,    47,    32,    18,    33,    23,
       0,    36,     0,    37,    52,    38,    54,    39,    42,    12,
     181,     0,   182,     0,     0,     0,     0,     0,     0,     0,
     357,     0,     0,   344,     0,     0,    90,    91,     0,     0,
      60,   193,     0,     0,   187,   192,     0,     0,     0,     0,
       0,     0,     0,   207,   209,   187,   187,   215,     0,     0,
       0,     0,    94,     0,     0,     0,     0,     0,     0,    13,
       0,     0,   226,   222,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,   250,   252,   253,     0,     0,
     269,   270,     0,     0,     0,     0,   225,   227,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,    45,     0,     0,     0,    22,     0,     0,
      55,     0,   221,   220,   220,   220,   367,     0,     0,   351,
     364,   374,   363,   370,   372,     0,   343,   286,   108,     0,
     291,   296,   110,   109,   330,   327,   329,     0,    74,    76,
     347,   199,   195,   188,   186,     0,     0,    93,    71,    72,
      83,   112,   205,   206,     0,   210,     0,   215,   216,    86,
      87,    80,    96,    99,     0,    95,     0,    73,     0,     0,
       0,    27,    28,    43,    29,    30,   223,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   246,   245,   243,   242,   241,   235,   236,
     239,   240,   237,   238,   233,   234,   231,   232,   228,   229,
     230,    15,    26,    24,    50,    48,    44,    20,    21,    35,
      34,    53,    56,     0,     0,     0,     0,   358,   359,     0,
     354,   352,     0,   308,   299,     0,   308,     0,     0,    85,
       0,     0,   190,   191,     0,   208,   211,   217,   102,    98,
     101,     0,     0,    82,     0,    89,   348,    41,     0,   256,
     264,     0,     0,   260,   262,   247,   224,     0,     0,     0,
     255,     0,   271,   254,     0,   183,   184,   185,   375,   372,
     365,   355,   353,     0,     0,   308,     0,   275,   111,   315,
       0,   316,   297,   333,   334,     0,   203,     0,     0,   201,
       0,     0,    92,     0,   106,    97,   100,     0,     0,     0,
       0,     0,     0,   219,     0,     0,     0,   244,   376,     0,
       0,     0,   301,   302,   303,   304,   305,   306,   309,     0,
       0,     0,     0,   311,     0,   277,     0,   314,   317,   275,
       0,   337,     0,   331,     0,   204,   200,   202,     0,   187,
     196,     0,     0,   104,   115,   257,   258,   259,     0,   266,
     267,   268,   368,     0,   375,   307,     0,   310,     0,     0,
     279,   300,   281,   111,     0,   334,     0,     0,    75,   220,
       0,   103,     0,     0,     0,   360,     0,   308,     0,     0,
     278,   281,     0,   292,     0,     0,   335,     0,   332,   197,
       0,   194,   107,     0,   263,   366,     0,     0,   274,     0,
     285,     0,     0,   298,   338,   334,   220,   105,     0,   312,
     276,   282,   283,   284,   287,     0,   293,   336,   198,     0,
       0,   280,   322,   308,   161,     0,     0,   138,   163,   164,
     165,   166,   167,     0,     0,     0,     0,   149,   150,   155,
       0,     0,     0,   147,     0,   117,   119,     0,     0,   144,
     152,   160,   162,     0,     0,     0,   323,   319,   313,     0,
       0,   157,   220,     0,   145,     0,     0,   116,     0,     0,
       0,     0,   122,   137,   187,     0,   139,     0,     0,     0,
     159,   288,   220,   148,     0,     0,   273,     0,     0,     0,
     161,     0,   168,     0,     0,   131,     0,   135,     0,     0,
       0,     0,     0,   140,     0,   187,     0,   187,     0,   319,
       0,   161,   318,     0,   320,   151,   120,   121,     0,   154,
       0,   116,     0,     0,   133,     0,   134,     0,     0,     0,
       0,     0,     0,     0,     0,   136,   142,   141,   187,   273,
     153,     0,     0,   170,   158,     0,   146,   132,   118,     0,
       0,   123,     0,     0,   124,   125,   130,   143,   320,   324,
     272,   220,     0,   294,     0,     0,     0,     0,     0,   170,
     320,   169,   321,   187,     0,     0,     0,     0,     0,   289,
     170,   295,   156,   127,   126,   128,   129,   187,   325,   290,
     187,   326
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -708,  -708,   -73,  -708,  -708,  -708,  -708,   499,  -708,  -708,
    -708,  -708,  -708,  -708,   505,  -708,  -708,   532,  -708,  -708,
    -708,  -708,   507,  -708,  -462,  -708,  -708,  -708,  -708,  -453,
     -13,  -708,  -611,  1205,   101,    54,  -708,  -708,  -708,  -629,
      62,  -708,  -708,   107,  -708,  -708,  -708,  -653,  -708,    -1,
    -707,  -708,  -643,   -12,  -220,  -708,   332,  -708,   441,  -708,
    -708,  -708,  -708,  -708,  -708,   274,  -708,  -708,  -708,  -708,
    -708,  -708,  -122,   -74,  -708,   -89,  -708,   -76,  -708,  -708,
      24,   236,  -708,  -708,   194,  -708,  -708,  -708,  -708,  -708,
    -708,  -708,  -708,  -708,  -708,  -708,  -708,  -708,  -708,  -477,
     389,  -708,  -708,    68,  -687,  -708,  -708,  -708,  -708,  -708,
    -708,  -708,  -708,  -708,  -708,  -527,  -708,  -708,  -708,  -708,
     758,  -708,  -708,  -708,  -708,  -708,   545,   -24,  -708,   675,
     -19,  -708,  -708,   248
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     6,   128,    11,    12,     9,    10,    19,    93,   249,
     187,   186,   184,   195,   197,     7,     8,    18,    61,   142,
     220,   245,   240,   241,   365,   503,   583,   552,    62,   214,
     332,   144,   655,   656,   657,   683,   706,   658,   708,   684,
     659,   660,   704,   661,   673,   700,   662,   663,   664,   701,
     773,   103,   148,    64,   714,    65,   223,   224,   225,   341,
     442,   549,   601,   441,   498,   499,    66,    67,   235,    68,
     236,    69,   238,   263,   264,   702,   201,   254,   260,   512,
     724,   535,   570,   591,   593,   624,   333,   433,   630,   719,
     797,   435,   612,   632,   783,   436,   540,   488,   529,   486,
     487,   491,   539,   696,   753,   635,   694,   780,   800,    70,
     215,   336,   437,   577,   494,   543,   575,    15,    16,    30,
      31,   118,    13,    14,    71,    72,    27,    28,   432,   112,
     113,   521,   426,   519
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   181,   151,   115,   345,    63,   496,   496,   532,   200,
     119,   191,   677,   127,   202,   354,   356,   686,   239,   310,
     677,   731,   693,   449,   450,   677,  -189,   362,   363,   541,
     449,   450,   505,   506,   677,   536,    25,   456,   303,   449,
     450,   551,    25,    20,   310,   237,   221,   728,   596,  -189,
     334,   677,    17,   449,   450,   247,   715,   677,   430,   717,
     229,   230,   666,   232,   234,   707,   481,   687,   751,   644,
     243,   687,   789,   644,   431,   294,   295,   296,    29,   252,
     253,   779,   482,   798,   678,   679,   680,   681,   627,   748,
     582,   250,   771,   790,   265,   266,   267,   736,   772,   270,
     271,   737,   738,   276,   277,   335,   300,   740,   741,   222,
     607,   697,   344,    26,   307,   358,   713,   667,   344,    26,
     594,   603,   747,   104,   758,   312,   733,   123,   124,   451,
     542,   105,   337,   364,   338,   107,   451,   531,   507,   606,
     344,   792,   621,   622,   623,   451,    21,    22,    23,   342,
     106,   146,   147,   107,   546,   652,   636,   497,   497,   451,
     652,   233,   651,   652,   652,   311,   688,   455,   368,   452,
     654,   371,   372,   735,   374,   375,   452,   652,   581,   377,
     378,   379,   380,   381,   304,   452,   384,   602,   317,   318,
     311,   357,   386,   387,   652,   248,   388,   389,   390,   452,
     652,   617,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   423,   424,   425,   153,   154,   417,
     418,   251,   419,   420,   278,   447,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   155,   156,   434,   734,   344,   114,
     353,   157,   158,   159,   108,   121,   122,   109,   110,   111,
     292,   293,   294,   295,   296,   160,   161,   162,   344,   320,
     355,   445,   108,   446,   163,   109,   116,   117,   125,   320,
     164,   344,   344,   746,   767,   522,   523,   524,   525,   526,
     527,   165,   126,     1,     2,     3,   166,   167,   168,   169,
     170,   171,   172,   127,     4,   129,   130,   131,   132,   133,
     173,   134,   174,     5,   135,   136,   137,    63,   327,   580,
     290,   291,   292,   293,   294,   295,   296,   138,   175,   149,
     139,   140,   141,   143,   176,   177,   115,   522,   523,   524,
     525,   526,   527,   145,   150,   152,   182,   485,   183,   490,
     485,   493,   185,   188,   189,   190,   192,   153,   154,   458,
     193,   459,   178,   194,   298,   196,   528,   198,   199,   179,
     180,   203,   509,   328,   204,   510,   511,   205,   206,   209,
     327,   329,   514,   515,   155,   156,   210,   207,   517,   330,
     212,   157,   158,   159,   208,    47,   327,   478,   321,   213,
     216,   322,   323,   324,   217,   160,   161,   162,   321,   218,
     219,   322,   323,   479,   163,   331,   226,   227,   528,   228,
     164,    21,    22,    23,   231,   237,   242,   244,   571,   534,
     246,   165,   255,   301,    58,   613,   166,   167,   168,   169,
     170,   171,   172,   329,   566,   256,   257,   258,   259,   313,
     173,   330,   174,   261,   262,   268,   269,    47,   302,   329,
     272,   273,   274,   275,   314,   308,   309,   330,   175,   315,
     319,   346,   584,    47,   176,   177,   326,   331,   339,   347,
     599,   325,   588,    21,    22,    23,   316,   348,   595,   343,
     597,   563,   564,   331,   382,   349,    58,   350,   351,    21,
      22,    23,   178,   609,   299,   352,   383,   359,   360,   179,
     180,   385,    58,   391,   361,   153,   154,   628,   367,   414,
     415,   416,   305,   421,   422,   625,   427,   429,   428,   438,
     440,   448,   629,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   155,   156,   444,   453,   464,   467,   480,   157,
     158,   159,   500,   791,   465,   473,   475,   508,   504,   476,
     516,   520,   671,   160,   161,   162,   477,   799,   530,   538,
     801,   533,   163,   544,   545,   548,   553,   495,   164,   558,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   165,
     502,   562,   513,   720,   166,   167,   168,   169,   170,   171,
     172,   153,   154,   518,   550,   554,   567,   561,   173,   568,
     174,  -116,   665,   565,   569,   573,   574,   730,   576,   578,
     579,   344,   589,   585,   590,   605,   175,   598,   155,   156,
     592,   600,   176,   177,   611,   483,   158,   159,   484,   616,
     665,   618,   619,   531,   626,   634,   668,   691,   669,   160,
     161,   162,   670,   672,   674,   675,   676,   685,   163,   692,
     178,   695,   306,   705,   164,   703,   677,   179,   180,   709,
     710,   711,   712,   722,  -116,   165,   716,   718,   665,   721,
     166,   167,   168,   169,   170,   171,   172,   153,   154,   723,
     725,   752,   754,   726,   173,   757,   174,   759,   727,   665,
     489,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   175,   729,   155,   156,   750,  -138,   176,   177,
     760,   157,   158,   159,   762,   756,   763,   761,   770,   764,
     765,   769,   766,   774,   782,   160,   161,   162,   373,   366,
     369,   784,   340,   785,   163,   786,   178,   787,   788,   689,
     164,   793,   794,   179,   180,   795,   732,   796,   745,   690,
     781,   165,   547,   768,   501,   572,   166,   167,   168,   169,
     170,   171,   172,   153,   154,   610,   443,   749,   120,   211,
     173,   370,   174,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   175,     0,
     155,   156,   586,     0,   176,   177,     0,   157,   158,   159,
       0,     0,     0,     0,     0,   492,     0,     0,     0,     0,
       0,   160,   161,   162,   637,     0,     0,     0,     0,     0,
     163,     0,   178,     0,     0,     0,   164,     0,     0,   179,
     180,     0,     0,     0,     0,     0,     0,   165,     0,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,     0,
       0,   638,   639,   640,   641,   642,   173,     0,   174,     0,
       0,     0,     0,     0,   643,     0,   644,     0,     0,     0,
       0,     0,     0,     0,   175,     0,     0,   645,     0,     0,
     176,   177,     0,     0,     0,   278,     0,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,     0,     0,   646,   178,   647,
      20,     0,     0,   648,     0,   179,   180,    21,    22,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     649,   278,   474,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   650,    32,    33,    34,   651,     0,   652,     0,     0,
       0,   653,     0,   654,     0,     0,     0,    35,    36,    37,
      38,    39,     0,    40,    41,    42,    43,    20,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,     0,     0,
       0,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,     0,    55,    56,    57,   439,
       0,     0,     0,    21,    22,    23,     0,     0,     0,    32,
      33,    34,   376,     0,     0,     0,    58,     0,     0,     0,
       0,     0,     0,     0,    35,    36,    37,    38,    39,    59,
      40,    41,    42,    43,     0,  -347,     0,     0,     0,     0,
       0,    44,    45,    46,    47,     0,     0,    60,     0,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     0,    55,    56,    57,     0,     0,     0,     0,
      21,    22,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    59,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,    60,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,     0,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,     0,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,     0,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,     0,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   278,     0,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,     0,     0,   278,
     460,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   278,
     463,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   278,
     466,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   278,
     470,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   278,
     472,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   278,
     555,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,     0,     0,     0,   278,   556,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   557,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   559,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   560,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   587,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   604,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   278,   608,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   278,   614,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   278,   615,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   278,   620,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   278,   631,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   278,   633,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   278,   297,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   278,   454,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,     0,   461,     0,     0,     0,
       0,     0,     0,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,     0,   468,     0,    74,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,   469,     0,     0,     0,
     457,     0,    74,     0,     0,     0,   278,    75,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296,     0,     0,   531,     0,
     471,    75,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,     0,     0,     0,     0,     0,
     755,    77,    78,    79,    80,    81,   -43,    82,    83,    84,
       0,     0,    85,    86,     0,    87,    88,    89,    76,   682,
       0,     0,    90,    91,    92,    77,    78,    79,    80,    81,
       0,    82,    83,    84,   698,   699,    85,    86,     0,    87,
      88,    89,     0,     0,     0,     0,    90,    91,    92,     0,
     682,     0,     0,   682,   278,   537,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   288,   289,   290,   291,   292,
     293,   294,   295,   296,   739,   742,   743,   744,     0,   682,
       0,   698,   278,   682,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   775,   776,     0,   777,   778
};

static const yytype_int16 yycheck[] =
{
      12,    77,    75,    27,   224,    18,     4,     4,   485,    98,
      29,    87,     4,     4,   103,   235,   236,     4,   140,     4,
       4,     4,   665,     4,     5,     4,    36,     4,     5,     4,
       4,     5,     4,     5,     4,   488,    58,    59,     4,     4,
       5,   503,    58,     4,     4,     4,     4,   700,   575,    59,
       4,     4,     0,     4,     5,    10,   685,     4,   135,   688,
     133,   134,     4,   136,   137,   676,   135,    54,   721,    56,
     143,    54,   779,    56,   151,    32,    33,    34,    58,   155,
     156,   768,   151,   790,    54,    55,    56,    57,   615,   718,
     552,    10,    10,   780,   168,   169,   170,   708,    16,   173,
     174,    54,    55,   179,   180,    59,   182,    54,    55,    67,
     587,   103,   150,   135,   190,   237,   154,    59,   150,   135,
     573,   583,   154,    37,   735,   201,    21,    49,    50,   110,
     105,    37,   150,   110,   152,     4,   110,    37,   110,    39,
     150,   784,   142,   143,   144,   110,   107,   108,   109,   222,
      37,   150,   151,     4,   152,   147,   633,   155,   155,   110,
     147,   152,   145,   147,   147,   150,   153,   152,   244,   150,
     153,   247,   248,   152,   250,   251,   150,   147,   152,   255,
     256,   257,   258,   259,   150,   150,   262,   152,   207,   208,
     150,   150,   268,   269,   147,   150,   272,   273,   274,   150,
     147,   152,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   313,   314,   315,     3,     4,   305,
     306,   150,     3,     4,    15,   357,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    30,    31,   329,   152,   150,    58,
     152,    37,    38,    39,   133,    58,    58,   136,   137,   138,
      30,    31,    32,    33,    34,    51,    52,    53,   150,     4,
     152,   354,   133,   356,    60,   136,   137,   138,    37,     4,
      66,   150,   150,   152,   152,    71,    72,    73,    74,    75,
      76,    77,    37,   129,   130,   131,    82,    83,    84,    85,
      86,    87,    88,     4,   140,    58,    37,    37,    37,    37,
      96,    37,    98,   149,    37,    37,    37,   340,     4,   549,
      28,    29,    30,    31,    32,    33,    34,    37,   114,   139,
      37,    37,    37,    37,   120,   121,   370,    71,    72,    73,
      74,    75,    76,    37,     4,     4,     4,   433,     4,   435,
     436,   437,     4,     4,     4,     4,     4,     3,     4,   150,
       3,   152,   148,     4,    10,     4,   152,     4,   116,   155,
     156,     4,   458,    59,     4,   461,   462,     4,     4,    59,
       4,    67,   468,   469,    30,    31,   151,    16,   474,    75,
      59,    37,    38,    39,    16,    81,     4,   426,   133,   151,
       4,   136,   137,   138,     4,    51,    52,    53,   133,     4,
       4,   136,   137,   138,    60,   101,     4,     4,   152,     4,
      66,   107,   108,   109,     4,     4,    37,    37,    36,   105,
      58,    77,    37,   150,   120,    59,    82,    83,    84,    85,
      86,    87,    88,    67,   530,    37,    37,    37,    37,    10,
      96,    75,    98,    37,    37,    37,    37,    81,   150,    67,
      37,    37,    37,    37,    10,   150,   150,    75,   114,    10,
     151,   150,   558,    81,   120,   121,   151,   101,   152,   152,
     579,    59,   568,   107,   108,   109,    58,   152,   574,    59,
     576,   520,   521,   101,    37,   152,   120,   152,   152,   107,
     108,   109,   148,   589,   150,   152,     4,   152,   152,   155,
     156,    37,   120,     4,   152,     3,     4,   616,   152,     4,
       4,     4,    10,     4,     4,   611,   151,     4,   151,     4,
      37,    37,   618,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    30,    31,     4,   152,     4,     4,    58,    37,
      38,    39,    16,   783,   152,   152,   152,     4,    37,   152,
       4,    16,   645,    51,    52,    53,   152,   797,    37,    94,
     800,    16,    60,     4,     4,    96,    37,   150,    66,   150,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    77,
     152,    59,   152,   692,    82,    83,    84,    85,    86,    87,
      88,     3,     4,   151,    36,   152,    16,   152,    96,    37,
      98,    37,   634,   152,    38,    58,    37,   703,    37,   152,
      10,   150,    37,   151,   146,    59,   114,   151,    30,    31,
     106,    98,   120,   121,    37,    37,    38,    39,    40,    10,
     662,    37,    16,    37,    58,    58,    16,    59,    37,    51,
      52,    53,    37,    37,    37,    37,    37,    37,    60,    37,
     148,    25,   150,     4,    66,    37,     4,   155,   156,    37,
      37,    37,    37,     4,    37,    77,    37,    37,   700,    58,
      82,    83,    84,    85,    86,    87,    88,     3,     4,   105,
     152,    25,    36,   152,    96,     4,    98,    37,   152,   721,
      16,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,   114,   152,    30,    31,   152,   152,   120,   121,
      37,    37,    38,    39,    37,   152,    37,   152,     4,   152,
     152,    59,   152,     4,     4,    51,    52,    53,   249,   242,
     245,   152,   220,   152,    60,   152,   148,   152,   152,   658,
      66,   152,   152,   155,   156,   152,   704,   152,   714,   662,
     771,    77,   498,   749,   442,   539,    82,    83,    84,    85,
      86,    87,    88,     3,     4,   591,   345,   719,    30,   114,
      96,   246,    98,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,   114,    -1,
      30,    31,   564,    -1,   120,   121,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,   436,    -1,    -1,    -1,    -1,
      -1,    51,    52,    53,     4,    -1,    -1,    -1,    -1,    -1,
      60,    -1,   148,    -1,    -1,    -1,    66,    -1,    -1,   155,
     156,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    82,    83,    84,    85,    86,    87,    88,    -1,
      -1,    41,    42,    43,    44,    45,    96,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,    -1,    -1,    67,    -1,    -1,
     120,   121,    -1,    -1,    -1,    15,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    97,   148,    99,
       4,    -1,    -1,   103,    -1,   155,   156,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,   141,    46,    47,    48,   145,    -1,   147,    -1,    -1,
      -1,   151,    -1,   153,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    -1,    67,    68,    69,    70,     4,    -1,    -1,
      -1,    -1,    -1,    -1,    78,    79,    80,    81,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    95,    -1,    -1,    -1,    -1,   100,   101,   102,    36,
      -1,    -1,    -1,   107,   108,   109,    -1,    -1,    -1,    46,
      47,    48,   152,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,   133,
      67,    68,    69,    70,    -1,   139,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    89,    90,    91,    92,    93,    94,    95,    -1,
      -1,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,    -1,
     107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   133,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,   151,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    15,    -1,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    15,
     152,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   152,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    15,   152,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,   150,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    15,   150,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   150,    -1,    38,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,   150,    -1,    -1,    -1,
      36,    -1,    38,    -1,    -1,    -1,    15,    67,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    37,    -1,
     150,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   104,    -1,    -1,    -1,    -1,    -1,
     150,   111,   112,   113,   114,   115,   116,   117,   118,   119,
      -1,    -1,   122,   123,    -1,   125,   126,   127,   104,   654,
      -1,    -1,   132,   133,   134,   111,   112,   113,   114,   115,
      -1,   117,   118,   119,   669,   670,   122,   123,    -1,   125,
     126,   127,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,
     685,    -1,    -1,   688,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,   709,   710,   711,   712,    -1,   714,
      -1,   716,    15,   718,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   759,   760,    -1,   762,   763
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   129,   130,   131,   140,   149,   158,   172,   173,   162,
     163,   160,   161,   279,   280,   274,   275,     0,   174,   164,
       4,   107,   108,   109,   210,    58,   135,   283,   284,    58,
     276,   277,    46,    47,    48,    61,    62,    63,    64,    65,
      67,    68,    69,    70,    78,    79,    80,    81,    89,    90,
      91,    92,    93,    94,    95,   100,   101,   102,   120,   133,
     151,   175,   185,   187,   210,   212,   223,   224,   226,   228,
     266,   281,   282,     4,    38,    67,   104,   111,   112,   113,
     114,   115,   117,   118,   119,   122,   123,   125,   126,   127,
     132,   133,   134,   165,     6,     7,     8,     9,    10,    11,
      12,    13,    14,   208,    37,    37,    37,     4,   133,   136,
     137,   138,   286,   287,    58,   284,   137,   138,   278,   287,
     277,    58,    58,    49,    50,    37,    37,     4,   159,    58,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,   176,    37,   188,    37,   150,   151,   209,   139,
       4,   159,     4,     3,     4,    30,    31,    37,    38,    39,
      51,    52,    53,    60,    66,    77,    82,    83,    84,    85,
      86,    87,    88,    96,    98,   114,   120,   121,   148,   155,
     156,   234,     4,     4,   169,     4,   168,   167,     4,     4,
       4,   234,     4,     3,     4,   170,     4,   171,     4,   116,
     232,   233,   232,     4,     4,     4,     4,    16,    16,    59,
     151,   286,    59,   151,   186,   267,     4,     4,     4,     4,
     177,     4,    67,   213,   214,   215,     4,     4,     4,   159,
     159,     4,   159,   152,   159,   225,   227,     4,   229,   229,
     179,   180,    37,   159,    37,   178,    58,    10,   150,   166,
      10,   150,   234,   234,   234,    37,    37,    37,    37,    37,
     235,    37,    37,   230,   231,   230,   230,   230,    37,    37,
     230,   230,    37,    37,    37,    37,   234,   234,    15,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,   150,    10,   150,
     234,   150,   150,     4,   150,    10,   150,   234,   150,   150,
       4,   150,   234,    10,    10,    10,    58,   287,   287,   151,
       4,   133,   136,   137,   138,    59,   151,     4,    59,    67,
      75,   101,   187,   243,     4,    59,   268,   150,   152,   152,
     174,   216,   159,    59,   150,   211,   150,   152,   152,   152,
     152,   152,   152,   152,   211,   152,   211,   150,   229,   152,
     152,   152,     4,     5,   110,   181,   179,   152,   234,   171,
     283,   234,   234,   164,   234,   234,   152,   234,   234,   234,
     234,   234,    37,     4,   234,    37,   234,   234,   234,   234,
     234,     4,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,     4,     4,     4,   234,   234,     3,
       4,     4,     4,   232,   232,   232,   289,   151,   151,     4,
     135,   151,   285,   244,   159,   248,   252,   269,     4,    36,
      37,   220,   217,   215,     4,   159,   159,   229,    37,     4,
       5,   110,   150,   152,   150,   152,    59,    36,   150,   152,
     152,   150,   150,   152,     4,   152,   152,     4,   150,   150,
     152,   150,   152,   152,    16,   152,   152,   152,   287,   138,
      58,   135,   151,    37,    40,   234,   256,   257,   254,    16,
     234,   258,   257,   234,   271,   150,     4,   155,   221,   222,
      16,   213,   152,   182,    37,     4,     5,   110,     4,   234,
     234,   234,   236,   152,   234,   234,     4,   234,   151,   290,
      16,   288,    71,    72,    73,    74,    75,    76,   152,   255,
      37,    37,   256,    16,   105,   238,   186,    16,    94,   259,
     253,     4,   105,   272,     4,     4,   152,   222,    96,   218,
      36,   181,   184,    37,   152,   152,   152,   152,   150,   152,
     152,   152,    59,   287,   287,   152,   234,    16,    37,    38,
     239,    36,   238,    58,    37,   273,    37,   270,   152,    10,
     211,   152,   181,   183,   234,   151,   290,   152,   234,    37,
     146,   240,   106,   241,   186,   234,   272,   234,   151,   232,
      98,   219,   152,   181,   152,    59,    39,   256,   152,   234,
     241,    37,   249,    59,   152,   152,    10,   152,    37,    16,
     152,   142,   143,   144,   242,   234,    58,   272,   232,   234,
     245,   152,   250,   152,    58,   262,   256,     4,    41,    42,
      43,    44,    45,    54,    56,    67,    97,    99,   103,   120,
     141,   145,   147,   151,   153,   189,   190,   191,   194,   197,
     198,   200,   203,   204,   205,   210,     4,    59,    16,    37,
      37,   159,    37,   201,    37,    37,    37,     4,    54,    55,
      56,    57,   190,   192,   196,    37,     4,    54,   153,   191,
     200,    59,    37,   209,   263,    25,   260,   103,   190,   190,
     202,   206,   232,    37,   199,     4,   193,   189,   195,    37,
      37,    37,    37,   154,   211,   196,    37,   196,    37,   246,
     232,    58,     4,   105,   237,   152,   152,   152,   204,   152,
     234,     4,   197,    21,   152,   152,   189,    54,    55,   190,
      54,    55,   190,   190,   190,   192,   152,   154,   196,   260,
     152,   204,    25,   261,    36,   150,   152,     4,   189,    37,
      37,   152,    37,    37,   152,   152,   152,   152,   237,    59,
       4,    10,    16,   207,     4,   190,   190,   190,   190,   261,
     264,   206,     4,   251,   152,   152,   152,   152,   152,   207,
     261,   211,   209,   152,   152,   152,   152,   247,   207,   211,
     265,   211
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   157,   158,   158,   158,   158,   158,   159,   161,   160,
     163,   162,   164,   164,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     166,   165,   165,   165,   167,   167,   167,   168,   168,   169,
     169,   170,   170,   170,   171,   171,   171,   173,   172,   174,
     174,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   175,   175,
     175,   176,   175,   175,   177,   175,   175,   175,   178,   175,
     175,   175,   175,   175,   180,   179,   181,   181,   181,   181,
     181,   181,   182,   181,   183,   181,   184,   181,   185,   186,
     186,   186,   187,   187,   188,   187,   189,   190,   190,   191,
     191,   191,   192,   192,   192,   192,   192,   192,   192,   192,
     192,   193,   193,   194,   195,   195,   196,   196,   197,   197,
     197,   197,   197,   197,   198,   199,   198,   200,   200,   200,
     200,   200,   200,   200,   200,   201,   200,   202,   200,   203,
     203,   204,   204,   205,   205,   205,   205,   205,   206,   207,
     207,   208,   208,   208,   208,   208,   208,   208,   208,   209,
     209,   210,   210,   210,   210,   210,   211,   211,   212,   213,
     213,   214,   214,   216,   215,   217,   215,   218,   219,   220,
     220,   221,   221,   222,   222,   223,   224,   224,   225,   225,
     226,   227,   227,   228,   228,   229,   229,   229,   231,   230,
     233,   232,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   235,   236,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   237,   237,   238,   238,   239,   239,   240,   240,
     241,   241,   242,   242,   242,   242,   244,   245,   246,   247,
     243,   248,   249,   250,   251,   243,   252,   253,   243,   254,
     243,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     257,   257,   257,   257,   258,   258,   259,   259,   260,   260,
     261,   261,   262,   263,   264,   265,   262,   266,   267,   267,
     269,   270,   268,   271,   272,   272,   272,   273,   273,   275,
     274,   276,   276,   277,   278,   280,   279,   282,   281,   283,
     283,   284,   284,   284,   285,   285,   286,   286,   286,   286,
     286,   287,   287,   287,   287,   288,   287,   289,   287,   287,
     287,   287,   287,   287,   287,   290,   290
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     2,     2,     1,     0,     2,
       0,     2,     3,     0,     2,     4,     1,     1,     2,     1,
       4,     4,     3,     2,     4,     3,     4,     4,     4,     4,
       4,     2,     2,     2,     4,     4,     2,     2,     2,     2,
       0,     5,     2,     0,     3,     2,     0,     1,     3,     1,
       3,     0,     1,     3,     1,     2,     3,     0,     2,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     8,     4,     1,     1,     1,
       4,     0,     5,     4,     0,     5,     4,     4,     0,     5,
       3,     3,     6,     4,     0,     2,     1,     3,     2,     1,
       3,     2,     0,     5,     0,     7,     0,     6,     4,     2,
       2,     0,     4,     2,     0,     7,     1,     1,     5,     1,
       4,     4,     1,     4,     4,     4,     7,     7,     7,     7,
       4,     1,     3,     4,     2,     1,     3,     1,     1,     2,
       3,     4,     4,     5,     1,     0,     5,     1,     2,     1,
       1,     4,     1,     4,     4,     0,     8,     0,     5,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     6,     6,     6,     1,     0,     4,     1,
       0,     3,     1,     0,     7,     0,     5,     3,     3,     0,
       3,     1,     2,     1,     2,     4,     4,     3,     3,     1,
       4,     3,     0,     1,     1,     0,     2,     3,     0,     4,
       0,     2,     2,     3,     4,     2,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     3,     3,     4,     1,     1,
       2,     2,     2,     2,     4,     4,     4,     6,     6,     6,
       4,     0,     0,     8,     4,     1,     6,     6,     6,     2,
       2,     4,     3,     0,     4,     0,     4,     0,     1,     0,
       4,     0,     1,     1,     1,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    17,     0,     0,     7,     0,
       5,     1,     1,     1,     1,     1,     1,     3,     0,     2,
       3,     2,     6,    10,     2,     1,     0,     1,     2,     0,
       0,     3,     0,     0,     0,     0,    11,     4,     0,     2,
       0,     0,     6,     1,     0,     3,     5,     0,     3,     0,
       2,     1,     2,     4,     2,     0,     2,     0,     5,     1,
       2,     4,     5,     6,     1,     2,     0,     2,     4,     4,
       8,     1,     1,     3,     3,     0,     9,     0,     7,     1,
       3,     1,     3,     1,     3,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* $@1: %empty  */
#line 158 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_expression(); }
#line 2567 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 9: /* defsym_expr: $@1 assignment  */
#line 160 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_popstate(); }
#line 2573 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 10: /* $@2: %empty  */
#line 165 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_mri_script ();
		  PUSH_ERROR (_("MRI style script"));
		}
#line 2582 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 11: /* mri_script_file: $@2 mri_script_lines  */
#line 170 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_popstate ();
		  mri_draw_tree ();
		  POP_ERROR ();
		}
#line 2592 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 16: /* mri_script_command: NAME  */
#line 185 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			einfo(_("%F%P: unrecognised keyword in MRI style script '%s'\n"),(yyvsp[0].name));
			}
#line 2600 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 17: /* mri_script_command: LIST  */
#line 188 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			config.map_filename = "-";
			}
#line 2608 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 20: /* mri_script_command: PUBLIC NAME '=' exp  */
#line 194 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_public((yyvsp[-2].name), (yyvsp[0].etree)); }
#line 2614 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 21: /* mri_script_command: PUBLIC NAME ',' exp  */
#line 196 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_public((yyvsp[-2].name), (yyvsp[0].etree)); }
#line 2620 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 22: /* mri_script_command: PUBLIC NAME exp  */
#line 198 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_public((yyvsp[-1].name), (yyvsp[0].etree)); }
#line 2626 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 23: /* mri_script_command: FORMAT NAME  */
#line 200 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_format((yyvsp[0].name)); }
#line 2632 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 24: /* mri_script_command: SECT NAME ',' exp  */
#line 202 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_output_section((yyvsp[-2].name), (yyvsp[0].etree));}
#line 2638 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 25: /* mri_script_command: SECT NAME exp  */
#line 204 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_output_section((yyvsp[-1].name), (yyvsp[0].etree));}
#line 2644 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 26: /* mri_script_command: SECT NAME '=' exp  */
#line 206 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_output_section((yyvsp[-2].name), (yyvsp[0].etree));}
#line 2650 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 27: /* mri_script_command: ALIGN_K NAME '=' exp  */
#line 208 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_align((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2656 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 28: /* mri_script_command: ALIGN_K NAME ',' exp  */
#line 210 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_align((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2662 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 29: /* mri_script_command: ALIGNMOD NAME '=' exp  */
#line 212 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_alignmod((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2668 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 30: /* mri_script_command: ALIGNMOD NAME ',' exp  */
#line 214 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_alignmod((yyvsp[-2].name),(yyvsp[0].etree)); }
#line 2674 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 33: /* mri_script_command: NAMEWORD NAME  */
#line 218 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_name((yyvsp[0].name)); }
#line 2680 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 34: /* mri_script_command: ALIAS NAME ',' NAME  */
#line 220 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_alias((yyvsp[-2].name),(yyvsp[0].name),0);}
#line 2686 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 35: /* mri_script_command: ALIAS NAME ',' INT  */
#line 222 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_alias ((yyvsp[-2].name), 0, (int) (yyvsp[0].bigint).integer); }
#line 2692 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 36: /* mri_script_command: BASE exp  */
#line 224 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_base((yyvsp[0].etree)); }
#line 2698 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 37: /* mri_script_command: TRUNCATE INT  */
#line 226 "../../Scpel-0.0.7/ld/ldgram.y"
                { mri_truncate ((unsigned int) (yyvsp[0].bigint).integer); }
#line 2704 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 40: /* $@3: %empty  */
#line 230 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldfile_open_command_file ((yyvsp[0].name)); }
#line 2710 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 42: /* mri_script_command: START NAME  */
#line 233 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_entry ((yyvsp[0].name), false); }
#line 2716 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 44: /* ordernamelist: ordernamelist ',' NAME  */
#line 238 "../../Scpel-0.0.7/ld/ldgram.y"
                                             { mri_order((yyvsp[0].name)); }
#line 2722 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 45: /* ordernamelist: ordernamelist NAME  */
#line 239 "../../Scpel-0.0.7/ld/ldgram.y"
                                          { mri_order((yyvsp[0].name)); }
#line 2728 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 47: /* mri_load_name_list: NAME  */
#line 245 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_load((yyvsp[0].name)); }
#line 2734 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 48: /* mri_load_name_list: mri_load_name_list ',' NAME  */
#line 246 "../../Scpel-0.0.7/ld/ldgram.y"
                                            { mri_load((yyvsp[0].name)); }
#line 2740 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 49: /* mri_abs_name_list: NAME  */
#line 251 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_only_load((yyvsp[0].name)); }
#line 2746 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 50: /* mri_abs_name_list: mri_abs_name_list ',' NAME  */
#line 253 "../../Scpel-0.0.7/ld/ldgram.y"
                        { mri_only_load((yyvsp[0].name)); }
#line 2752 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 51: /* casesymlist: %empty  */
#line 257 "../../Scpel-0.0.7/ld/ldgram.y"
                      { (yyval.name) = NULL; }
#line 2758 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 54: /* extern_name_list: NAME  */
#line 264 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlang_add_undef ((yyvsp[0].name), false); }
#line 2764 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 55: /* extern_name_list: extern_name_list NAME  */
#line 266 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlang_add_undef ((yyvsp[0].name), false); }
#line 2770 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 56: /* extern_name_list: extern_name_list ',' NAME  */
#line 268 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlang_add_undef ((yyvsp[0].name), false); }
#line 2776 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 57: /* $@4: %empty  */
#line 272 "../../Scpel-0.0.7/ld/ldgram.y"
        { ldlex_script (); }
#line 2782 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 58: /* script_file: $@4 ifile_list  */
#line 274 "../../Scpel-0.0.7/ld/ldgram.y"
        { ldlex_popstate (); }
#line 2788 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 71: /* ifile_p1: TARGET_K '(' NAME ')'  */
#line 295 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_target((yyvsp[-1].name)); }
#line 2794 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 72: /* ifile_p1: SEARCH_DIR '(' filename ')'  */
#line 297 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldfile_add_library_path ((yyvsp[-1].name), false); }
#line 2800 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 73: /* ifile_p1: OUTPUT '(' filename ')'  */
#line 299 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_output((yyvsp[-1].name), 1); }
#line 2806 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 74: /* ifile_p1: OUTPUT_FORMAT '(' NAME ')'  */
#line 301 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_add_output_format ((yyvsp[-1].name), (char *) NULL,
					    (char *) NULL, 1); }
#line 2813 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 75: /* ifile_p1: OUTPUT_FORMAT '(' NAME ',' NAME ',' NAME ')'  */
#line 304 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_add_output_format ((yyvsp[-5].name), (yyvsp[-3].name), (yyvsp[-1].name), 1); }
#line 2819 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 76: /* ifile_p1: OUTPUT_ARCH '(' NAME ')'  */
#line 306 "../../Scpel-0.0.7/ld/ldgram.y"
                  { ldfile_set_output_arch ((yyvsp[-1].name), bfd_arch_unknown); }
#line 2825 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 77: /* ifile_p1: FORCE_COMMON_ALLOCATION  */
#line 308 "../../Scpel-0.0.7/ld/ldgram.y"
                { command_line.force_common_definition = true ; }
#line 2831 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 78: /* ifile_p1: FORCE_GROUP_ALLOCATION  */
#line 310 "../../Scpel-0.0.7/ld/ldgram.y"
                { command_line.force_group_allocation = true ; }
#line 2837 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 79: /* ifile_p1: INHIBIT_COMMON_ALLOCATION  */
#line 312 "../../Scpel-0.0.7/ld/ldgram.y"
                { link_info.inhibit_common_definition = true ; }
#line 2843 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 81: /* $@5: %empty  */
#line 315 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_enter_group (); }
#line 2849 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 82: /* ifile_p1: GROUP $@5 '(' input_list ')'  */
#line 317 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_leave_group (); }
#line 2855 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 83: /* ifile_p1: MAP '(' filename ')'  */
#line 319 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_map((yyvsp[-1].name)); }
#line 2861 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 84: /* $@6: %empty  */
#line 321 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldfile_open_command_file ((yyvsp[0].name)); }
#line 2867 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 86: /* ifile_p1: NOCROSSREFS '(' nocrossref_list ')'  */
#line 324 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_nocrossref ((yyvsp[-1].nocrossref));
		}
#line 2875 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 87: /* ifile_p1: NOCROSSREFS_TO '(' nocrossref_list ')'  */
#line 328 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_nocrossref_to ((yyvsp[-1].nocrossref));
		}
#line 2883 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 88: /* $@7: %empty  */
#line 331 "../../Scpel-0.0.7/ld/ldgram.y"
                           { ldlex_expression (); }
#line 2889 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 89: /* ifile_p1: EXTERN '(' $@7 extern_name_list ')'  */
#line 332 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); }
#line 2895 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 90: /* ifile_p1: INSERT_K AFTER NAME  */
#line 334 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_insert ((yyvsp[0].name), 0); }
#line 2901 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 91: /* ifile_p1: INSERT_K BEFORE NAME  */
#line 336 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_insert ((yyvsp[0].name), 1); }
#line 2907 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 92: /* ifile_p1: REGION_ALIAS '(' NAME ',' NAME ')'  */
#line 338 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_memory_region_alias ((yyvsp[-3].name), (yyvsp[-1].name)); }
#line 2913 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 93: /* ifile_p1: LD_FEATURE '(' NAME ')'  */
#line 340 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_ld_feature ((yyvsp[-1].name)); }
#line 2919 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 94: /* $@8: %empty  */
#line 344 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_inputlist(); }
#line 2925 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 95: /* input_list: $@8 input_list1  */
#line 346 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_popstate(); }
#line 2931 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 96: /* input_list1: NAME  */
#line 350 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2938 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 97: /* input_list1: input_list1 ',' NAME  */
#line 353 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2945 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 98: /* input_list1: input_list1 NAME  */
#line 356 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_search_file_enum,
				 (char *)NULL); }
#line 2952 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 99: /* input_list1: LNAME  */
#line 359 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2959 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 100: /* input_list1: input_list1 ',' LNAME  */
#line 362 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2966 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 101: /* input_list1: input_list1 LNAME  */
#line 365 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_input_file((yyvsp[0].name),lang_input_file_is_l_enum,
				 (char *)NULL); }
#line 2973 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 102: /* @9: %empty  */
#line 368 "../../Scpel-0.0.7/ld/ldgram.y"
                  { (yyval.integer) = input_flags.add_DT_NEEDED_for_regular;
		    input_flags.add_DT_NEEDED_for_regular = true; }
#line 2980 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 103: /* input_list1: AS_NEEDED '(' @9 input_list1 ')'  */
#line 371 "../../Scpel-0.0.7/ld/ldgram.y"
                  { input_flags.add_DT_NEEDED_for_regular = (yyvsp[-2].integer); }
#line 2986 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 104: /* @10: %empty  */
#line 373 "../../Scpel-0.0.7/ld/ldgram.y"
                  { (yyval.integer) = input_flags.add_DT_NEEDED_for_regular;
		    input_flags.add_DT_NEEDED_for_regular = true; }
#line 2993 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 105: /* input_list1: input_list1 ',' AS_NEEDED '(' @10 input_list1 ')'  */
#line 376 "../../Scpel-0.0.7/ld/ldgram.y"
                  { input_flags.add_DT_NEEDED_for_regular = (yyvsp[-2].integer); }
#line 2999 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 106: /* @11: %empty  */
#line 378 "../../Scpel-0.0.7/ld/ldgram.y"
                  { (yyval.integer) = input_flags.add_DT_NEEDED_for_regular;
		    input_flags.add_DT_NEEDED_for_regular = true; }
#line 3006 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 107: /* input_list1: input_list1 AS_NEEDED '(' @11 input_list1 ')'  */
#line 381 "../../Scpel-0.0.7/ld/ldgram.y"
                  { input_flags.add_DT_NEEDED_for_regular = (yyvsp[-2].integer); }
#line 3012 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 112: /* statement_anywhere: ENTRY '(' NAME ')'  */
#line 396 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_add_entry ((yyvsp[-1].name), false); }
#line 3018 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 114: /* $@12: %empty  */
#line 398 "../../Scpel-0.0.7/ld/ldgram.y"
                          {ldlex_expression ();}
#line 3024 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 115: /* statement_anywhere: ASSERT_K $@12 '(' exp ',' NAME ')'  */
#line 399 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_popstate ();
		  lang_add_assignment (exp_assert ((yyvsp[-3].etree), (yyvsp[-1].name))); }
#line 3031 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 116: /* wildcard_name: NAME  */
#line 405 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.cname) = (yyvsp[0].name);
			}
#line 3039 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 117: /* wildcard_maybe_exclude: wildcard_name  */
#line 412 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard).name = (yyvsp[0].cname);
			  (yyval.wildcard).sorted = none;
			  (yyval.wildcard).exclude_name_list = NULL;
			  (yyval.wildcard).section_flag_list = NULL;
			}
#line 3050 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 118: /* wildcard_maybe_exclude: EXCLUDE_FILE '(' exclude_name_list ')' wildcard_name  */
#line 419 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard).name = (yyvsp[0].cname);
			  (yyval.wildcard).sorted = none;
			  (yyval.wildcard).exclude_name_list = (yyvsp[-2].name_list);
			  (yyval.wildcard).section_flag_list = NULL;
			}
#line 3061 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 120: /* filename_spec: SORT_BY_NAME '(' wildcard_maybe_exclude ')'  */
#line 430 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_name;
			}
#line 3070 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 121: /* filename_spec: SORT_NONE '(' wildcard_maybe_exclude ')'  */
#line 435 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_none;
			}
#line 3079 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 123: /* section_name_spec: SORT_BY_NAME '(' wildcard_maybe_exclude ')'  */
#line 444 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_name;
			}
#line 3088 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 124: /* section_name_spec: SORT_BY_ALIGNMENT '(' wildcard_maybe_exclude ')'  */
#line 449 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_alignment;
			}
#line 3097 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 125: /* section_name_spec: SORT_NONE '(' wildcard_maybe_exclude ')'  */
#line 454 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_none;
			}
#line 3106 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 126: /* section_name_spec: SORT_BY_NAME '(' SORT_BY_ALIGNMENT '(' wildcard_maybe_exclude ')' ')'  */
#line 459 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-2].wildcard);
			  (yyval.wildcard).sorted = by_name_alignment;
			}
#line 3115 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 127: /* section_name_spec: SORT_BY_NAME '(' SORT_BY_NAME '(' wildcard_maybe_exclude ')' ')'  */
#line 464 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-2].wildcard);
			  (yyval.wildcard).sorted = by_name;
			}
#line 3124 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 128: /* section_name_spec: SORT_BY_ALIGNMENT '(' SORT_BY_NAME '(' wildcard_maybe_exclude ')' ')'  */
#line 469 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-2].wildcard);
			  (yyval.wildcard).sorted = by_alignment_name;
			}
#line 3133 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 129: /* section_name_spec: SORT_BY_ALIGNMENT '(' SORT_BY_ALIGNMENT '(' wildcard_maybe_exclude ')' ')'  */
#line 474 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-2].wildcard);
			  (yyval.wildcard).sorted = by_alignment;
			}
#line 3142 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 130: /* section_name_spec: SORT_BY_INIT_PRIORITY '(' wildcard_maybe_exclude ')'  */
#line 479 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.wildcard) = (yyvsp[-1].wildcard);
			  (yyval.wildcard).sorted = by_init_priority;
			}
#line 3151 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 131: /* sect_flag_list: NAME  */
#line 486 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct flag_info_list *n;
			  n = ((struct flag_info_list *) xmalloc (sizeof *n));
			  if ((yyvsp[0].name)[0] == '!')
			    {
			      n->with = without_flags;
			      n->name = &(yyvsp[0].name)[1];
			    }
			  else
			    {
			      n->with = with_flags;
			      n->name = (yyvsp[0].name);
			    }
			  n->valid = false;
			  n->next = NULL;
			  (yyval.flag_info_list) = n;
			}
#line 3173 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 132: /* sect_flag_list: sect_flag_list '&' NAME  */
#line 504 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct flag_info_list *n;
			  n = ((struct flag_info_list *) xmalloc (sizeof *n));
			  if ((yyvsp[0].name)[0] == '!')
			    {
			      n->with = without_flags;
			      n->name = &(yyvsp[0].name)[1];
			    }
			  else
			    {
			      n->with = with_flags;
			      n->name = (yyvsp[0].name);
			    }
			  n->valid = false;
			  n->next = (yyvsp[-2].flag_info_list);
			  (yyval.flag_info_list) = n;
			}
#line 3195 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 133: /* sect_flags: INPUT_SECTION_FLAGS '(' sect_flag_list ')'  */
#line 525 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct flag_info *n;
			  n = ((struct flag_info *) xmalloc (sizeof *n));
			  n->flag_list = (yyvsp[-1].flag_info_list);
			  n->flags_initialized = false;
			  n->not_with_flags = 0;
			  n->only_with_flags = 0;
			  (yyval.flag_info) = n;
			}
#line 3209 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 134: /* exclude_name_list: exclude_name_list wildcard_name  */
#line 538 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct name_list *tmp;
			  tmp = (struct name_list *) xmalloc (sizeof *tmp);
			  tmp->name = (yyvsp[0].cname);
			  tmp->next = (yyvsp[-1].name_list);
			  (yyval.name_list) = tmp;
			}
#line 3221 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 135: /* exclude_name_list: wildcard_name  */
#line 547 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct name_list *tmp;
			  tmp = (struct name_list *) xmalloc (sizeof *tmp);
			  tmp->name = (yyvsp[0].cname);
			  tmp->next = NULL;
			  (yyval.name_list) = tmp;
			}
#line 3233 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 136: /* section_name_list: section_name_list opt_comma section_name_spec  */
#line 558 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct wildcard_list *tmp;
			  tmp = (struct wildcard_list *) xmalloc (sizeof *tmp);
			  tmp->next = (yyvsp[-2].wildcard_list);
			  tmp->spec = (yyvsp[0].wildcard);
			  (yyval.wildcard_list) = tmp;
			}
#line 3245 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 137: /* section_name_list: section_name_spec  */
#line 567 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct wildcard_list *tmp;
			  tmp = (struct wildcard_list *) xmalloc (sizeof *tmp);
			  tmp->next = NULL;
			  tmp->spec = (yyvsp[0].wildcard);
			  (yyval.wildcard_list) = tmp;
			}
#line 3257 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 138: /* input_section_spec_no_keep: NAME  */
#line 578 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct wildcard_spec tmp;
			  tmp.name = (yyvsp[0].name);
			  tmp.exclude_name_list = NULL;
			  tmp.sorted = none;
			  tmp.section_flag_list = NULL;
			  lang_add_wild (&tmp, NULL, ldgram_had_keep);
			}
#line 3270 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 139: /* input_section_spec_no_keep: sect_flags NAME  */
#line 587 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct wildcard_spec tmp;
			  tmp.name = (yyvsp[0].name);
			  tmp.exclude_name_list = NULL;
			  tmp.sorted = none;
			  tmp.section_flag_list = (yyvsp[-1].flag_info);
			  lang_add_wild (&tmp, NULL, ldgram_had_keep);
			}
#line 3283 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 140: /* input_section_spec_no_keep: '[' section_name_list ']'  */
#line 596 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  lang_add_wild (NULL, (yyvsp[-1].wildcard_list), ldgram_had_keep);
			}
#line 3291 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 141: /* input_section_spec_no_keep: sect_flags '[' section_name_list ']'  */
#line 600 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct wildcard_spec tmp;
			  tmp.name = NULL;
			  tmp.exclude_name_list = NULL;
			  tmp.sorted = none;
			  tmp.section_flag_list = (yyvsp[-3].flag_info);
			  lang_add_wild (&tmp, (yyvsp[-1].wildcard_list), ldgram_had_keep);
			}
#line 3304 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 142: /* input_section_spec_no_keep: filename_spec '(' section_name_list ')'  */
#line 609 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  lang_add_wild (&(yyvsp[-3].wildcard), (yyvsp[-1].wildcard_list), ldgram_had_keep);
			}
#line 3312 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 143: /* input_section_spec_no_keep: sect_flags filename_spec '(' section_name_list ')'  */
#line 613 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyvsp[-3].wildcard).section_flag_list = (yyvsp[-4].flag_info);
			  lang_add_wild (&(yyvsp[-3].wildcard), (yyvsp[-1].wildcard_list), ldgram_had_keep);
			}
#line 3321 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 145: /* $@13: %empty  */
#line 622 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldgram_had_keep = true; }
#line 3327 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 146: /* input_section_spec: KEEP '(' $@13 input_section_spec_no_keep ')'  */
#line 624 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldgram_had_keep = false; }
#line 3333 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 149: /* statement: CREATE_OBJECT_SYMBOLS  */
#line 631 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_attribute (lang_object_symbols_statement_enum);
		}
#line 3341 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 150: /* statement: CONSTRUCTORS  */
#line 635 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_attribute (lang_constructors_statement_enum);
		}
#line 3349 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 151: /* statement: SORT_BY_NAME '(' CONSTRUCTORS ')'  */
#line 639 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  constructors_sorted = true;
		  lang_add_attribute (lang_constructors_statement_enum);
		}
#line 3358 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 153: /* statement: length '(' mustbe_exp ')'  */
#line 645 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_data ((int) (yyvsp[-3].integer), (yyvsp[-1].etree));
		}
#line 3366 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 154: /* statement: FILL '(' fill_exp ')'  */
#line 650 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_fill ((yyvsp[-1].fill));
		}
#line 3374 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 155: /* $@14: %empty  */
#line 654 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldlex_expression (); }
#line 3380 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 156: /* statement: ASSERT_K $@14 '(' exp ',' NAME ')' separator  */
#line 656 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_popstate ();
		  lang_add_assignment (exp_assert ((yyvsp[-4].etree), (yyvsp[-2].name)));
		}
#line 3389 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 157: /* $@15: %empty  */
#line 661 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldfile_open_command_file ((yyvsp[0].name));
		}
#line 3397 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 163: /* length: QUAD  */
#line 679 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = (yyvsp[0].token); }
#line 3403 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 164: /* length: SQUAD  */
#line 681 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = (yyvsp[0].token); }
#line 3409 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 165: /* length: LONG  */
#line 683 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = (yyvsp[0].token); }
#line 3415 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 166: /* length: SHORT  */
#line 685 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = (yyvsp[0].token); }
#line 3421 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 167: /* length: BYTE  */
#line 687 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = (yyvsp[0].token); }
#line 3427 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 168: /* fill_exp: mustbe_exp  */
#line 692 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.fill) = exp_get_fill ((yyvsp[0].etree), 0, "fill value");
		}
#line 3435 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 169: /* fill_opt: '=' fill_exp  */
#line 699 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.fill) = (yyvsp[0].fill); }
#line 3441 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 170: /* fill_opt: %empty  */
#line 700 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.fill) = (fill_type *) 0; }
#line 3447 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 171: /* assign_op: PLUSEQ  */
#line 705 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '+'; }
#line 3453 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 172: /* assign_op: MINUSEQ  */
#line 707 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '-'; }
#line 3459 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 173: /* assign_op: MULTEQ  */
#line 709 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '*'; }
#line 3465 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 174: /* assign_op: DIVEQ  */
#line 711 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '/'; }
#line 3471 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 175: /* assign_op: LSHIFTEQ  */
#line 713 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = LSHIFT; }
#line 3477 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 176: /* assign_op: RSHIFTEQ  */
#line 715 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = RSHIFT; }
#line 3483 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 177: /* assign_op: ANDEQ  */
#line 717 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '&'; }
#line 3489 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 178: /* assign_op: OREQ  */
#line 719 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = '|'; }
#line 3495 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 181: /* assignment: NAME '=' mustbe_exp  */
#line 729 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_assignment (exp_assign ((yyvsp[-2].name), (yyvsp[0].etree), false));
		}
#line 3503 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 182: /* assignment: NAME assign_op mustbe_exp  */
#line 733 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_assignment (exp_assign ((yyvsp[-2].name),
						   exp_binop ((yyvsp[-1].token),
							      exp_nameop (NAME,
									  (yyvsp[-2].name)),
							      (yyvsp[0].etree)), false));
		}
#line 3515 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 183: /* assignment: HIDDEN '(' NAME '=' mustbe_exp ')'  */
#line 741 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_assignment (exp_assign ((yyvsp[-3].name), (yyvsp[-1].etree), true));
		}
#line 3523 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 184: /* assignment: PROVIDE '(' NAME '=' mustbe_exp ')'  */
#line 745 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_assignment (exp_provide ((yyvsp[-3].name), (yyvsp[-1].etree), false));
		}
#line 3531 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 185: /* assignment: PROVIDE_HIDDEN '(' NAME '=' mustbe_exp ')'  */
#line 749 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_add_assignment (exp_provide ((yyvsp[-3].name), (yyvsp[-1].etree), true));
		}
#line 3539 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 193: /* $@16: %empty  */
#line 772 "../../Scpel-0.0.7/ld/ldgram.y"
                { region = lang_memory_region_lookup ((yyvsp[0].name), true); }
#line 3545 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 194: /* memory_spec: NAME $@16 attributes_opt ':' origin_spec opt_comma length_spec  */
#line 775 "../../Scpel-0.0.7/ld/ldgram.y"
                {}
#line 3551 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 195: /* $@17: %empty  */
#line 777 "../../Scpel-0.0.7/ld/ldgram.y"
                { ldfile_open_command_file ((yyvsp[0].name)); }
#line 3557 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 197: /* origin_spec: ORIGIN '=' mustbe_exp  */
#line 783 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  region->origin_exp = (yyvsp[0].etree);
		}
#line 3565 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 198: /* length_spec: LENGTH '=' mustbe_exp  */
#line 790 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  if (yychar == NAME)
		    {
		      yyclearin;
		      ldlex_backup ();
		    }
		  region->length_exp = (yyvsp[0].etree);
		}
#line 3578 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 199: /* attributes_opt: %empty  */
#line 802 "../../Scpel-0.0.7/ld/ldgram.y"
                  { /* dummy action to avoid bison 1.25 error message */ }
#line 3584 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 203: /* attributes_string: NAME  */
#line 813 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_set_flags (region, (yyvsp[0].name), 0); }
#line 3590 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 204: /* attributes_string: '!' NAME  */
#line 815 "../../Scpel-0.0.7/ld/ldgram.y"
                  { lang_set_flags (region, (yyvsp[0].name), 1); }
#line 3596 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 205: /* startup: STARTUP '(' filename ')'  */
#line 820 "../../Scpel-0.0.7/ld/ldgram.y"
                { lang_startup((yyvsp[-1].name)); }
#line 3602 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 207: /* high_level_library: HLL '(' ')'  */
#line 826 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldemul_hll((char *)NULL); }
#line 3608 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 208: /* high_level_library_NAME_list: high_level_library_NAME_list opt_comma filename  */
#line 831 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldemul_hll((yyvsp[0].name)); }
#line 3614 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 209: /* high_level_library_NAME_list: filename  */
#line 833 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldemul_hll((yyvsp[0].name)); }
#line 3620 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 211: /* low_level_library_NAME_list: low_level_library_NAME_list opt_comma filename  */
#line 842 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldemul_syslib((yyvsp[0].name)); }
#line 3626 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 213: /* floating_point_support: FLOAT  */
#line 848 "../../Scpel-0.0.7/ld/ldgram.y"
                        { lang_float(true); }
#line 3632 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 214: /* floating_point_support: NOFLOAT  */
#line 850 "../../Scpel-0.0.7/ld/ldgram.y"
                        { lang_float(false); }
#line 3638 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 215: /* nocrossref_list: %empty  */
#line 855 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.nocrossref) = NULL;
		}
#line 3646 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 216: /* nocrossref_list: NAME nocrossref_list  */
#line 859 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  struct lang_nocrossref *n;

		  n = (struct lang_nocrossref *) xmalloc (sizeof *n);
		  n->name = (yyvsp[-1].name);
		  n->next = (yyvsp[0].nocrossref);
		  (yyval.nocrossref) = n;
		}
#line 3659 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 217: /* nocrossref_list: NAME ',' nocrossref_list  */
#line 868 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  struct lang_nocrossref *n;

		  n = (struct lang_nocrossref *) xmalloc (sizeof *n);
		  n->name = (yyvsp[-2].name);
		  n->next = (yyvsp[0].nocrossref);
		  (yyval.nocrossref) = n;
		}
#line 3672 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 218: /* $@18: %empty  */
#line 878 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_script (); }
#line 3678 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 219: /* paren_script_name: $@18 '(' NAME ')'  */
#line 880 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); (yyval.name) = (yyvsp[-1].name); }
#line 3684 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 220: /* $@19: %empty  */
#line 882 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_expression (); }
#line 3690 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 221: /* mustbe_exp: $@19 exp  */
#line 884 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); (yyval.etree) = (yyvsp[0].etree); }
#line 3696 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 222: /* exp: '-' exp  */
#line 889 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop ('-', (yyvsp[0].etree)); }
#line 3702 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 223: /* exp: '(' exp ')'  */
#line 891 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = (yyvsp[-1].etree); }
#line 3708 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 224: /* exp: NEXT '(' exp ')'  */
#line 893 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop ((int) (yyvsp[-3].integer),(yyvsp[-1].etree)); }
#line 3714 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 225: /* exp: '!' exp  */
#line 895 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop ('!', (yyvsp[0].etree)); }
#line 3720 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 226: /* exp: '+' exp  */
#line 897 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = (yyvsp[0].etree); }
#line 3726 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 227: /* exp: '~' exp  */
#line 899 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop ('~', (yyvsp[0].etree));}
#line 3732 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 228: /* exp: exp '*' exp  */
#line 902 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('*', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3738 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 229: /* exp: exp '/' exp  */
#line 904 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('/', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3744 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 230: /* exp: exp '%' exp  */
#line 906 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('%', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3750 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 231: /* exp: exp '+' exp  */
#line 908 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('+', (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3756 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 232: /* exp: exp '-' exp  */
#line 910 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('-' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3762 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 233: /* exp: exp LSHIFT exp  */
#line 912 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (LSHIFT , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3768 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 234: /* exp: exp RSHIFT exp  */
#line 914 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (RSHIFT , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3774 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 235: /* exp: exp EQ exp  */
#line 916 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (EQ , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3780 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 236: /* exp: exp NE exp  */
#line 918 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (NE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3786 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 237: /* exp: exp LE exp  */
#line 920 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (LE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3792 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 238: /* exp: exp GE exp  */
#line 922 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (GE , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3798 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 239: /* exp: exp '<' exp  */
#line 924 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('<' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3804 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 240: /* exp: exp '>' exp  */
#line 926 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('>' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3810 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 241: /* exp: exp '&' exp  */
#line 928 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('&' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3816 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 242: /* exp: exp '^' exp  */
#line 930 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('^' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3822 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 243: /* exp: exp '|' exp  */
#line 932 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop ('|' , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3828 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 244: /* exp: exp '?' exp ':' exp  */
#line 934 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_trinop ('?' , (yyvsp[-4].etree), (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3834 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 245: /* exp: exp ANDAND exp  */
#line 936 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (ANDAND , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3840 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 246: /* exp: exp OROR exp  */
#line 938 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (OROR , (yyvsp[-2].etree), (yyvsp[0].etree)); }
#line 3846 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 247: /* exp: DEFINED '(' NAME ')'  */
#line 940 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (DEFINED, (yyvsp[-1].name)); }
#line 3852 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 248: /* exp: INT  */
#line 942 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_bigintop ((yyvsp[0].bigint).integer, (yyvsp[0].bigint).str); }
#line 3858 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 249: /* exp: SIZEOF_HEADERS  */
#line 944 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (SIZEOF_HEADERS,0); }
#line 3864 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 250: /* exp: ALIGNOF paren_script_name  */
#line 947 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (ALIGNOF, (yyvsp[0].name)); }
#line 3870 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 251: /* exp: SIZEOF paren_script_name  */
#line 949 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (SIZEOF, (yyvsp[0].name)); }
#line 3876 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 252: /* exp: ADDR paren_script_name  */
#line 951 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (ADDR, (yyvsp[0].name)); }
#line 3882 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 253: /* exp: LOADADDR paren_script_name  */
#line 953 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (LOADADDR, (yyvsp[0].name)); }
#line 3888 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 254: /* exp: CONSTANT '(' NAME ')'  */
#line 955 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (CONSTANT,(yyvsp[-1].name)); }
#line 3894 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 255: /* exp: ABSOLUTE '(' exp ')'  */
#line 957 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop (ABSOLUTE, (yyvsp[-1].etree)); }
#line 3900 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 256: /* exp: ALIGN_K '(' exp ')'  */
#line 959 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop (ALIGN_K,(yyvsp[-1].etree)); }
#line 3906 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 257: /* exp: ALIGN_K '(' exp ',' exp ')'  */
#line 961 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (ALIGN_K,(yyvsp[-3].etree),(yyvsp[-1].etree)); }
#line 3912 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 258: /* exp: DATA_SEGMENT_ALIGN '(' exp ',' exp ')'  */
#line 963 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (DATA_SEGMENT_ALIGN, (yyvsp[-3].etree), (yyvsp[-1].etree)); }
#line 3918 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 259: /* exp: DATA_SEGMENT_RELRO_END '(' exp ',' exp ')'  */
#line 965 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (DATA_SEGMENT_RELRO_END, (yyvsp[-1].etree), (yyvsp[-3].etree)); }
#line 3924 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 260: /* exp: DATA_SEGMENT_END '(' exp ')'  */
#line 967 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop (DATA_SEGMENT_END, (yyvsp[-1].etree)); }
#line 3930 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 261: /* $@20: %empty  */
#line 968 "../../Scpel-0.0.7/ld/ldgram.y"
                              { ldlex_script (); }
#line 3936 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 262: /* $@21: %empty  */
#line 969 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); }
#line 3942 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 263: /* exp: SEGMENT_START $@20 '(' NAME $@21 ',' exp ')'  */
#line 970 "../../Scpel-0.0.7/ld/ldgram.y"
                        { /* The operands to the expression node are
			     placed in the opposite order from the way
			     in which they appear in the script as
			     that allows us to reuse more code in
			     fold_binary.  */
			  (yyval.etree) = exp_binop (SEGMENT_START,
					  (yyvsp[-1].etree),
					  exp_nameop (NAME, (yyvsp[-4].name))); }
#line 3955 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 264: /* exp: BLOCK '(' exp ')'  */
#line 979 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop (ALIGN_K,(yyvsp[-1].etree)); }
#line 3961 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 265: /* exp: NAME  */
#line 981 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (NAME,(yyvsp[0].name)); }
#line 3967 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 266: /* exp: MAX_K '(' exp ',' exp ')'  */
#line 983 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (MAX_K, (yyvsp[-3].etree), (yyvsp[-1].etree) ); }
#line 3973 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 267: /* exp: MIN_K '(' exp ',' exp ')'  */
#line 985 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_binop (MIN_K, (yyvsp[-3].etree), (yyvsp[-1].etree) ); }
#line 3979 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 268: /* exp: ASSERT_K '(' exp ',' NAME ')'  */
#line 987 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_assert ((yyvsp[-3].etree), (yyvsp[-1].name)); }
#line 3985 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 269: /* exp: ORIGIN paren_script_name  */
#line 989 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (ORIGIN, (yyvsp[0].name)); }
#line 3991 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 270: /* exp: LENGTH paren_script_name  */
#line 991 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_nameop (LENGTH, (yyvsp[0].name)); }
#line 3997 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 271: /* exp: LOG2CEIL '(' exp ')'  */
#line 993 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.etree) = exp_unop (LOG2CEIL, (yyvsp[-1].etree)); }
#line 4003 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 272: /* memspec_at_opt: AT '>' NAME  */
#line 998 "../../Scpel-0.0.7/ld/ldgram.y"
                            { (yyval.name) = (yyvsp[0].name); }
#line 4009 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 273: /* memspec_at_opt: %empty  */
#line 999 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.name) = 0; }
#line 4015 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 274: /* opt_at: AT '(' exp ')'  */
#line 1003 "../../Scpel-0.0.7/ld/ldgram.y"
                               { (yyval.etree) = (yyvsp[-1].etree); }
#line 4021 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 275: /* opt_at: %empty  */
#line 1004 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.etree) = 0; }
#line 4027 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 276: /* opt_align: ALIGN_K '(' exp ')'  */
#line 1008 "../../Scpel-0.0.7/ld/ldgram.y"
                                    { (yyval.etree) = (yyvsp[-1].etree); }
#line 4033 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 277: /* opt_align: %empty  */
#line 1009 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.etree) = 0; }
#line 4039 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 278: /* opt_align_with_input: ALIGN_WITH_INPUT  */
#line 1013 "../../Scpel-0.0.7/ld/ldgram.y"
                                 { (yyval.token) = ALIGN_WITH_INPUT; }
#line 4045 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 279: /* opt_align_with_input: %empty  */
#line 1014 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.token) = 0; }
#line 4051 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 280: /* opt_subalign: SUBALIGN '(' exp ')'  */
#line 1018 "../../Scpel-0.0.7/ld/ldgram.y"
                                     { (yyval.etree) = (yyvsp[-1].etree); }
#line 4057 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 281: /* opt_subalign: %empty  */
#line 1019 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.etree) = 0; }
#line 4063 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 282: /* sect_constraint: ONLY_IF_RO  */
#line 1023 "../../Scpel-0.0.7/ld/ldgram.y"
                           { (yyval.token) = ONLY_IF_RO; }
#line 4069 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 283: /* sect_constraint: ONLY_IF_RW  */
#line 1024 "../../Scpel-0.0.7/ld/ldgram.y"
                           { (yyval.token) = ONLY_IF_RW; }
#line 4075 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 284: /* sect_constraint: SPECIAL  */
#line 1025 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.token) = SPECIAL; }
#line 4081 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 285: /* sect_constraint: %empty  */
#line 1026 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.token) = 0; }
#line 4087 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 286: /* $@22: %empty  */
#line 1030 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_expression(); }
#line 4093 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 287: /* $@23: %empty  */
#line 1037 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  ldlex_popstate ();
			  ldlex_wild ();
			  lang_enter_output_section_statement((yyvsp[-7].name), (yyvsp[-5].etree), sectype,
							      (yyvsp[-3].etree), (yyvsp[-1].etree), (yyvsp[-4].etree),
							      (yyvsp[0].token), (yyvsp[-2].token));
			}
#line 4105 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 288: /* $@24: %empty  */
#line 1047 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); }
#line 4111 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 289: /* $@25: %empty  */
#line 1049 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  /* fill_opt may have switched the lexer into
			     expression state, and back again, but in
			     order to find the end of the fill
			     expression the parser must look ahead one
			     token.  If it is a NAME, throw it away as
			     it will have been lexed in the wrong
			     state.  */
			  if (yychar == NAME)
			    {
			      yyclearin;
			      ldlex_backup ();
			    }
			  lang_leave_output_section_statement ((yyvsp[0].fill), (yyvsp[-3].name),
							       (yyvsp[-1].section_phdr), (yyvsp[-2].name));
			}
#line 4132 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 291: /* $@26: %empty  */
#line 1067 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_expression (); }
#line 4138 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 292: /* $@27: %empty  */
#line 1069 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); }
#line 4144 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 293: /* $@28: %empty  */
#line 1071 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  lang_enter_overlay ((yyvsp[-5].etree), (yyvsp[-2].etree));
			}
#line 4152 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 294: /* $@29: %empty  */
#line 1077 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  if (yychar == NAME)
			    {
			      yyclearin;
			      ldlex_backup ();
			    }
			  lang_leave_overlay ((yyvsp[-10].etree), (int) (yyvsp[-11].integer),
					      (yyvsp[0].fill), (yyvsp[-3].name), (yyvsp[-1].section_phdr), (yyvsp[-2].name));
			}
#line 4166 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 296: /* $@30: %empty  */
#line 1092 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_expression (); }
#line 4172 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 297: /* $@31: %empty  */
#line 1094 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  ldlex_popstate ();
			  lang_add_assignment (exp_assign (".", (yyvsp[0].etree), false));
			}
#line 4181 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 299: /* $@32: %empty  */
#line 1100 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  ldfile_open_command_file ((yyvsp[0].name));
			}
#line 4189 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 301: /* type: NOLOAD  */
#line 1107 "../../Scpel-0.0.7/ld/ldgram.y"
                   { sectype = noload_section; }
#line 4195 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 302: /* type: DSECT  */
#line 1108 "../../Scpel-0.0.7/ld/ldgram.y"
                   { sectype = noalloc_section; }
#line 4201 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 303: /* type: COPY  */
#line 1109 "../../Scpel-0.0.7/ld/ldgram.y"
                   { sectype = noalloc_section; }
#line 4207 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 304: /* type: INFO  */
#line 1110 "../../Scpel-0.0.7/ld/ldgram.y"
                   { sectype = noalloc_section; }
#line 4213 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 305: /* type: OVERLAY  */
#line 1111 "../../Scpel-0.0.7/ld/ldgram.y"
                   { sectype = noalloc_section; }
#line 4219 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 306: /* type: READONLY  */
#line 1112 "../../Scpel-0.0.7/ld/ldgram.y"
                    { sectype = readonly_section; }
#line 4225 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 308: /* atype: %empty  */
#line 1117 "../../Scpel-0.0.7/ld/ldgram.y"
                            { sectype = normal_section; }
#line 4231 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 309: /* atype: '(' ')'  */
#line 1118 "../../Scpel-0.0.7/ld/ldgram.y"
                        { sectype = normal_section; }
#line 4237 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 310: /* opt_exp_with_type: exp atype ':'  */
#line 1122 "../../Scpel-0.0.7/ld/ldgram.y"
                                        { (yyval.etree) = (yyvsp[-2].etree); }
#line 4243 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 311: /* opt_exp_with_type: atype ':'  */
#line 1123 "../../Scpel-0.0.7/ld/ldgram.y"
                                        { (yyval.etree) = (etree_type *)NULL;  }
#line 4249 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 312: /* opt_exp_with_type: BIND '(' exp ')' atype ':'  */
#line 1128 "../../Scpel-0.0.7/ld/ldgram.y"
                                           { (yyval.etree) = (yyvsp[-3].etree); }
#line 4255 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 313: /* opt_exp_with_type: BIND '(' exp ')' BLOCK '(' exp ')' atype ':'  */
#line 1130 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.etree) = (yyvsp[-7].etree); }
#line 4261 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 314: /* opt_exp_without_type: exp ':'  */
#line 1134 "../../Scpel-0.0.7/ld/ldgram.y"
                                { (yyval.etree) = (yyvsp[-1].etree); }
#line 4267 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 315: /* opt_exp_without_type: ':'  */
#line 1135 "../../Scpel-0.0.7/ld/ldgram.y"
                                { (yyval.etree) = (etree_type *) NULL;  }
#line 4273 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 316: /* opt_nocrossrefs: %empty  */
#line 1140 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = 0; }
#line 4279 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 317: /* opt_nocrossrefs: NOCROSSREFS  */
#line 1142 "../../Scpel-0.0.7/ld/ldgram.y"
                        { (yyval.integer) = 1; }
#line 4285 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 318: /* memspec_opt: '>' NAME  */
#line 1147 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.name) = (yyvsp[0].name); }
#line 4291 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 319: /* memspec_opt: %empty  */
#line 1148 "../../Scpel-0.0.7/ld/ldgram.y"
                { (yyval.name) = DEFAULT_MEMORY_REGION; }
#line 4297 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 320: /* phdr_opt: %empty  */
#line 1153 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.section_phdr) = NULL;
		}
#line 4305 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 321: /* phdr_opt: phdr_opt ':' NAME  */
#line 1157 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  struct lang_output_section_phdr_list *n;

		  n = ((struct lang_output_section_phdr_list *)
		       xmalloc (sizeof *n));
		  n->name = (yyvsp[0].name);
		  n->used = false;
		  n->next = (yyvsp[-2].section_phdr);
		  (yyval.section_phdr) = n;
		}
#line 4320 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 323: /* $@33: %empty  */
#line 1173 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  ldlex_wild ();
			  lang_enter_overlay_section ((yyvsp[0].name));
			}
#line 4329 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 324: /* $@34: %empty  */
#line 1180 "../../Scpel-0.0.7/ld/ldgram.y"
                        { ldlex_popstate (); }
#line 4335 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 325: /* $@35: %empty  */
#line 1182 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  if (yychar == NAME)
			    {
			      yyclearin;
			      ldlex_backup ();
			    }
			  lang_leave_overlay_section ((yyvsp[0].fill), (yyvsp[-1].section_phdr));
			}
#line 4348 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 330: /* $@36: %empty  */
#line 1203 "../../Scpel-0.0.7/ld/ldgram.y"
                     { ldlex_expression (); }
#line 4354 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 331: /* $@37: %empty  */
#line 1204 "../../Scpel-0.0.7/ld/ldgram.y"
                                            { ldlex_popstate (); }
#line 4360 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 332: /* phdr: NAME $@36 phdr_type phdr_qualifiers $@37 ';'  */
#line 1206 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_new_phdr ((yyvsp[-5].name), (yyvsp[-3].etree), (yyvsp[-2].phdr).filehdr, (yyvsp[-2].phdr).phdrs, (yyvsp[-2].phdr).at,
				 (yyvsp[-2].phdr).flags);
		}
#line 4369 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 333: /* phdr_type: exp  */
#line 1214 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.etree) = (yyvsp[0].etree);

		  if ((yyvsp[0].etree)->type.node_class == etree_name
		      && (yyvsp[0].etree)->type.node_code == NAME)
		    {
		      const char *s;
		      unsigned int i;
		      static const char * const phdr_types[] =
			{
			  "PT_NULL", "PT_LOAD", "PT_DYNAMIC",
			  "PT_INTERP", "PT_NOTE", "PT_SHLIB",
			  "PT_PHDR", "PT_TLS"
			};

		      s = (yyvsp[0].etree)->name.name;
		      for (i = 0;
			   i < sizeof phdr_types / sizeof phdr_types[0];
			   i++)
			if (strcmp (s, phdr_types[i]) == 0)
			  {
			    (yyval.etree) = exp_intop (i);
			    break;
			  }
		      if (i == sizeof phdr_types / sizeof phdr_types[0])
			{
			  if (strcmp (s, "PT_GNU_EH_FRAME") == 0)
			    (yyval.etree) = exp_intop (0x6474e550);
			  else if (strcmp (s, "PT_GNU_STACK") == 0)
			    (yyval.etree) = exp_intop (0x6474e551);
			  else if (strcmp (s, "PT_GNU_RELRO") == 0)
			    (yyval.etree) = exp_intop (0x6474e552);
			  else if (strcmp (s, "PT_GNU_PROPERTY") == 0)
			    (yyval.etree) = exp_intop (0x6474e553);
			  else
			    {
			      einfo (_("\
%X%P:%pS: unknown phdr type `%s' (try integer literal)\n"),
				     NULL, s);
			      (yyval.etree) = exp_intop (0);
			    }
			}
		    }
		}
#line 4418 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 334: /* phdr_qualifiers: %empty  */
#line 1262 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  memset (&(yyval.phdr), 0, sizeof (struct phdr_info));
		}
#line 4426 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 335: /* phdr_qualifiers: NAME phdr_val phdr_qualifiers  */
#line 1266 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.phdr) = (yyvsp[0].phdr);
		  if (strcmp ((yyvsp[-2].name), "FILEHDR") == 0 && (yyvsp[-1].etree) == NULL)
		    (yyval.phdr).filehdr = true;
		  else if (strcmp ((yyvsp[-2].name), "PHDRS") == 0 && (yyvsp[-1].etree) == NULL)
		    (yyval.phdr).phdrs = true;
		  else if (strcmp ((yyvsp[-2].name), "FLAGS") == 0 && (yyvsp[-1].etree) != NULL)
		    (yyval.phdr).flags = (yyvsp[-1].etree);
		  else
		    einfo (_("%X%P:%pS: PHDRS syntax error at `%s'\n"),
			   NULL, (yyvsp[-2].name));
		}
#line 4443 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 336: /* phdr_qualifiers: AT '(' exp ')' phdr_qualifiers  */
#line 1279 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.phdr) = (yyvsp[0].phdr);
		  (yyval.phdr).at = (yyvsp[-2].etree);
		}
#line 4452 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 337: /* phdr_val: %empty  */
#line 1287 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.etree) = NULL;
		}
#line 4460 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 338: /* phdr_val: '(' exp ')'  */
#line 1291 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.etree) = (yyvsp[-1].etree);
		}
#line 4468 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 339: /* $@38: %empty  */
#line 1297 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_version_file ();
		  PUSH_ERROR (_("dynamic list"));
		}
#line 4477 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 340: /* dynamic_list_file: $@38 dynamic_list_nodes  */
#line 1302 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_popstate ();
		  POP_ERROR ();
		}
#line 4486 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 344: /* dynamic_list_tag: vers_defns ';'  */
#line 1319 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_append_dynamic_list (current_dynamic_list_p, (yyvsp[-1].versyms));
		}
#line 4494 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 345: /* $@39: %empty  */
#line 1327 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_version_file ();
		  PUSH_ERROR (_("VERSION script"));
		}
#line 4503 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 346: /* version_script_file: $@39 vers_nodes  */
#line 1332 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_popstate ();
		  POP_ERROR ();
		}
#line 4512 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 347: /* $@40: %empty  */
#line 1341 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_version_script ();
		}
#line 4520 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 348: /* version: $@40 VERSIONK '{' vers_nodes '}'  */
#line 1345 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  ldlex_popstate ();
		}
#line 4528 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 351: /* vers_node: '{' vers_tag '}' ';'  */
#line 1357 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_register_vers_node (NULL, (yyvsp[-2].versnode), NULL);
		}
#line 4536 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 352: /* vers_node: VERS_TAG '{' vers_tag '}' ';'  */
#line 1361 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_register_vers_node ((yyvsp[-4].name), (yyvsp[-2].versnode), NULL);
		}
#line 4544 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 353: /* vers_node: VERS_TAG '{' vers_tag '}' verdep ';'  */
#line 1365 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  lang_register_vers_node ((yyvsp[-5].name), (yyvsp[-3].versnode), (yyvsp[-1].deflist));
		}
#line 4552 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 354: /* verdep: VERS_TAG  */
#line 1372 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.deflist) = lang_add_vers_depend (NULL, (yyvsp[0].name));
		}
#line 4560 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 355: /* verdep: verdep VERS_TAG  */
#line 1376 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.deflist) = lang_add_vers_depend ((yyvsp[-1].deflist), (yyvsp[0].name));
		}
#line 4568 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 356: /* vers_tag: %empty  */
#line 1383 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versnode) = lang_new_vers_node (NULL, NULL);
		}
#line 4576 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 357: /* vers_tag: vers_defns ';'  */
#line 1387 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-1].versyms), NULL);
		}
#line 4584 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 358: /* vers_tag: GLOBAL ':' vers_defns ';'  */
#line 1391 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-1].versyms), NULL);
		}
#line 4592 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 359: /* vers_tag: LOCAL ':' vers_defns ';'  */
#line 1395 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versnode) = lang_new_vers_node (NULL, (yyvsp[-1].versyms));
		}
#line 4600 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 360: /* vers_tag: GLOBAL ':' vers_defns ';' LOCAL ':' vers_defns ';'  */
#line 1399 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versnode) = lang_new_vers_node ((yyvsp[-5].versyms), (yyvsp[-1].versyms));
		}
#line 4608 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 361: /* vers_defns: VERS_IDENTIFIER  */
#line 1406 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern (NULL, (yyvsp[0].name), ldgram_vers_current_lang, false);
		}
#line 4616 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 362: /* vers_defns: NAME  */
#line 1410 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern (NULL, (yyvsp[0].name), ldgram_vers_current_lang, true);
		}
#line 4624 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 363: /* vers_defns: vers_defns ';' VERS_IDENTIFIER  */
#line 1414 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern ((yyvsp[-2].versyms), (yyvsp[0].name), ldgram_vers_current_lang, false);
		}
#line 4632 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 364: /* vers_defns: vers_defns ';' NAME  */
#line 1418 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern ((yyvsp[-2].versyms), (yyvsp[0].name), ldgram_vers_current_lang, true);
		}
#line 4640 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 365: /* @41: %empty  */
#line 1422 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.name) = ldgram_vers_current_lang;
			  ldgram_vers_current_lang = (yyvsp[-1].name);
			}
#line 4649 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 366: /* vers_defns: vers_defns ';' EXTERN NAME '{' @41 vers_defns opt_semicolon '}'  */
#line 1427 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  struct bfd_elf_version_expr *pat;
			  for (pat = (yyvsp[-2].versyms); pat->next != NULL; pat = pat->next);
			  pat->next = (yyvsp[-8].versyms);
			  (yyval.versyms) = (yyvsp[-2].versyms);
			  ldgram_vers_current_lang = (yyvsp[-3].name);
			}
#line 4661 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 367: /* @42: %empty  */
#line 1435 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.name) = ldgram_vers_current_lang;
			  ldgram_vers_current_lang = (yyvsp[-1].name);
			}
#line 4670 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 368: /* vers_defns: EXTERN NAME '{' @42 vers_defns opt_semicolon '}'  */
#line 1440 "../../Scpel-0.0.7/ld/ldgram.y"
                        {
			  (yyval.versyms) = (yyvsp[-2].versyms);
			  ldgram_vers_current_lang = (yyvsp[-3].name);
			}
#line 4679 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 369: /* vers_defns: GLOBAL  */
#line 1445 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern (NULL, "global", ldgram_vers_current_lang, false);
		}
#line 4687 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 370: /* vers_defns: vers_defns ';' GLOBAL  */
#line 1449 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern ((yyvsp[-2].versyms), "global", ldgram_vers_current_lang, false);
		}
#line 4695 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 371: /* vers_defns: LOCAL  */
#line 1453 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern (NULL, "local", ldgram_vers_current_lang, false);
		}
#line 4703 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 372: /* vers_defns: vers_defns ';' LOCAL  */
#line 1457 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern ((yyvsp[-2].versyms), "local", ldgram_vers_current_lang, false);
		}
#line 4711 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 373: /* vers_defns: EXTERN  */
#line 1461 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern (NULL, "extern", ldgram_vers_current_lang, false);
		}
#line 4719 "../../Scpel-0.0.7/ld/ldgram.c"
    break;

  case 374: /* vers_defns: vers_defns ';' EXTERN  */
#line 1465 "../../Scpel-0.0.7/ld/ldgram.y"
                {
		  (yyval.versyms) = lang_new_vers_pattern ((yyvsp[-2].versyms), "extern", ldgram_vers_current_lang, false);
		}
#line 4727 "../../Scpel-0.0.7/ld/ldgram.c"
    break;


#line 4731 "../../Scpel-0.0.7/ld/ldgram.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1475 "../../Scpel-0.0.7/ld/ldgram.y"

void
yyerror(arg)
     const char *arg;
{
  if (ldfile_assumed_script)
    einfo (_("%P:%s: file format not recognized; treating as linker script\n"),
	   ldlex_filename ());
  if (error_index > 0 && error_index < ERROR_NAME_MAX)
    einfo ("%F%P:%pS: %s in %s\n", NULL, arg, error_names[error_index - 1]);
  else
    einfo ("%F%P:%pS: %s\n", NULL, arg);
}
