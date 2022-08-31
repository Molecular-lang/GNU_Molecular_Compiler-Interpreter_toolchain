/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 364 "../../Scpel-0.0.7/ld/ldgram.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY__SCPEL_LD_LDGRAM_H_INCLUDED  */
