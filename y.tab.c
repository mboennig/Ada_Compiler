/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 4 "ada.y" /* yacc.c:339  */

int yylex();
int yyerror(char*);
#include <stdio.h>
#include <string.h>
#include "binTree.c"
#include "linkedList.c"
#include "record.c"
#include "patchLink.c"
#include "rec_l.c"
int instruction = 0;
int current_register =1;
FILE *output;
int current_position = 0;
int is_raise = 0;
int handler_done = 0;
int exception_jump = 0;
int exception_count = 3;
int return_except = 0;
struct listEntry array[20];
extern int lineno;
struct link_Patch * patchList = NULL;
int jump_table[20];

#line 91 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IS = 258,
    BEG = 259,
    END = 260,
    PROCEDURE = 261,
    ID = 262,
    NUMBER = 263,
    TYPE = 264,
    ARRAY = 265,
    RAISE = 266,
    OTHERS = 267,
    RECORD = 268,
    IN = 269,
    OUT = 270,
    RANGE = 271,
    CONSTANT = 272,
    ASSIGN = 273,
    EXCEPTION = 274,
    NULLWORD = 275,
    LOOP = 276,
    IF = 277,
    THEN = 278,
    ELSEIF = 279,
    ELSE = 280,
    EXIT = 281,
    WHEN = 282,
    AND = 283,
    OR = 284,
    EQ = 285,
    NEQ = 286,
    LT = 287,
    GT = 288,
    GTE = 289,
    LTE = 290,
    TICK = 291,
    NOT = 292,
    EXP = 293,
    ARROW = 294,
    OF = 295,
    DOTDOT = 296,
    ENDIF = 297,
    ENDREC = 298,
    ENDLOOP = 299,
    EXITWHEN = 300
  };
#endif
/* Tokens.  */
#define IS 258
#define BEG 259
#define END 260
#define PROCEDURE 261
#define ID 262
#define NUMBER 263
#define TYPE 264
#define ARRAY 265
#define RAISE 266
#define OTHERS 267
#define RECORD 268
#define IN 269
#define OUT 270
#define RANGE 271
#define CONSTANT 272
#define ASSIGN 273
#define EXCEPTION 274
#define NULLWORD 275
#define LOOP 276
#define IF 277
#define THEN 278
#define ELSEIF 279
#define ELSE 280
#define EXIT 281
#define WHEN 282
#define AND 283
#define OR 284
#define EQ 285
#define NEQ 286
#define LT 287
#define GT 288
#define GTE 289
#define LTE 290
#define TICK 291
#define NOT 292
#define EXP 293
#define ARROW 294
#define OF 295
#define DOTDOT 296
#define ENDIF 297
#define ENDREC 298
#define ENDLOOP 299
#define EXITWHEN 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 67 "ada.y" /* yacc.c:355  */

  int integer;
  char *var;
  struct link_node * head;
  struct node * tree_node;
  struct Records * rec;
  struct link * rec_head;
  struct rec_l * rec_o;

#line 231 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 248 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      47,    48,    54,    53,    50,    51,    52,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    46,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    82,   101,   114,   147,   151,   159,   172,
     174,   178,   226,   273,   274,   275,   278,   279,   283,   284,
     285,   288,   289,   292,   353,   356,   359,   360,   361,   364,
     379,   396,   405,   426,   429,   435,   438,   439,   442,   446,
     452,   462,   463,   464,   465,   469,   470,   474,   493,   496,
     500,   506,   540,   544,   564,   565,   581,   601,   604,   605,
     646,   669,   672,   673,   677,   678,   679,   680,   681,   684,
    1263,  1264,  1269,  1272,  1287,  1290,  1303,  1308,  1309,  1312,
    1313,  1316,  1319,  1323,  1326,  1333,  1341,  1342,  1345,  1365,
    1372,  1374,  1378,  1379,  1388,  1389,  1392,  1405,  1420,  1424,
    1437,  1440,  1448,  1452,  1462,  1463,  1464,  1465,  1466,  1467,
    1470,  1471,  1474,  1475,  1479,  1489,  1523,  1524,  1660,  1726,
    1832,  1936,  1937,  1940,  1982,  1998,  2020,  2021,  2024,  2033,
    2037
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "BEG", "END", "PROCEDURE", "ID",
  "NUMBER", "TYPE", "ARRAY", "RAISE", "OTHERS", "RECORD", "IN", "OUT",
  "RANGE", "CONSTANT", "ASSIGN", "EXCEPTION", "NULLWORD", "LOOP", "IF",
  "THEN", "ELSEIF", "ELSE", "EXIT", "WHEN", "AND", "OR", "EQ", "NEQ", "LT",
  "GT", "GTE", "LTE", "TICK", "NOT", "EXP", "ARROW", "OF", "DOTDOT",
  "ENDIF", "ENDREC", "ENDLOOP", "EXITWHEN", "';'", "'('", "')'", "':'",
  "','", "'-'", "'.'", "'+'", "'*'", "'/'", "$accept", "program",
  "main_body", "main_specification", "procedure_body", "begin",
  "procedure_prime", "procedure_specification", "formal_parameter_part",
  "parameters", "declarative_part", "procedure_body_part", "declares",
  "objects", "variable", "const_variable", "identifier", "types", "array",
  "record", "range", "exceptions", "identifier_list", "type_name",
  "constant", "component_list", "record_ob", "mode", "boolean_op",
  "expression", "exprlist", "relation", "simple_expr", "term", "factor",
  "sequence_of_statements", "statement_list", "statement", "name",
  "opt_param", "looppart", "loopStart", "loop_list_struct", "loopstmt",
  "exit_statement", "null_stmt", "raise_i", "opt_assign", "ifstruct",
  "ifstart", "else_if_sequence", "option_else_part", "else_if_list",
  "else_if", "else_if_start", "else_part", "else_start", "end_if",
  "condition_if_else", "condition_if", "condition", "relation_op",
  "adding_op", "multiplying_op", "primary", "opt_rec_arr",
  "exception_part", "exception_start", "exceptionList", "excepthand",
  "choice_sequence", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    59,    40,    41,    58,
      44,    45,    46,    43,    42,    47
};
# endif

#define YYPACT_NINF -105

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-105)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    20,    47,  -105,    99,  -105,  -105,   113,    76,  -105,
      76,    37,   102,    46,    82,  -105,    95,  -105,  -105,  -105,
    -105,  -105,  -105,  -105,  -105,  -105,    21,  -105,   139,  -105,
     113,    76,  -105,  -105,    87,   113,    14,    76,    28,    82,
      98,    30,     7,   101,  -105,  -105,     4,   129,  -105,    87,
     103,  -105,    55,  -105,  -105,  -105,     3,  -105,   132,  -105,
    -105,  -105,  -105,   104,    76,   123,    87,  -105,   118,  -105,
     107,  -105,     3,   145,   136,  -105,   152,   131,  -105,  -105,
     114,     3,  -105,    52,  -105,  -105,    43,  -105,     8,     3,
       5,   106,    80,   -17,    83,  -105,   138,  -105,   121,     3,
     123,    90,   119,   117,  -105,  -105,   124,   129,   149,  -105,
      76,  -105,   106,    39,   120,     3,  -105,   122,    92,   131,
    -105,  -105,   125,   126,  -105,     3,   159,  -105,    -9,    83,
    -105,  -105,     3,  -105,  -105,  -105,  -105,  -105,  -105,     3,
    -105,  -105,     5,  -105,  -105,     5,    87,     8,   106,   128,
      76,  -105,    76,   123,   165,  -105,   127,    54,     3,     3,
    -105,   106,  -105,  -105,  -105,   135,  -105,  -105,  -105,    -3,
     120,  -105,    80,   -17,    83,  -105,   151,  -105,   123,  -105,
    -105,  -105,   133,    76,     3,   170,   106,    36,    87,    71,
    -105,  -105,   153,  -105,   151,     3,   134,  -105,  -105,    79,
    -105,  -105,  -105,     3,   173,  -105,   141,  -105,    87,  -105,
     106,   158,   144,  -105,    40,  -105,  -105,   140,  -105,    87,
      76,  -105,  -105,  -105,  -105
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     4,     1,    15,     0,    25,
       0,    17,     0,    10,     0,    14,     0,    18,    21,    22,
      34,    19,    26,    27,    28,    20,     0,     8,     0,    16,
      15,     0,     7,     6,     0,    15,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    89,    74,   124,    61,    62,
       0,    64,     0,    67,    68,    65,     0,    13,     0,    32,
      35,    23,    33,     0,     0,     0,     0,     9,    44,    85,
       0,    83,     0,     0,    87,   125,     0,     0,    63,    66,
       0,     0,    79,     0,    77,    80,   115,   114,     0,     0,
       0,   103,    48,    52,    54,    57,     0,   102,    58,     0,
       0,     0,     0,     0,    36,    37,     0,   124,    41,    42,
       0,    84,    50,     0,   122,     0,    69,     0,     0,   123,
     127,    81,     0,     0,    78,     0,     0,    60,     0,    55,
      45,    46,     0,   104,   105,   106,   108,   109,   107,     0,
     111,   110,     0,   112,   113,     0,     0,     0,    24,     0,
       0,    30,    39,     0,     0,    43,    12,    70,     0,     0,
      73,    86,     3,   129,   130,     0,   126,    82,    75,     0,
     122,   116,    47,    51,    53,    56,    91,    59,     0,    40,
      38,    31,     0,     0,     0,     0,    49,     0,     0,   118,
     120,    97,    93,    90,    95,     0,     0,     5,    11,     0,
      72,   121,   128,     0,     0,    99,     0,    92,     0,    94,
     101,     0,     0,    71,     0,   119,   100,     0,    98,     0,
       0,   117,    88,    96,    29
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -105,  -105,  -105,  -105,  -105,   146,  -105,  -105,  -105,     6,
      91,   176,  -105,  -105,  -105,  -105,    -7,  -105,  -105,  -105,
    -105,  -105,   -27,  -104,   -93,    38,  -105,  -105,  -105,   -67,
       9,    56,    53,   -81,    49,   -64,   142,   -34,  -105,  -105,
    -105,  -105,  -105,   112,  -105,  -105,  -105,  -105,  -105,  -105,
    -105,  -105,     2,  -105,  -105,  -105,  -105,  -105,  -105,  -105,
     116,  -105,  -105,  -105,   -80,    29,    93,  -105,  -105,    84,
    -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    34,    12,    13,    32,    40,
      14,    15,    16,    17,    18,    19,    46,    21,    22,    23,
      24,    25,    26,    61,   106,   102,   103,   110,   132,    91,
     113,    92,    93,    94,    95,    47,    48,    49,    50,    74,
      51,    52,    83,    84,    85,    53,    54,   116,    55,    56,
     192,   206,   193,   194,   195,   207,   208,   217,   211,    96,
      97,   139,   142,   145,    98,   160,    76,    77,   119,   120,
     165
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    27,   107,    28,    41,   112,   156,   149,   127,   129,
      86,    87,    86,    87,     9,    86,    87,     1,    82,   130,
     131,     9,   128,    20,    20,   130,   131,     5,    20,    60,
      62,    58,   148,    59,   140,    70,   141,   101,    63,   171,
      88,    64,    88,     8,    65,   189,   179,     6,   161,    82,
      89,    72,    89,    69,    90,    89,    73,    20,   169,     9,
     181,   174,     9,    42,   130,   131,    42,   177,   130,   131,
      36,    37,    43,    44,    45,    43,    44,    45,    80,    68,
      37,    80,   176,     9,   201,   196,    33,   157,   221,   158,
     125,   186,   187,    31,     9,   126,   123,    81,    42,   163,
      81,   184,     7,    60,   164,    30,   185,    43,    44,    45,
     133,   134,   135,   136,   137,   138,   224,   112,   203,     8,
       9,    39,    10,   204,   202,   101,    57,   213,   210,   158,
     104,   105,   108,   109,   130,   131,   214,   143,   144,   150,
      37,    35,    38,    60,   218,    20,    67,    71,    75,    79,
      99,   100,   114,   111,   115,   223,    41,   117,   118,   147,
     121,   146,   151,   152,   155,   153,   170,   159,   162,   178,
     182,   167,   168,   183,   188,   191,    20,   200,   205,   197,
     215,   219,   212,   216,   220,    66,   222,    29,   172,   198,
     180,    78,   173,   199,   175,   124,   209,   122,     0,   190,
     154,     0,     0,   166,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    60
};

static const yytype_int16 yycheck[] =
{
       7,     8,    66,    10,    31,    72,   110,   100,    88,    90,
       7,     8,     7,     8,     7,     7,     8,     6,    52,    28,
      29,     7,    89,    30,    31,    28,    29,     7,    35,    36,
      37,    17,    99,    19,    51,    42,    53,    64,    10,    48,
      37,    13,    37,     6,    16,    48,   150,     0,   115,    83,
      47,    47,    47,    46,    51,    47,    52,    64,   125,     7,
     153,   142,     7,    11,    28,    29,    11,   147,    28,    29,
      49,    50,    20,    21,    22,    20,    21,    22,    26,    49,
      50,    26,   146,     7,    48,   178,     4,    48,    48,    50,
      47,   158,   159,    47,     7,    52,    44,    45,    11,     7,
      45,    47,     3,   110,    12,     3,    52,    20,    21,    22,
      30,    31,    32,    33,    34,    35,   220,   184,    47,     6,
       7,    30,     9,    52,   188,   152,    35,    48,   195,    50,
       7,     8,    14,    15,    28,    29,   203,    54,    55,    49,
      50,    46,     3,   150,   208,   152,    48,    46,    19,    46,
      18,    47,     7,    46,    18,   219,   183,     5,    27,    38,
      46,    23,    43,    46,    15,    41,     7,    47,    46,    41,
       5,    46,    46,    46,    39,    24,   183,     7,    25,    46,
       7,    23,    48,    42,    40,    39,    46,    11,   132,   183,
     152,    49,   139,   184,   145,    83,   194,    81,    -1,   170,
     107,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   220
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    57,    58,    59,     7,     0,     3,     6,     7,
       9,    60,    62,    63,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    72,    72,    67,
       3,    47,    64,     4,    61,    46,    49,    50,     3,    66,
      65,    78,    11,    20,    21,    22,    72,    91,    92,    93,
      94,    96,    97,   101,   102,   104,   105,    66,    17,    19,
      72,    79,    72,    10,    13,    16,    61,    48,    49,    46,
      72,    46,    47,    52,    95,    19,   122,   123,    92,    46,
      26,    45,    93,    98,    99,   100,     7,     8,    37,    47,
      51,    85,    87,    88,    89,    90,   115,   116,   120,    18,
      47,    78,    81,    82,     7,     8,    80,    91,    14,    15,
      83,    46,    85,    86,     7,    18,   103,     5,    27,   124,
     125,    46,   116,    44,    99,    47,    52,   120,    85,    89,
      28,    29,    84,    30,    31,    32,    33,    34,    35,   117,
      51,    53,   118,    54,    55,   119,    23,    38,    85,    80,
      49,    43,    46,    41,   122,    15,    79,    48,    50,    47,
     121,    85,    46,     7,    12,   126,   125,    46,    46,    85,
       7,    48,    87,    88,    89,    90,    91,   120,    41,    79,
      81,    80,     5,    46,    47,    52,    85,    85,    39,    48,
     121,    24,   106,   108,   109,   110,    80,    46,    65,    86,
       7,    48,    91,    47,    52,    25,   107,   111,   112,   108,
      85,   114,    48,    48,    85,     7,    42,   113,    91,    23,
      40,    48,    46,    91,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    70,    71,    72,    73,    73,    73,    74,
      75,    76,    77,    78,    78,    79,    80,    80,    81,    81,
      82,    83,    83,    83,    83,    84,    84,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    89,    89,    90,    90,
      90,    91,    92,    92,    93,    93,    93,    93,    93,    94,
      95,    95,    95,    95,    95,    96,    97,    98,    98,    99,
      99,   100,   100,   101,   102,   102,   103,   103,   104,   105,
     106,   106,   107,   107,   108,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   117,   117,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   124,   124,   125,   126,
     126
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     2,     8,     1,     2,     2,     3,
       0,     6,     4,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     5,     1,     1,     1,     1,    11,
       6,     7,     3,     3,     1,     1,     1,     1,     3,     2,
       3,     1,     1,     2,     0,     1,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     2,     3,     1,     1,     3,
       2,     1,     1,     2,     1,     1,     2,     1,     1,     3,
       3,     6,     5,     3,     0,     4,     1,     1,     2,     1,
       1,     2,     3,     2,     3,     2,     2,     0,     8,     1,
       1,     0,     1,     0,     2,     1,     4,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     7,     4,     6,
       4,     3,     0,     2,     0,     1,     2,     1,     4,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 77 "ada.y" /* yacc.c:1646  */
    {printf ("\n*****\nDONE.\n*****\n");
		    printPatch(patchList, output);
		    }
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 85 "ada.y" /* yacc.c:1646  */
    { //take $4 for the jump number 
				   printf("Popping off the top of the stack %s \n", array[current_position-1].name);
				   printInParent(array[current_position-1].tree);
				   pop(&current_position);
				   fprintf(output, "%d	r%d := contents b, 1\n", instruction++, current_register);
                                   fprintf(output, "%d	b := contents b, 3\n", instruction++);
				   fprintf(output, "%d	pc := r%d\n", instruction++, current_register);
				   current_register++;
				   //pop off the the pop
				   insert_Patch(&patchList,0, instruction);
				   insert_Patch(&patchList,1, instruction + (yyvsp[-5].integer));
				   insert_Patch(&patchList,4, (yyvsp[-4].integer));
				   }
#line 1525 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 101 "ada.y" /* yacc.c:1646  */
    {push(array, &current_position, (yyvsp[0].var));
				   //put into start current instruction count 
				   fprintf(output, "%d 	b := ?\n", instruction++);
				   fprintf(output, "%d	contents b, 0 := ?\n", instruction++);
				   fprintf(output, "%d	contents b, 1 := 5\n", instruction++);
				   fprintf(output, "%d	r%d := 0\n", instruction++, current_register);
				   current_register++;
				   fprintf(output, "%d	pc := ?\n", instruction++);
				   fprintf(output, "%d	halt\n", instruction++);
				   incrementOffset(4);
				   }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "ada.y" /* yacc.c:1646  */
    {
                                        printf("Popping off the top of the stack %s \n", array[current_position-1].name);
                                        printInParent(array[current_position-1].tree);
                                        pop(&current_position);
					//fprintf(output, "THE CURRENT OFFSET IS %d\n", $3);
					(yyvsp[-7].tree_node)->lower= (yyvsp[-5].integer);
					(yyvsp[-7].tree_node)->value= (yyvsp[-4].integer);
					int i = 0;
					node_t * prodNode = (yyvsp[-7].tree_node)->next;
					if(prodNode != NULL){
                                        while(i == 0){
                                            printf("The kind is %s \n",prodNode->str);
					    if(strcmp(prodNode->mode,"In Out")==0 || strcmp(prodNode->mode, "Out")==0){
						fprintf(output, "%d	r%d := contents b, %d\n", instruction++, current_register, prodNode->value);
						fprintf(output, "%d	contents r%d := contents b, %d\n", instruction++, current_register, prodNode->offset);
						current_register++;
					    }
                                            if(prodNode->next != NULL){
                                                 prodNode = prodNode->next;
                                            }else{i=1;}
					}}
					
					fprintf(output, "%d	r%d := contents b, 1\n", instruction++, current_register);
                                        fprintf(output, "%d	b := contents b, 3\n", instruction++);
                                        fprintf(output, "%d	pc := r%d\n", instruction++, current_register);
					current_register++;
					prevOffset();
					}
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 147 "ada.y" /* yacc.c:1646  */
    { (yyval.integer)= instruction;
	     push_toPatchExp();
	   }
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 151 "ada.y" /* yacc.c:1646  */
    { //link the next if something is in parameters
								if(strcmp((yyvsp[0].var), "")!=0){
								  node_t * topProd = (yyvsp[-1].tree_node);
								  (yyvsp[-1].tree_node)->next = searchLocal(array, current_position, (yyvsp[0].var));
							        }
								(yyval.tree_node)=(yyvsp[-1].tree_node);
								}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "ada.y" /* yacc.c:1646  */
    { //do an add here, pass up the pointer to the procedure prime
						add(array, current_position, (yyvsp[0].var));
						node_t * prodNode = searchLocal(array, current_position, (yyvsp[0].var));
						strcpy(prodNode->kind, "procedure");
						//fprintf(output, "THE CURRENT OFFSET LATER IS %d\n", currentOffset());
						//prodNode->value=instruction;
						(yyval.tree_node) = prodNode;
  						push(array, &current_position, (yyvsp[0].var));
						nextOffset();
						incrementOffset(4);
						}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "ada.y" /* yacc.c:1646  */
    { (yyval.var) = (yyvsp[-1].var); 
					  }
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 174 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "";}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 178 "ada.y" /* yacc.c:1646  */
    {
                                   
					  printf("	line#: %d: ", lineno);
					  printLinks((yyvsp[-5].head));
                                          printf(": %s \n", (yyvsp[-2].var));
					  //$6 is the varaible of the node being passed in, do a search on it and connect it to the last
					  link_node current = (yyvsp[-5].head);
                                          while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
						    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
						    continue;
					         }
 						 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->mode, (yyvsp[-3].var));
						 strcpy(current_node->kind, "variable");
                                                 current_node->parent_Type= searchAll(array, current_position, (yyvsp[-2].var));
                                           	 //current_node->memSpace = current_node->parent_Type->memSpace;
						 if(current->next == NULL){
                                                     (yyval.var) = current->data;
                                                  }
						  
						 int off = currentOffset();
                                                 off = off - current_node->parent_Type->lower;
                                                 current_node->real_off = currentOffset();
                                                 current_node->offset = off;
                                                 incrementOffset(current_node->parent_Type->memSpace);
						 if(strcmp((yyvsp[-3].var), "In Out")==0 || strcmp((yyvsp[-3].var), "Out")==0){
                                          	      int offf = currentOffset();
                                                      offf = offf - current_node->parent_Type->lower;
						      current_node->value = offf;		
						      incrementOffset(current_node->parent_Type->memSpace);
                                                 }
						 current = current->next;

					 }
						
					 link_node c =(yyvsp[-5].head);
					 while(c->next != NULL){
                                                node_t * n_current = searchLocal(array, current_position, c->next->data);
                                                n_current->next = searchLocal(array, current_position, c->data);
                                                c = c->next;
                                            }
					node_t * make_next = searchLocal(array,current_position, (yyvsp[-5].head)->data);
					make_next->next = searchLocal(array, current_position, (yyvsp[0].var));

                                        }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 226 "ada.y" /* yacc.c:1646  */
    {
						printf("    line#: %d: ", lineno);
						printLinks((yyvsp[-3].head));
                                                printf(": %s \n", (yyvsp[0].var));
						link_node current = (yyvsp[-3].head);
                                                while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
                                                    continue;
                                                 }
						 //Here I connect all of the nodes together and pass up a pointer for the first node
                                                 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->mode, (yyvsp[-1].var));
						 //set the next to localSearch(current->next->data)
					         strcpy(current_node->kind, "variable");
                                                 current_node->parent_Type= searchAll(array, current_position, (yyvsp[0].var));
                                                 //current_node->memSpace = current_node->parent_Type->memSpace;

						 if(current->next == NULL){
						     (yyval.var) = current->data;
						  }
					          int off = currentOffset();
                                                 off = off - current_node->parent_Type->lower;
                                                 current_node->real_off = currentOffset();
                                                 current_node->offset = off;
                                                 incrementOffset(current_node->parent_Type->memSpace);
                                                 if(strcmp((yyvsp[-1].var), "In Out")==0 || strcmp((yyvsp[-1].var), "Out")==0){
                                                      int offf = currentOffset();
                                                      offf = offf - current_node->parent_Type->lower;
                                                      current_node->value = offf;               
                                                      incrementOffset(current_node->parent_Type->memSpace);
                                                 }
                                                 current = current->next;

                                            }//have another while loop that connects all of the nexts
					    link_node c =(yyvsp[-3].head);
					    while(c->next != NULL){
						node_t * n_current = searchLocal(array, current_position, c->next->data);
						n_current->next = searchLocal(array, current_position, c->data);
						c = c->next; 
					    }
					}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 273 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = currentOffset();}
#line 1731 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 274 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = currentOffset();}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 275 "ada.y" /* yacc.c:1646  */
    {(yyval.integer)= currentOffset();}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 292 "ada.y" /* yacc.c:1646  */
    { printf("	line#: %d - ", lineno);
					  printLinks((yyvsp[-2].head));
					  printf(": %s \n", (yyvsp[0].var));
					  link_node current = (yyvsp[-2].head);
					  while (current != NULL){
						 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
						    current = current->next;
                                                    continue;
                                                 }
                                                 add(array, current_position, current->data);
					         node_t * current_node = searchLocal(array, current_position, current->data);
					    	 strcpy(current_node->kind, "variable"); 
						 current_node->parent_Type= searchAll(array, current_position, (yyvsp[0].var));
						 if(strcmp(current_node->parent_Type->kind, "record")==0){
						    int running_off = currentOffset();
						    struct rec_l *head = current_node->parent_Type->recor_l;
						    struct rec_l *new = NULL; 
                                                    while(head != NULL){
                                                           node_t * node_type = searchAll(array, current_position, head->type);
							   insertLinkRec_l(&new, head->name,head->type ,running_off - node_type->lower);
                                                           running_off = running_off + node_type->memSpace;
                                                           head = head->next;
                                                        }
						    current_node->recor_l = new;
						    printf("Printing the old one\n");
						    printRec_l(current_node->parent_Type->recor_l);
						    printf("Printing the new one\n");
						    printRec_l(current_node->recor_l);
						 }else if(strcmp(current_node->parent_Type->kind, "array")==0 && strcmp(current_node->parent_Type->component_type->kind, "record")==0){
						   int running_off = currentOffset();
                                                    struct rec_l *head = current_node->parent_Type->component_type->recor_l;
                                                    struct rec_l *new = NULL; 
						    int i = 0;
                                                    while(head != NULL){
                                                           node_t * node_type = searchAll(array, current_position, head->type);
                                                           insertLinkRec_l(&new, head->name,head->type ,i);
							   i++;
                                                           head = head->next;
                                                        }
                                                    current_node->recor_l = new;
                                                    printf("Printing the new one\n");
                                                    printRec_l(current_node->recor_l);
						    current_node->parent_memory = current_node->parent_Type->component_type->memSpace;
						  
						 }
						 //current_node->memSpace = current_node->parent_Type->memSpace
						 int off = currentOffset();
						 off = off - current_node->parent_Type->lower;
						 printf("The current offset is %d\n", currentOffset());
						 current_node->real_off = currentOffset();
						 current_node->offset = off;
						 printf("The menspace for the offset is %d \n", current_node->parent_Type->memSpace);
						 incrementOffset(current_node->parent_Type->memSpace);

                                                 current = current->next;
                                            }
                                          }
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 356 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 364 "ada.y" /* yacc.c:1646  */
    { add(array, current_position, (yyvsp[-9].var));
     										node_t * current_node = searchLocal(array, current_position, (yyvsp[-9].var));
										current_node->lower = (yyvsp[-5].integer);
										current_node->upper = (yyvsp[-3].integer);
										current_node->component_type = searchAll(array, current_position, (yyvsp[0].var));
										strcpy(current_node->kind, "array");
										printf("The range is %d to %d\n", (yyvsp[-3].integer), (yyvsp[-5].integer));
										int range = (yyvsp[-3].integer) - (yyvsp[-5].integer);
										range = range+1;
										printf("I am multiplying %d by %d \n",range, current_node->component_type->memSpace);
                                                 				current_node->memSpace = range*current_node->component_type->memSpace;
										printf("THE CURRENT MEMSPACE IS %d \n", current_node->memSpace);
										}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 379 "ada.y" /* yacc.c:1646  */
    {add(array, current_position, (yyvsp[-4].var));
							node_t * current_node = searchLocal(array, current_position, (yyvsp[-4].var));
							current_node->recor_l = (yyvsp[-1].rec_o);
				   			struct rec_l *head = (yyvsp[-1].rec_o);
							int memS = 0;
							while(head != NULL){
							   node_t * node_type = searchAll(array, current_position, head->type);
							   memS = memS + node_type->memSpace;
							   head = head->next;
							}
							current_node->component_type = createNode("");
							strcpy(current_node->kind, "record");
							current_node->memSpace = memS;
							printRec_l((yyvsp[-1].rec_o));
						       }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 396 "ada.y" /* yacc.c:1646  */
    {add(array, current_position, (yyvsp[-5].var));
                                                          node_t * current_node = searchLocal(array, current_position, (yyvsp[-5].var));
                                                          current_node->lower = (yyvsp[-2].integer);
                                                          current_node->upper = (yyvsp[0].integer);
                                                          strcpy(current_node->kind, "range");
							  current_node->memSpace = 1;//TODO:This is hard coded, just assuming it is an int
                                                         }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 405 "ada.y" /* yacc.c:1646  */
    {
					 printf("      line#: %d - ", lineno);
                                          printLinks((yyvsp[-2].head));
                                          printf(": Exception \n");
                                          link_node current = (yyvsp[-2].head);
                                          while (current != NULL){
                                                 if(searchDFS(array[current_position-1].tree, current->data) == 1){
                                                    printf("ERROR: Duplicate IDs \n");
                                                    current = current->next;
                                                    continue;
                                                 }
                                                 add(array, current_position, current->data);
                                                 node_t * current_node = searchLocal(array, current_position, current->data);
                                                 strcpy(current_node->kind, "exception");
					         current_node->value = exception_count;
						 exception_count++;
                                                 current = current->next;
                                            }
					   }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 426 "ada.y" /* yacc.c:1646  */
    {(yyvsp[-2].head) = insertLink((yyvsp[-2].head),(yyvsp[0].var));
						  (yyval.head) = (yyvsp[-2].head);
						}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 429 "ada.y" /* yacc.c:1646  */
    {struct link_node *head;
			     head = initLink((yyvsp[0].var));
		             (yyval.head) = head;
			    }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 435 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = (yyvsp[0].var);}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 438 "ada.y" /* yacc.c:1646  */
    {(yyval.integer)=0;}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 439 "ada.y" /* yacc.c:1646  */
    {(yyval.integer)=(yyvsp[0].integer);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 442 "ada.y" /* yacc.c:1646  */
    {
                               		      insertLinkRec_l_node(&(yyvsp[-2].rec_o), &(yyvsp[0].rec_o));
                               		      (yyval.rec_o) = (yyvsp[-2].rec_o);
					     }
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 446 "ada.y" /* yacc.c:1646  */
    {
			       (yyval.rec_o) = (yyvsp[-1].rec_o);
			      }
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 452 "ada.y" /* yacc.c:1646  */
    {struct rec_l *test = NULL;
					  link_node current = (yyvsp[-2].head);
                                          while (current != NULL){ 
					   insertLinkRec_l(&test, current->data, (yyvsp[0].var), 0);
					   current = current->next; 
					  }
					 (yyval.rec_o) = test;
					 }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "In";}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 463 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "Out";}
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 464 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "In Out";}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 465 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "In";}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 469 "ada.y" /* yacc.c:1646  */
    {(yyval.var) ="and";}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 470 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "or";}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 474 "ada.y" /* yacc.c:1646  */
    {record * new_record = newRec();
					    if((yyvsp[-2].rec)->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[-2].rec)->register_n,(yyvsp[-2].rec)->walkback_n, (yyvsp[-2].rec)->offset);
                                 	   }	
                                 	   if((yyvsp[0].rec)->is_walkback){
                                   	       fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                 	    }	
                                            fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
                                                                                         (yyvsp[-2].rec)->is_reg?"r":"contents b, ",
                                                                                         (yyvsp[-2].rec)->is_reg?(yyvsp[-2].rec)->register_n:(yyvsp[-2].rec)->offset,
                                                                                         (yyvsp[-1].var),
                                                                                         (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                                         (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);

                                           new_record->is_reg = true;
                                           new_record->register_n = current_register;
                                           (yyval.rec) = new_record;
                                           current_register++; 
				           }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 493 "ada.y" /* yacc.c:1646  */
    {(yyval.rec) = (yyvsp[0].rec);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 496 "ada.y" /* yacc.c:1646  */
    { //TODO Make this a list of expressions 
	 			  insertLinkRec((yyvsp[-2].rec_head),(yyvsp[0].rec));
                                  (yyval.rec_head) = (yyvsp[-2].rec_head);
				 }
#line 2026 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 500 "ada.y" /* yacc.c:1646  */
    {struct link *head;
                       head = initLinkRec((yyvsp[0].rec));
                       (yyval.rec_head) = head;
		      }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 506 "ada.y" /* yacc.c:1646  */
    {
					    record * new_record = newRec();
					    if((yyvsp[-2].rec)->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[-2].rec)->register_n,(yyvsp[-2].rec)->walkback_n, (yyvsp[-2].rec)->offset);
                                 	    }
                                 	    if((yyvsp[0].rec)->is_walkback){
                                   		fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                 	    }
					    if(!(yyvsp[0].rec)->is_reg){
					       fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, (yyvsp[0].rec)->offset);
					       (yyvsp[0].rec)->register_n = current_register;
					       current_register++;
					    }
					    if(!(yyvsp[-2].rec)->is_reg){
                                               fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-2].rec)->offset); 
                                               (yyvsp[-2].rec)->register_n = current_register;
                                               current_register++;
                                            }	
					    if(strcmp((yyvsp[-1].var), ">")==0){
					     fprintf(output,"%d	r%d:= r%d < r%d\n", instruction++, current_register,(yyvsp[0].rec)->register_n, (yyvsp[-2].rec)->register_n);
					    }else if(strcmp((yyvsp[-1].var), ">=")==0){
                                            fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,(yyvsp[0].rec)->register_n, (yyvsp[-2].rec)->register_n);
					   }else{
					     fprintf(output,"%d	r%d:= r%d %s r%d\n", instruction++, current_register,
                                                                                         (yyvsp[-2].rec)->register_n,
                                                                                         (yyvsp[-1].var),
                                                                                         (yyvsp[0].rec)->register_n);

					   }
                                           new_record->is_reg = true;
                                           new_record->register_n = current_register;
                                           (yyval.rec) = new_record;
                                           current_register++;
					 }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 540 "ada.y" /* yacc.c:1646  */
    {(yyval.rec)=(yyvsp[0].rec);}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 544 "ada.y" /* yacc.c:1646  */
    {
					record * new_record = newRec();
					if((yyvsp[-2].rec)->is_walkback){
                                   	   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[-2].rec)->register_n,(yyvsp[-2].rec)->walkback_n, (yyvsp[-2].rec)->offset);
                                 	}
                                 	if((yyvsp[0].rec)->is_walkback){
                                   	  fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                 	}
                                        fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
                                                                                     (yyvsp[-2].rec)->is_reg?"r":"contents b, ",
                                                                                     (yyvsp[-2].rec)->is_reg?(yyvsp[-2].rec)->register_n:(yyvsp[-2].rec)->offset,
                                                                                     (yyvsp[-1].var),
                                                                                     (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                                     (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);

                                         new_record->is_reg = true;
                                         new_record->register_n = current_register;
                                         (yyval.rec) = new_record;
                                         current_register++;
					}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 564 "ada.y" /* yacc.c:1646  */
    {(yyval.rec)=(yyvsp[0].rec);}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 565 "ada.y" /* yacc.c:1646  */
    {record * new_record = newRec();
                       if((yyvsp[0].rec)->is_reg){
                           fprintf(output, "%d	r%d := - r%d\n",  instruction++, current_register, (yyvsp[0].rec)->register_n);
                           new_record->is_reg = true;
                           new_record->register_n = current_register;
                           current_register++;
                        }else{
                           fprintf(output, "%d	r%d := - contents b, %d\n",  instruction++, current_register, (yyvsp[0].rec)->offset);
                           new_record->is_reg = true;
                           new_record->register_n = current_register;
                           current_register++;
                        }
                        (yyval.rec) = new_record;           
			}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 581 "ada.y" /* yacc.c:1646  */
    {//TODO mulitplying opp, grab register, then move up stack, 
				 record * new_record = newRec();
			         if((yyvsp[-2].rec)->is_walkback){
				   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[-2].rec)->register_n,(yyvsp[-2].rec)->walkback_n, (yyvsp[-2].rec)->offset);
				 }
				 if((yyvsp[0].rec)->is_walkback){
                                   fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                 }
				 fprintf(output,"%d	r%d:= %s%d %s %s%d\n", instruction++, current_register,
				 					 (yyvsp[-2].rec)->is_reg?"r":"contents b, ",
									 (yyvsp[-2].rec)->is_reg?(yyvsp[-2].rec)->register_n:(yyvsp[-2].rec)->offset,
									 (yyvsp[-1].var),
									 (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                         (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);

				 new_record->is_reg = true;					
				 new_record->register_n = current_register;
				 (yyval.rec) = new_record;
				 current_register++;
				 }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 601 "ada.y" /* yacc.c:1646  */
    {(yyval.rec)=(yyvsp[0].rec);}
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 604 "ada.y" /* yacc.c:1646  */
    {(yyval.rec) = (yyvsp[0].rec);}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 605 "ada.y" /* yacc.c:1646  */
    {record * new_record = newRec();
			    if((yyvsp[-2].rec)->is_walkback){
                      		fprintf(output, "%d	r%d := contents r%d, %d\n",  instruction++, current_register, (yyvsp[-2].rec)->walkback_n, (yyvsp[-2].rec)->offset);
				(yyvsp[-2].rec)->is_reg = true;
                      		(yyvsp[-2].rec)->register_n = current_register;
                      		current_register++;
			    }else if(!(yyvsp[-2].rec)->is_reg){
				fprintf(output, "%d	r%d := contents b, %d\n",  instruction++, current_register, (yyvsp[-2].rec)->offset);
                      		(yyvsp[-2].rec)->is_reg = true;
                      		(yyvsp[-2].rec)->register_n = current_register;
                      		current_register++;
			    }
			    if((yyvsp[0].rec)->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d\n",  instruction++, current_register, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                (yyvsp[0].rec)->is_reg = true;
                                (yyvsp[0].rec)->register_n = current_register;
				current_register++;
                            }else if(!(yyvsp[0].rec)->is_reg){
                                fprintf(output, "%d	r%d := contents b, %d\n",  instruction++, current_register, (yyvsp[0].rec)->offset);
                                (yyvsp[0].rec)->is_reg = true;
                                (yyvsp[0].rec)->register_n = current_register;
                                current_register++;
                            }
			    
			    fprintf(output, "%d	r%d := 1\n",  instruction++, current_register);
			    int product_reg = current_register;
			    current_register++;
			    fprintf(output, "%d	r%d := 1\n",  instruction++, current_register);
                            int dec_reg = current_register;
                            current_register++;
			    int jump_int = instruction;
			    fprintf(output,"%d	r%d:= r%d * r%d\n", instruction++, product_reg, product_reg, (yyvsp[-2].rec)->register_n);
			    fprintf(output, "%d	r%d := r%d = r%d\n",  instruction++, current_register, (yyvsp[0].rec)->register_n, dec_reg);
                            int comp_reg = current_register;
                            current_register++;
			    fprintf(output,"%d	r%d:= r%d - r%d\n", instruction++, (yyvsp[0].rec)->register_n, (yyvsp[0].rec)->register_n, dec_reg);
			    fprintf(output,"%d	pc:= %d if not r%d\n", instruction++, jump_int, comp_reg);
			    new_record->is_reg = true;
                            new_record->register_n = product_reg;
			    (yyval.rec)= new_record;
			    }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 646 "ada.y" /* yacc.c:1646  */
    {record * new_record = newRec();
		     if((yyvsp[0].rec)->is_walkback){
		      fprintf(output, "%d	r%d := not contents r%d, %d\n",  instruction++, current_register, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                      new_record->is_reg = true;
                      new_record->register_n = current_register;
                      current_register++;
		    }else if((yyvsp[0].rec)->is_reg){
		      fprintf(output, "%d	r%d := not r%d\n",  instruction++, current_register, (yyvsp[0].rec)->register_n);
		      new_record->is_reg = true;
                      new_record->register_n = current_register;
		      current_register++;
		    }else{
		      fprintf(output, "%d	r%d := not contents b, %d\n",  instruction++, current_register, (yyvsp[0].rec)->offset);
                      new_record->is_reg = true;
                      new_record->register_n = current_register;
		      current_register++;
		     }
		    (yyval.rec) = new_record;
		    }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 684 "ada.y" /* yacc.c:1646  */
    {
		 node_t * current_node = searchAll(array, current_position, (yyvsp[-2].var));//There should be a node in the tree since it added before 
                 record * rec = newRec();
                 if(strcmp(current_node->kind, "read_routine")==0){
                     if((yyvsp[-1].rec_head)->data->is_walkback){
                         fprintf(output, "%d	read contents r%d, %d\n",instruction++, (yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                     }else{
                         fprintf(output,"%d	read %s%d \n", instruction++,
                         (yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ",
                         (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                         }
                }else if(strcmp(current_node->kind, "write_routine")==0){
		      link head = (yyvsp[-1].rec_head);
		      while (head != NULL){
                      if(head->data->is_walkback){
                                fprintf(output, "%d     r%d := contents r%d, %d\n",  instruction++, current_register, head->data->walkback_n, head->data->offset);
				current_register++;
		      }
        	      fprintf(output,"%d      write %s%d \n", instruction++,
                                                              head->data->is_reg?"r":"contents b, ",
                                                              head->data->is_reg?head->data->register_n:head->data->offset);
        	      head = head->next;
    		     }
 
                      //instruction = printRecs($2, output, instruction);
                }else if((yyvsp[-1].rec_head) != NULL && (yyvsp[0].rec) != NULL){
			//LHS ARRAY ALSO use for LHS records
				printf("The current node parent type is %s\n", current_node->parent_Type->kind);
				printf("The current component type is '%s'\n", current_node->parent_Type->component_type->kind);
				if(strcmp(current_node->parent_Type->component_type->kind, "array")==0){
				//For LHS Arrays of Arrays
					printf("Going into an array of arrays\n");
					record * first_exp = newRec();
					record * second_exp = newRec();
					second_exp = (yyvsp[-1].rec_head)->data;
					first_exp = (yyvsp[-1].rec_head)->next->data;
                                        node_t * second_node = current_node->parent_Type->component_type;
                                        if(first_exp->is_walkback){
                                             fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                         }
                                        if(first_exp->is_walkback){
                                             fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                        }
					fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    	int lower_r = current_register;
                                    	current_register++;
                                    	fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    	int upper_r = current_register;
                                    	current_register++;
                                    	if(!(yyvsp[-1].rec_head)->data->is_reg){
                                      	fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
                                      	(yyvsp[-1].rec_head)->data->register_n = current_register;
                                      	current_register++;
                                    	}
                                    	fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,(yyvsp[-1].rec_head)->data->register_n,
                                                                                         upper_r);
                                    	int upper_comp = current_register;
                                   	 current_register++;
                                    	fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          (yyvsp[-1].rec_head)->data->register_n);
                                    	int lower_comp = current_register;
                                    	current_register++;
                                    	fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    	is_raise = 1;
                                    	int i = instruction + 3;
                                    	fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    	fprintf(output,"%d	r1 := 1\n", instruction++);
                                    	//if there are no handlers need to jump to the base 
                                    	add_toPatchExp(instruction);
                                    	fprintf(output,"%d	pc := ?\n", instruction++);
                                    	current_register++;

					fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,second_node->lower);
                                        int lower_reg = current_register;
                                        current_register++;
                                        fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,second_node->upper);
                                        int upper_reg = current_register;
                                        current_register++;
                                        if(!second_exp->is_reg){
                                        fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, second_exp->offset);
                                        second_exp->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d      r%d:= r%d <= r%d\n", instruction++, current_register,second_exp->register_n,
                                                                                         upper_reg);
                                        int upper_comper = current_register;
                                         current_register++;
                                        fprintf(output,"%d      r%d:= r%d <= r%d\n", instruction++, current_register, lower_reg,
                                                                                          second_exp->register_n);
                                        int lower_comper = current_register;
                                        current_register++;
                                        fprintf(output, "%d     r%d:= r%d and r%d\n", instruction++, current_register, upper_comper, lower_comper);
                                        is_raise = 1;
                                        int in = instruction + 3;
                                        fprintf(output, "%d     pc := %d if r%d\n", instruction++,in, current_register);
                                        fprintf(output,"%d      r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d      pc := ?\n", instruction++);
                                        current_register++;

					      int space_1 = second_node->upper;
                                              space_1 = space_1 - second_node->lower;
                                              space_1++;
                                              int low = current_node->parent_Type->lower;
                                              //to find the offset I am taking the base offset then adding the two expressions onto it 
                                              //int space_1 = second_node->upper - second_node->lower;
					      int old_reg;
                                              int numberWalk = searchInt(array, current_position, (yyvsp[-2].var));
                                              if(numberWalk == 0){
                                                fprintf(output, "%d     r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d      r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
                                                int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
                                                int s = current_register;
                                                current_register++;
                                               	fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register, s);
						old_reg = current_register;
                                                current_register++;
                                              }else{
                                                  fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                                  while(numberWalk > 0){
                                                     fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                      numberWalk--;
                                                  }
						int walk_reg = current_register;
   						current_register++;
                                                fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
                                                int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
 						current_register++;
						fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, current_register-1, walk_reg);                                               
                                                old_reg = current_register;
                                                current_register++;
                                                //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                                current_register++;
                                                }
					int of = current_node->real_off - second_node->lower;
					if((yyvsp[0].rec)->is_walkback){
                                           fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, of, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                        }else if((yyvsp[0].rec)->is_reg){
                                           fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, of, (yyvsp[0].rec)->register_n);
                                        }else{
                                           fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, of, (yyvsp[0].rec)->offset);
                                        }

				}else if(strcmp(current_node->parent_Type->component_type->kind,"record")==0){
					printf("Going into an array of records\n");
					int numberWalk = searchInt(array, current_position, (yyvsp[-2].var));
                                	int offset;
                                	struct rec_l *head = current_node->recor_l;
                                	node_t * type_node;
                                	while(head != NULL){
                                   	if(strcmp(head->name, (yyvsp[-1].rec_head)->data->param_n)==0){
                                      		offset=head->offset;
                                      	type_node = searchAll(array, current_position, head->type);
                                   	break;
                                  	}
                                  	head = head->next;
				     }
					fprintf(output,"%d	 r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
                                    if(!(yyvsp[-1].rec_head)->data->is_reg){
                                      fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
                                      (yyvsp[-1].rec_head)->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,(yyvsp[-1].rec_head)->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          (yyvsp[-1].rec_head)->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d 	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                   if((yyvsp[-1].rec_head)->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec_head)->data->register_n,(yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                                    }
                                    int old_reg;
                                    if(numberWalk == 0){
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++; 
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i, (yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ",
                                                                                                                   (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                    int z = current_register;
                                    fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register,z);
				      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d       r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d   r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                    int reg = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i, (yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ",
                                                                                                                   (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                    int z = current_register;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,z, reg);
                                      old_reg = current_register;
                                      current_register++;

				     }
                                    if((yyvsp[0].rec)->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, current_node->offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                    }else if((yyvsp[0].rec)->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, current_node->offset, (yyvsp[0].rec)->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, current_node->offset, (yyvsp[0].rec)->offset);
                                  }

                                

				
				}else if(strcmp(current_node->parent_Type->kind,"array")==0){
				    printf("Going into a regular array\n");
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
				    int upper_r = current_register;
                                    current_register++;
                                    if(!(yyvsp[-1].rec_head)->data->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
                                      (yyvsp[-1].rec_head)->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,(yyvsp[-1].rec_head)->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          (yyvsp[-1].rec_head)->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                
                                   if((yyvsp[-1].rec_head)->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec_head)->data->register_n,(yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                                    }
                                    int numberWalk = searchInt(array, current_position, (yyvsp[-2].var));
				    int old_reg;
                                    if(numberWalk == 0){
                                      fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register,(yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ", 
														   (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                                      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                     fprintf(output, "%d	r%d := r%d + %s%d\n",  instruction++, current_register, current_register, (yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ",
                                                                                                                   (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                                     old_reg = current_register;
                                     current_register++;
                                    }
				    if((yyvsp[0].rec)->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, current_node->offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                    }else if((yyvsp[0].rec)->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, current_node->offset, (yyvsp[0].rec)->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n",instruction++, old_reg, current_node->offset, (yyvsp[0].rec)->offset);
                                  }
			    }
				
			    //For records
			    else if(strcmp(current_node->parent_Type->kind,"record")==0){
                       		//search the list to find the what is trying to be accessed 
				printf("Going into a regular record\n");
                        	int numberWalk = searchInt(array, current_position, (yyvsp[-2].var));
                        	int offset;
                        	struct rec_l *head = current_node->recor_l;
				node_t * type_node;
                        	while(head != NULL){
                           	   if(strcmp(head->name, (yyvsp[-1].rec_head)->data->param_n)==0){
                                      offset=head->offset;
				      type_node = searchAll(array, current_position, head->type);
                                   break;
                                  }
                                  head = head->next;
                                }
			     if(strcmp(type_node->kind, "array")==0){
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!(yyvsp[-1].rec_head)->data->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
                                      (yyvsp[-1].rec_head)->data->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         (yyvsp[-1].rec_head)->data->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                            (yyvsp[-1].rec_head)->data->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;

                                   if((yyvsp[-1].rec_head)->data->is_walkback){
                                     fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec_head)->data->register_n,(yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                                    }
                                    int old_reg;
                                    if(numberWalk == 0){
                                      fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register,(yyvsp[-1].rec_head)->data->is_reg?"r":"contents b, ",
                                                                                                                   (yyvsp[-1].rec_head)->data->is_reg?(yyvsp[-1].rec_head)->data->register_n:(yyvsp[-1].rec_head)->data->offset);
                                      old_reg = current_register;
                                      current_register++;
                                    }else{
                                      fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                          while(numberWalk > 0){
                                                  fprintf(output, "%d   r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                  numberWalk--;
                                          }
                                     fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, (yyvsp[-1].rec_head)->data->register_n);
                                     old_reg = current_register;
                                     current_register++;
                                    }
                                    if((yyvsp[0].rec)->is_walkback){
                                        fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++,old_reg, offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                    }else if((yyvsp[0].rec)->is_reg){
                                      fprintf(output, "%d	contents r%d, %d := r%d\n",  instruction++,old_reg, offset, (yyvsp[0].rec)->register_n);
                                    }else{
                                     fprintf(output, "%d	contents r%d, %d := contents b, %d\n", instruction++,  old_reg, offset, (yyvsp[0].rec)->offset);
                                  }




			     }else{
			     if(numberWalk ==0){
                                    if((yyvsp[0].rec)->is_walkback){
                                      fprintf(output, "%d	contents b, %d := contents r%d, %d\n",  instruction++, offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                    }else if((yyvsp[0].rec)->is_reg){
                                      fprintf(output, "%d	contents b, %d := r%d\n",  instruction++, offset, (yyvsp[0].rec)->register_n);
                                    }else{
                                      fprintf(output, "%d	contents b, %d := contents b, %d\n",  instruction++, offset, (yyvsp[0].rec)->offset);
                                   }
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                   while(numberWalk > 0){
                                        fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                        numberWalk--;
                                   }
                                   if((yyvsp[0].rec)->is_walkback){
                                      fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++, current_register,
                                                                                             offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                   }else{
                                   fprintf(output,"%d	contents r%d, %d := %s%d \n", instruction++, current_register,offset,
                                                                         (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                         (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);
                                  }
                                  current_register++;
                     	    }
			  }
			}

		 }else if ((yyvsp[-1].rec_head) == NULL && (yyvsp[0].rec) != NULL){
		    //node_t * current_node = searchAll(array, current_position, $1);
				if(strcmp(current_node->parent_Type->kind,"range")==0){
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
				    int lower_r = current_register;
				    current_register++;
				    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
				    int upper_r = current_register;
				    current_register++;
				    if(!(yyvsp[0].rec)->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[0].rec)->offset);
                                      (yyvsp[0].rec)->register_n = current_register;
                                      current_register++;
                                    }
				    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         (yyvsp[0].rec)->register_n,
                                                                                         upper_r);
				    int upper_comp = current_register;
				    current_register++;
				    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         (yyvsp[0].rec)->register_n);
				    int lower_comp = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                     current_register++;


				 }
                                 int numberWalk = searchInt(array, current_position, (yyvsp[-2].var));
                                 if(numberWalk ==0){
                                    if((yyvsp[0].rec)->is_walkback){
                                      fprintf(output, "%d	contents b, %d := contents r%d, %d\n",  instruction++, current_node->offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                    }else if((yyvsp[0].rec)->is_reg){
                                      fprintf(output, "%d	contents b, %d := r%d\n",  instruction++, current_node->offset, (yyvsp[0].rec)->register_n);
                                    }else{
                                      fprintf(output, "%d	contents b, %d := contents b, %d\n",  instruction++, current_node->offset, (yyvsp[0].rec)->offset);
                                   }
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                   while(numberWalk > 0){
                                        fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                        numberWalk--;
                                   }
                                   if((yyvsp[0].rec)->is_walkback){
                                      fprintf(output, "%d	contents r%d, %d := contents r%d, %d\n",  instruction++, current_register,
                                                                                             current_node->offset, (yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                                   }else{
                                   fprintf(output,"%d	contents r%d, %d := %s%d \n", instruction++, current_register,current_node->offset,
                                                                         (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                         (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);
                                  }
                                  current_register++;
                                }
                                

		 }else{
		 //THIS IS FOR PROCEDURE CALLS, ADD A CHECK TO SEE IF THERE ARE ANY PARAMETER 
	         //do register and everything here 
		 //fprintf(output, "%d      contents b, %d := r%d\n",  instruction++, current_node->offset, $3->register_n); 
		 //TODO for function call
		 //node_t * current_node = searchAll(array, current_position, $1);//Finding the node for the procedure to get the size;
		 int x = searchInt(array, current_position, (yyvsp[-2].var));
		 fprintf(output,"%d	r%d:= b\n", instruction++, current_register);
		 fprintf(output,"%d	b := contents r%d, 0\n", instruction++, current_register);
		 fprintf(output,"%d	contents b, 3 := r%d\n", instruction++, current_register);
		 if(x==0){
		 	fprintf(output,"%d	contents b, 2 := r%d\n", instruction++, current_register);
		  }else{
			//fprintf(output, "%d     r%d := contents b, 2\n",  instruction++, current_register);
			while(x>0){
			fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
			x--;
			}
			fprintf(output, "%d	contents b, 2 := r%d\n",  instruction++, current_register);
		  }
		 //Do the other one here
		 //Increase register
		 int theWalkBackReg = current_register;
		 current_register++;
		 fprintf(output,"%d	r%d:= %d\n", instruction++, current_register, current_node->lower);
		 fprintf(output,"%d	contents b, 0 := b + r%d\n", instruction++, current_register);
		 current_register++;
		 //check here for in and in out
		 if((yyvsp[-1].rec_head) != NULL){
		    //take the link from the procedure node
		    
		    //take exprlist and go over it
		    struct link *list = (yyvsp[-1].rec_head);
		    struct link * list_r;
		    while(list != NULL){
		        list_r = insertLinkRec2(list_r, list->data);
			list = list->next;
		    }
                    node_t * prodNode = current_node->next;
		    while((yyvsp[-1].rec_head) != NULL){
			if(strcmp(prodNode->mode,"In")==0){//IN
			  if((yyvsp[-1].rec_head)->data->is_reg){
			    if((yyvsp[-1].rec_head)->data->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec_head)->data->register_n,(yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                             }
			  fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->offset,(yyvsp[-1].rec_head)->data->register_n);
			  }else{
			   fprintf(output, "%d   contents b, %d := contents r%d, %d\n", instruction++, prodNode->offset, theWalkBackReg, (yyvsp[-1].rec_head)->data->offset);
			  }
			}
			else if(strcmp(prodNode->mode,"In Out")==0){//IN OUT
                          if((yyvsp[-1].rec_head)->data->is_reg){
			     if((yyvsp[-1].rec_head)->data->is_walkback){
                                fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec_head)->data->register_n,(yyvsp[-1].rec_head)->data->walkback_n, (yyvsp[-1].rec_head)->data->offset);
                             }
                          fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->offset,(yyvsp[-1].rec_head)->data->register_n);
                          }else{
                           fprintf(output, "%d	contents b, %d := contents r%d, %d\n", instruction++, prodNode->offset, theWalkBackReg, (yyvsp[-1].rec_head)->data->offset);
                          }
			  fprintf(output, "%d	r%d := %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
			  int u = current_register;
			  current_register++;
			  fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, theWalkBackReg, u);
			  int y = current_register;
			  current_register++;
			  fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->value,y);
                        }else if(strcmp(prodNode->mode,"Out")==0){//OUT
			 fprintf(output, "%d	r%d := %d\n", instruction++, current_register, (yyvsp[-1].rec_head)->data->offset);
                          int u = current_register;
                          current_register++;
                          fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register, theWalkBackReg, u);
                          int y = current_register;
                          current_register++;
                          fprintf(output, "%d	contents b, %d := r%d\n", instruction++, prodNode->value,y);
			}
			prodNode = prodNode->next;
                        (yyvsp[-1].rec_head) = (yyvsp[-1].rec_head)->next;
		   
		   }
		 }
		 fprintf(output,"%d	r%d:= %d\n", instruction++, current_register, instruction+3);
		 fprintf(output,"%d	contents b, 1 := r%d\n", instruction++, current_register);
		 current_register++;
		 fprintf(output,"%d	pc := %d\n", instruction++, current_node->value);
		 return_except = instruction;	 
		 fprintf(output,"%d	pc := ? if r1\n", instruction++);
		 }
		}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1263 "ada.y" /* yacc.c:1646  */
    {(yyval.rec_head) = (yyvsp[-1].rec_head);}
#line 2825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1264 "ada.y" /* yacc.c:1646  */
    {struct link *head;
						head = initLinkRec((yyvsp[-4].rec_head)->data);
						insertLinkRec(head, (yyvsp[-1].rec_head)->data);
						(yyval.rec_head) = head;
						}
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1269 "ada.y" /* yacc.c:1646  */
    {strcpy((yyvsp[-3].rec_head)->data->param_n, (yyvsp[0].var)); 
                                (yyval.rec_head) = (yyvsp[-3].rec_head);
				}
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1272 "ada.y" /* yacc.c:1646  */
    {//for records
		   //need to add another option in the exprList for a string so I can pass up ID
		   if((yyvsp[0].rec) == NULL){
		      struct link *head;
		      record * new_record = newRec();
		      strcpy(new_record->param_n,(yyvsp[-1].var));
                      head = initLinkRec(new_record);
                      (yyval.rec_head) = head;
		   }else{
		     strcpy((yyvsp[0].rec)->param_n, (yyvsp[-1].var));
		     struct link *head;
		     head = initLinkRec((yyvsp[0].rec));
		     (yyval.rec_head) = head;
		   }
		  }
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1287 "ada.y" /* yacc.c:1646  */
    {(yyval.rec_head) = NULL;}
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1290 "ada.y" /* yacc.c:1646  */
    {fprintf(output,"%d	pc := %d\n", instruction++, (yyvsp[-3].integer));
						 struct link_toPatch *h = grab_toPatch();
  						 while (h != NULL){
						    insert_Patch(&patchList,h->value, instruction);
     						    //printf("%d ,", h->value);
     						    h = h->next;
    						  }
						  pop_toPatch();
						  //fprintf(output,"%d	pc := %d\n", instruction++, $1);
					        }
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1303 "ada.y" /* yacc.c:1646  */
    {(yyval.integer) = instruction;
		push_toPatch();
		}
#line 2892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1316 "ada.y" /* yacc.c:1646  */
    {add_toPatch(instruction);
                          fprintf(output,"%d	pc := ?\n", instruction++);
                         }
#line 2900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1319 "ada.y" /* yacc.c:1646  */
    {fprintf(output,"%d	pc := ? if r%d\n", instruction++, (yyvsp[-1].rec)->register_n);
				      }
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1326 "ada.y" /* yacc.c:1646  */
    {is_raise = 1;
			      node_t * current_node = searchAll(array, current_position, (yyvsp[-1].var));
			      fprintf(output,"%d	r1 := %d\n", instruction++, current_node->value);
			      add_toPatchExp(instruction);
			      fprintf(output,"%d	pc := ?\n", instruction++);
			      
			     }
#line 2919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1333 "ada.y" /* yacc.c:1646  */
    {is_raise = 1;
			     handler_done = 1;
			     add_toPatchExp(instruction);
                             fprintf(output,"%d	pc := ?\n", instruction++);
			     }
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1341 "ada.y" /* yacc.c:1646  */
    {(yyval.rec)= (yyvsp[0].rec);}
#line 2935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1342 "ada.y" /* yacc.c:1646  */
    {(yyval.rec) = NULL;}
#line 2941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1345 "ada.y" /* yacc.c:1646  */
    {
												     struct link_toPatch *r = grab_toPatchCond();
                                                                      				     while (r != NULL){
                                                                          				insert_Patch(&patchList,r->value,(yyvsp[-1].integer));
                                                                          				//printf("inserting into if %d ,", h->value);
                                                                          				r = r->next;
                                                                      				      }
                                                                      				     //printf("\n");
												     struct link_toPatch *h = grab_toPatch();
                                                 						     while (h != NULL){
                                                    						     insert_Patch(&patchList,h->value, (yyvsp[-1].integer));
                                                    						     //printf("inserting into if %d ,", h->value);
                                                    						     h = h->next;
                                                 						     }
												     //printf("\n");
                                                  						     pop_toPatch();
												     pop_toPatchCond();
												    }
#line 2964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1365 "ada.y" /* yacc.c:1646  */
    {
            push_toPatch();
	   push_toPatchCond();
	   }
#line 2973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1372 "ada.y" /* yacc.c:1646  */
    {
			       }
#line 2980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1374 "ada.y" /* yacc.c:1646  */
    {
		}
#line 2987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1379 "ada.y" /* yacc.c:1646  */
    {struct link_toPatch *r = grab_toPatchCond();
                  while (r != NULL){
                      insert_Patch(&patchList,r->value,instruction);
                      r = r->next;
                   }
                 pop_toPatchCond();
		  }
#line 2999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1392 "ada.y" /* yacc.c:1646  */
    {//struct link_toPatch *h = grab_toPatchCond();
                                                                      //while (h != NULL){
                                                                        //  insert_Patch(&patchList,h->value,instruction+1);
                                                                          //printf("inserting into if %d ,", h->value);
                                                                         // h = h->next;
                                                                     // }
                                                                      //printf("\n");
                                                                      //pop_toPatchCond();

								}
#line 3014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1405 "ada.y" /* yacc.c:1646  */
    {struct link_toPatch *h = grab_toPatchCond();
                      while (h != NULL){
                      insert_Patch(&patchList,h->value,instruction+1);
                      //printf("inserting into if %d ,", h->value);
                      h = h->next;
                      }
                      //printf("\n");
		      //pop_toPatch();
                      pop_toPatchCond();
		      fprintf(output,"%d	pc := ?\n", instruction++);
		      add_toPatch(instruction-1);
		      
		     }
#line 3032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1424 "ada.y" /* yacc.c:1646  */
    {  struct link_toPatch *h = grab_toPatchCond();
                      while (h != NULL){
                      insert_Patch(&patchList,h->value,instruction+1);
                      //printf("inserting into if %d ,", h->value);
                      h = h->next;
                      }
                      //printf("\n");
                      pop_toPatchCond();
		      fprintf(output,"%d        pc := ?\n", instruction++);
                      add_toPatch(instruction-1);
		}
#line 3048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1437 "ada.y" /* yacc.c:1646  */
    {(yyval.integer)=instruction;}
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1440 "ada.y" /* yacc.c:1646  */
    {if((yyvsp[0].rec)->is_walkback){
                                 fprintf(output, "%d    r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                              }
			      push_toPatchCond();
			      add_toPatchCond(instruction);
			      fprintf(output,"%d     pc := ? if not r%d\n", instruction++, (yyvsp[0].rec)->register_n);
			     }
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1448 "ada.y" /* yacc.c:1646  */
    { fprintf(output,"%d	pc := ? if not r%d\n", instruction++, (yyvsp[0].rec)->register_n);
			}
#line 3073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1452 "ada.y" /* yacc.c:1646  */
    {if((yyvsp[0].rec)->is_walkback){
                        fprintf(output, "%d    r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                      } 
		      (yyval.rec) = (yyvsp[0].rec);
		      push_toPatchCond();
		      add_toPatchCond(instruction);
		      //ifprintf(output,"%d	pc := ? if not r%d\n", instruction++, $1->register_n);
		     }
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1462 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "=";}
#line 3092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1463 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "/=";}
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1464 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "<";}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1465 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "<=";}
#line 3110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1466 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = ">";}
#line 3116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1467 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = ">=";}
#line 3122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1470 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "+";}
#line 3128 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1471 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "-";}
#line 3134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1474 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "*";}
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1475 "ada.y" /* yacc.c:1646  */
    {(yyval.var) = "/";}
#line 3146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1479 "ada.y" /* yacc.c:1646  */
    {
	        record * rec = newRec();
		rec->value = (yyvsp[0].integer);
		rec->register_n = current_register;
		rec->is_reg = true;
		(yyval.rec)=rec;
		fprintf(output, "%d	r%d := %d\n",instruction++, current_register, (yyvsp[0].integer));
		current_register++;
		//printf("This is the offset %d\n", $$->offset);
		}
#line 3161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1489 "ada.y" /* yacc.c:1646  */
    {//look up local or do walk back find the node
	     node_t * current_node = searchAll(array, current_position, (yyvsp[0].var));//There should be a node in the tree since it added before 
	     record * rec = newRec();
	     if(strcmp(current_node->kind, "literal")==0){
		rec->value = current_node->value;
                rec->register_n = current_register;
                rec->is_reg = true;
                (yyval.rec)=rec;
                fprintf(output, "%d	r%d := %d\n",instruction++, current_register, current_node->value);
                current_register++;
	     }else{
	     	int numberWalk = searchInt(array, current_position, (yyvsp[0].var));
	     	if(numberWalk == 0){
			rec->offset = current_node->offset;
	     	}else{
			fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                	while(numberWalk > 0){
                     	   fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           numberWalk--;
                      	   }
		      int old_reg = current_register;
		      current_register++;
                      //fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                      rec->register_n = current_register;
		      rec->offset = current_node->offset;
                      rec->is_reg = true;
		      rec->is_walkback = true;
		      rec->walkback_n = old_reg;
		      current_register++;

	             }
	    }
	     (yyval.rec) = rec;
	    }
#line 3200 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1523 "ada.y" /* yacc.c:1646  */
    {(yyval.rec) = (yyvsp[-1].rec);}
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1524 "ada.y" /* yacc.c:1646  */
    {//access arrays of arrays
					      node_t * current_node = searchAll(array, current_position, (yyvsp[-6].var));
					      node_t * second_node = current_node->parent_Type->component_type;
                                	      record * rec = newRec();
                                	      if((yyvsp[-4].rec)->is_walkback){
                                   		 fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-4].rec)->register_n,(yyvsp[-4].rec)->walkback_n, (yyvsp[-4].rec)->offset);
                                 	       }
					      if((yyvsp[-1].rec)->is_walkback){
                                                 fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-4].rec)->register_n,(yyvsp[-4].rec)->walkback_n, (yyvsp[-4].rec)->offset);
                                               }
					      fprintf(output,"%d      r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
					     record * first_exp = newRec();
                                        record * second_exp = newRec();
                                        first_exp = (yyvsp[-1].rec);
                                        second_exp = (yyvsp[-4].rec);
                                        int lower_r = current_register;
                                        current_register++;
                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                        int upper_r = current_register;
                                        current_register++;
                                        if(!(yyvsp[-4].rec)->is_reg){
                                        fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, second_exp->offset);
                                        (yyvsp[-4].rec)->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,second_exp->register_n,
                                                                                         upper_r);
                                        int upper_comp = current_register;
                                         current_register++;
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                          second_exp->register_n);
                                        int lower_comp = current_register;
                                        current_register++;
                                        fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                        is_raise = 1;
                                        int i = instruction + 3;
                                        fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                        fprintf(output,"%d	r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d	pc := ?\n", instruction++);
                                        current_register++;

                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,second_node->lower);
                                        int lower_reg = current_register;
                                        current_register++; 
                                        fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,second_node->upper);
                                        int upper_reg = current_register;
                                        current_register++;
                                        if(!second_exp->is_reg){
                                        fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, first_exp->offset);
                                        second_exp->register_n = current_register;
                                        current_register++;
                                        }
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,first_exp->register_n,
                                                                                         upper_reg);
                                        int upper_comper = current_register;
                                         current_register++;
                                        fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_reg,
                                                                                          first_exp->register_n);
                                        int lower_comper = current_register;
                                        current_register++;
                                        fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comper, lower_comper);
                                        is_raise = 1;
                                        int in = instruction + 3;
                                        fprintf(output, "%d	pc := %d if r%d\n", instruction++,in, current_register);
                                        fprintf(output,"%d	r1 := 1\n", instruction++);
                                        //if there are no handlers need to jump to the base 
                                        add_toPatchExp(instruction);
                                        fprintf(output,"%d	pc := ?\n", instruction++);
                                        current_register++;
					      int space_1 = second_node->upper;
					      space_1 = space_1 - second_node->lower;
					      space_1++;
					      int low = current_node->parent_Type->lower;
					      //to find the offset I am taking the base offset then adding the two expressions onto it 
					      //int space_1 = second_node->upper - second_node->lower;
					      
					      int numberWalk = searchInt(array, current_position, (yyvsp[-6].var));
                                	      if(numberWalk == 0){
						fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
                                                int w = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
						int p = current_register;
						current_register++;
						fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
						int r = current_register;
						current_register++;
						fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, second_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset); 
						int s = current_register;
						current_register++;
                                   	       fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register, s);
                                                 rec->register_n = current_register;
                                                 rec->offset = current_node->real_off - second_node->lower;
                                                 rec->is_reg = true;
                                                 rec->is_walkback = true;
                                                 rec-> walkback_n = current_register;
                                                current_register++;
                                	      }else{
                                   		  fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                                  while(numberWalk > 0){
                                                     fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                      numberWalk--;
                                                  }
						int walk_reg = current_register;
						current_register++;
						fprintf(output, "%d	r%d := %d\n", instruction++, current_register, low);
						int w = current_register;
						current_register++;
                                                fprintf(output, "%d	r%d := %s%d - r%d\n", instruction++, current_register, second_exp->is_reg?"r":"contents b, ",
                                                                                                                         second_exp->is_reg?second_exp->register_n:second_exp->offset, w);
                                                int p = current_register;
                                                current_register++;
                                                fprintf(output,"%d	r%d := r%d * %d\n", instruction++, current_register, p, space_1);
						int r = current_register;
                                                current_register++;
                                                fprintf(output, "%d	r%d := r%d + %s%d\n", instruction++, current_register,r, first_exp->is_reg?"r":"contents b, ",
                                                                                                             first_exp->is_reg?first_exp->register_n:first_exp->offset);
						current_register++;
                                                fprintf(output, "%d     r%d := r%d + r%d\n", instruction++, current_register, current_register-1, walk_reg);
                                                int old_reg = current_register;
                                                current_register++;
                                   		//fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   		rec->register_n = current_register;
                                   		rec->offset = current_node->real_off - second_node->lower;
                                   		rec->is_reg = true;
                                   		rec->is_walkback = true;
                                   		rec->walkback_n = old_reg;
                                   		current_register++;
                                		}

					      (yyval.rec)= rec;
					     }
#line 3347 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1660 "ada.y" /* yacc.c:1646  */
    {node_t * current_node = searchAll(array, current_position, (yyvsp[-3].var));
				record * rec = newRec();
				if((yyvsp[-1].rec)->is_walkback){
                                   fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[-1].rec)->register_n,(yyvsp[-1].rec)->walkback_n, (yyvsp[-1].rec)->offset);
                                 }
				if(strcmp(current_node->parent_Type->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!(yyvsp[-1].rec)->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-1].rec)->offset);
                                      (yyvsp[-1].rec)->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         (yyvsp[-1].rec)->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         (yyvsp[-1].rec)->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
				    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
				    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
				int numberWalk = searchInt(array, current_position, (yyvsp[-3].var));
				if(numberWalk == 0){
				    fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register, (yyvsp[-1].rec)->is_reg?"r":"contents b, ",
                                                                                                             (yyvsp[-1].rec)->is_reg?(yyvsp[-1].rec)->register_n:(yyvsp[-1].rec)->offset);
				    rec->register_n = current_register;
                        	    rec->offset = current_node->offset;
				    rec->is_reg = true;
                      		    rec->is_walkback = true;
				    rec-> walkback_n = current_register;
				    current_register++;
				}else{
				   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                        		while(numberWalk > 0){
                           			fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           			numberWalk--;
                           		}
				   fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, (yyvsp[-1].rec)->register_n);
                      	  	   int old_reg = current_register;
                      		   current_register++;
                      		   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                      		   rec->register_n = current_register;
                      		   rec->offset = current_node->offset;
                      		   rec->is_reg = true;
                      		   rec->is_walkback = true;
                      		   rec->walkback_n = old_reg;
                      		   current_register++;
				}
				(yyval.rec) = rec;
		  }
#line 3417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1726 "ada.y" /* yacc.c:1646  */
    {node_t * current_node = searchAll(array, current_position, (yyvsp[-5].var));
                                record * rec = newRec();
				node_t * type_node;
                       //search the list to find the what is trying to be accessed 
                        int offset;
                        struct rec_l *head = current_node->recor_l;
                        while(head != NULL){
                           if(strcmp(head->name, (yyvsp[0].var))==0){
                                offset=head->offset;
                                type_node = searchAll(array, current_position, head->type);
                                break;
                           }
                           head = head->next;
                        }
	                

                                if((yyvsp[-3].rec)->is_walkback){
                                   fprintf(output, "%d  r%d := contents r%d, %d \n",  instruction++, (yyvsp[-3].rec)->register_n,(yyvsp[-3].rec)->walkback_n, (yyvsp[-3].rec)->offset);
                                 }
                                if(strcmp(current_node->parent_Type->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,current_node->parent_Type->upper);
                                    int upper_r = current_register;
                                    current_register++;
                                    if(!(yyvsp[-3].rec)->is_reg){
                                      fprintf(output,"%d	r%d := contents b, %d\n", instruction++, current_register, (yyvsp[-3].rec)->offset);
                                      (yyvsp[-3].rec)->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         (yyvsp[-3].rec)->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         (yyvsp[-3].rec)->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
                                    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
                                int numberWalk = searchInt(array, current_position, (yyvsp[-5].var));
                                if(numberWalk == 0){
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
				    int i = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++; 
				    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i,  (yyvsp[-3].rec)->is_reg?"r":"contents b, ",
                                                                                                             (yyvsp[-3].rec)->is_reg?(yyvsp[-3].rec)->register_n:(yyvsp[-3].rec)->offset);
				    int y = current_register;
				    current_register++;
				    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
				    int z = current_register;
				    fprintf(output, "%d	r%d := b + r%d\n", instruction++, current_register,z);
                                    rec->register_n = current_register;
                                    rec->offset = current_node->real_off;
                                    rec->is_reg = true;
                                    rec->is_walkback = true;
                                    rec-> walkback_n = current_register;
                                    current_register++;
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                        while(numberWalk > 0){
                                                fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                numberWalk--;
                                        }
				    int reg = current_register;
				    current_register++;
				   fprintf(output, "%d	r%d := %d\n", instruction++, current_register, current_node->parent_memory);
                                    int i = current_register;
                                    current_register++; 
                                    fprintf(output, "%d	r%d := %d\n", instruction++, current_register, offset);
                                    int f = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d * %s%d\n", instruction++, current_register,i,  (yyvsp[-3].rec)->is_reg?"r":"contents b, ",
                                                                                                             (yyvsp[-3].rec)->is_reg?(yyvsp[-3].rec)->register_n:(yyvsp[-3].rec)->offset);
                                    int y = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d := r%d + r%d\n", instruction++, current_register,f,y);
                                   fprintf(output, "%d	r%d := r%d + r%d\n",  instruction++, current_register, current_register, reg);
                                   int old_reg = current_register;
                                   current_register++;
                                   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   rec->register_n = current_register;
                                   rec->offset = current_node->real_off;
                                   rec->is_reg = true;
                                   rec->is_walkback = true;
                                   rec->walkback_n = old_reg;
                                   current_register++;
                                }
				rec->offset = rec->offset + offset;
                                (yyval.rec) = rec;


	  }
#line 3528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1832 "ada.y" /* yacc.c:1646  */
    {//used for records
		       node_t * current_node = searchAll(array, current_position, (yyvsp[-3].var));
		       record * rec = newRec();
			node_t * type_node;
			int numberWalk = searchInt(array, current_position, (yyvsp[-3].var));
		       //search the list to find the what is trying to be accessed 
			int offset;
			struct rec_l *head = current_node->recor_l;
                        while(head != NULL){
			   if(strcmp(head->name, (yyvsp[-1].var))==0){
			   	offset=head->offset;
				type_node = searchAll(array, current_position, head->type);
				break;
			   }	
                           head = head->next;
			}
			if((yyvsp[0].rec) != NULL){
			//for arrays
			if((yyvsp[0].rec)->is_walkback){
                           fprintf(output, "%d	r%d := contents r%d, %d \n",  instruction++, (yyvsp[0].rec)->register_n,(yyvsp[0].rec)->walkback_n, (yyvsp[0].rec)->offset);
                        }
			   if(strcmp(type_node->kind,"array")==0){
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->lower);
                                    int lower_r = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= %d\n", instruction++, current_register,type_node->upper);
                                    int upper_r = current_register;
                                    current_register++;
				    if(!(yyvsp[0].rec)->is_reg){
                                      fprintf(output,"%d      r%d := contents b, %d\n", instruction++, current_register, (yyvsp[0].rec)->offset);
                                      (yyvsp[0].rec)->register_n = current_register;
                                      current_register++;
                                    }
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register,
                                                                                         (yyvsp[0].rec)->register_n,
                                                                                         upper_r);
                                    int upper_comp = current_register;
                                    current_register++;
                                    fprintf(output,"%d	r%d:= r%d <= r%d\n", instruction++, current_register, lower_r,
                                                                                         (yyvsp[0].rec)->register_n);
                                    int lower_comp = current_register;
                                    current_register++;
                                    fprintf(output, "%d	r%d:= r%d and r%d\n", instruction++, current_register, upper_comp, lower_comp);
				    is_raise = 1;
                                    int i = instruction + 3;
                                    fprintf(output, "%d	pc := %d if r%d\n", instruction++,i, current_register);
                                    fprintf(output,"%d	r1 := 1\n", instruction++);
                                    //if there are no handlers need to jump to the base 
                                    add_toPatchExp(instruction);
                                    fprintf(output,"%d	pc := ?\n", instruction++);
                                    current_register++;
                                 }
                                if(numberWalk == 0){
                                    fprintf(output, "%d	r%d := b + %s%d\n", instruction++, current_register, (yyvsp[0].rec)->is_reg?"r":"contents b, ",
													     (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);
                                    rec->register_n = current_register;
                                    rec->offset = offset;
                                    rec->is_reg = true;
                                    rec->is_walkback = true;
                                    rec-> walkback_n = current_register;
                                    current_register++;
                                }else{
                                   fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                                        while(numberWalk > 0){
                                                fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                                                numberWalk--;
                                        }
                                   fprintf(output, "%d	r%d := r%d + %s%d\n",  instruction++, current_register, current_register, (yyvsp[0].rec)->is_reg?"r":"contents b, ",
                                                                                                                                 (yyvsp[0].rec)->is_reg?(yyvsp[0].rec)->register_n:(yyvsp[0].rec)->offset);
                                   int old_reg = current_register;
                                   current_register++;
                                   //fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                                   rec->register_n = current_register;
                                   rec->offset = offset;
                                   rec->is_reg = true;
                                   rec->is_walkback = true;
                                   rec->walkback_n = old_reg;
                                   current_register++;
                                }
			}else{
                	    if(numberWalk == 0){
                        	rec->offset = offset;
                	   }else{
                        	fprintf(output, "%d	r%d := b\n",  instruction++, current_register);
                        	while(numberWalk > 0){
                           	  fprintf(output, "%d	r%d := contents r%d, 2\n",  instruction++, current_register, current_register);
                           	  numberWalk--;
                           	}	
                      		int old_reg = current_register;
                      		current_register++;
                      		//fprintf(output, "%d     r%d := contents r%d, %d \n",  instruction++, current_register,old_reg, current_node->offset);
                     		rec->register_n = current_register;
                      		rec->offset = offset;
                      		rec->is_reg = true;
                      		rec->is_walkback = true;
                      		rec->walkback_n = old_reg;
                      		current_register++;
                            }
			  }
			  (yyval.rec) = rec;

		     }
#line 3635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1936 "ada.y" /* yacc.c:1646  */
    { (yyval.rec) = (yyvsp[-1].rec);}
#line 3641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1937 "ada.y" /* yacc.c:1646  */
    {(yyval.rec) = NULL;}
#line 3647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1940 "ada.y" /* yacc.c:1646  */
    { int u = instruction + exception_count -1;
						if(handler_done != 0){
						 insert_Patch(&patchList, exception_jump, instruction-1);
						 for(int i = 1; i < exception_count; i++){
							if(jump_table[i] == 0){
							  fprintf(output, "%d	pc: = %d\n", instruction++, u);
							}else{
                                                        fprintf(output, "%d	pc := %d\n", instruction++,jump_table[i]);
							}
                                                   } 
						
						}else{
						  if(is_raise != 0){
						  insert_Patch(&patchList, exception_jump, instruction-1);
						  for(int i = 1; i < exception_count; i++){
							if(jump_table[i] == 0){
							  if(jump_table[0] == 0){
								fprintf(output, "%d	pc := %d\n", instruction++, u);	
							  }else{
							  fprintf(output, "%d	pc := %d\n", instruction++, jump_table[0]);
							  }
							}else{
							  fprintf(output, "%d	pc := %d\n", instruction++,jump_table[i]);
						   	}
						    }
						 }
						}
						
						 struct link_toPatch *h = grab_toPatchExp();
                                                while (h != NULL){
                                                  insert_Patch(&patchList,h->value, instruction);
                                                  //printf("inserting into if %d ,", h->value);
                                                  h = h->next;
						}
						for(int i =0; i < 20; i++){
						   jump_table[i] = 0;
						}
						is_raise = 0;
						handler_done =0;
						return_except =0;
						pop_toPatchExp();
					      }
#line 3694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1982 "ada.y" /* yacc.c:1646  */
    {//if there is nothin
		 if(is_raise != 0){
		 struct link_toPatch *h = grab_toPatchExp();
                 while (h != NULL){
                     insert_Patch(&patchList,h->value, instruction);
                     //printf("inserting into if %d ,", h->value);
                     h = h->next;
                
		  }
		 }
		if(return_except != 0){
		insert_Patch(&patchList,return_except, instruction);
		}
		}
#line 3713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1998 "ada.y" /* yacc.c:1646  */
    {
                                 struct link_toPatch *h = grab_toPatchExp();
                                 int instruct = instruction+1;
                                    while (h != NULL){
                                        insert_Patch(&patchList,h->value, instruct);
                                        //printf("inserting into if %d ,", h->value);
                                         h = h->next;
                                     }
                               
			       pop_toPatchExp();
                               push_toPatchExp();
                               add_toPatchExp(instruction);
                               fprintf(output, "%d     pc := ?\n", instruction++);
                               exception_jump = instruction;
			       if(return_except != 0){
			          insert_Patch(&patchList,return_except, instruction);
			       }
                               fprintf(output, "%d     pc := r1, ?\n", instruction++);
			       is_raise = 1;
			   }
#line 3738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 2025 "ada.y" /* yacc.c:1646  */
    {//if(handler_done == 0){
	     fprintf(output, "%d	r1 := 0\n", instruction++);
	     add_toPatchExp(instruction);
	     fprintf(output, "%d	pc := ?\n", instruction++);
	    // }
	    }
#line 3749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 2033 "ada.y" /* yacc.c:1646  */
    {node_t * current_node = searchAll(array, current_position, (yyvsp[0].var));
		     (yyval.integer) = current_node->value;
		     jump_table[current_node->value] = instruction;
		     }
#line 3758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 2037 "ada.y" /* yacc.c:1646  */
    {(yyval.integer)= 1;
			  jump_table[0] = instruction;
			 }
#line 3766 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3770 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 2043 "ada.y" /* yacc.c:1906  */

int main()
{
	output = fopen("simple.out", "w");
	push(array, &current_position, "Outer Context");
 	addOuter(array, current_position);
	yyparse();
	fclose(output);
}
