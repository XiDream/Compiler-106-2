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
#line 1 "parser.y" /* yacc.c:339  */


#include "action.h"

#define DEBUG                           0
#define SCOPE_GLOBAL                    0
#define SYMBOL_MAX_AMOUNT               256

#define Trace(this, next)               printf("/* %s reducing to %s. */\n", this, next);

SymbolTable* symbolTable;
Scope* scopeCurrent;

bool getScopeKind = false;
ScopeKind newScopeKind;

Symbol* parameterList = NULL;
int parameterListLength = 0;
Symbol* argumentList = NULL;
int argumentListLength = 0;

LabelStack* elseLabelStack;
LabelStack* endifLabelStack;

int tabAmount = 1;
int labelAmount = 0;
int localVariableAmount = 0;


#line 96 "y.tab.c" /* yacc.c:339  */

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
    COMMA = 258,
    COLON = 259,
    SEMICOLON = 260,
    LEFT_PARENTHESE = 261,
    RIGHT_PARENTHESE = 262,
    LEFT_SQUARE_PARENTHESE = 263,
    RIGHT_SQUARE_PARENTHESE = 264,
    LEFT_BRACKET = 265,
    RIGHT_BRACKET = 266,
    INCREMENT = 267,
    DECREMENT = 268,
    REMAINDER = 269,
    NOT = 270,
    ASSIGNMENT = 271,
    RIGHT_ARROW = 272,
    PLUS_ASSIGNMENT = 273,
    MINUS_ASSIGNMENT = 274,
    MULTIPLY_ASSIGNMENT = 275,
    DIVIDE_ASSIGNMENT = 276,
    BOOL = 277,
    BREAK = 278,
    CHAR = 279,
    CONTINUE = 280,
    DO = 281,
    ELSE = 282,
    ENUM = 283,
    EXTERN = 284,
    FALSE = 285,
    FLOAT = 286,
    FOR = 287,
    FN = 288,
    IF = 289,
    IN = 290,
    INT = 291,
    LET = 292,
    LOOP = 293,
    MATCH = 294,
    MUT = 295,
    PRINT = 296,
    PRINTLN = 297,
    PUB = 298,
    READ = 299,
    RETURN = 300,
    SELF = 301,
    STATIC = 302,
    STR = 303,
    STRUCT = 304,
    TRUE = 305,
    USE = 306,
    WHERE = 307,
    WHILE = 308,
    IDENTIFIER = 309,
    INTEGER = 310,
    STRING = 311,
    OR = 312,
    AND = 313,
    LESS = 314,
    LESS_EQUAL = 315,
    EQUAL = 316,
    GREATER_EQUAL = 317,
    GREATER = 318,
    NOT_EQUAL = 319,
    PLUS = 320,
    MINUS = 321,
    MULTIPLY = 322,
    DIVIDE = 323
  };
#endif
/* Tokens.  */
#define COMMA 258
#define COLON 259
#define SEMICOLON 260
#define LEFT_PARENTHESE 261
#define RIGHT_PARENTHESE 262
#define LEFT_SQUARE_PARENTHESE 263
#define RIGHT_SQUARE_PARENTHESE 264
#define LEFT_BRACKET 265
#define RIGHT_BRACKET 266
#define INCREMENT 267
#define DECREMENT 268
#define REMAINDER 269
#define NOT 270
#define ASSIGNMENT 271
#define RIGHT_ARROW 272
#define PLUS_ASSIGNMENT 273
#define MINUS_ASSIGNMENT 274
#define MULTIPLY_ASSIGNMENT 275
#define DIVIDE_ASSIGNMENT 276
#define BOOL 277
#define BREAK 278
#define CHAR 279
#define CONTINUE 280
#define DO 281
#define ELSE 282
#define ENUM 283
#define EXTERN 284
#define FALSE 285
#define FLOAT 286
#define FOR 287
#define FN 288
#define IF 289
#define IN 290
#define INT 291
#define LET 292
#define LOOP 293
#define MATCH 294
#define MUT 295
#define PRINT 296
#define PRINTLN 297
#define PUB 298
#define READ 299
#define RETURN 300
#define SELF 301
#define STATIC 302
#define STR 303
#define STRUCT 304
#define TRUE 305
#define USE 306
#define WHERE 307
#define WHILE 308
#define IDENTIFIER 309
#define INTEGER 310
#define STRING 311
#define OR 312
#define AND 313
#define LESS 314
#define LESS_EQUAL 315
#define EQUAL 316
#define GREATER_EQUAL 317
#define GREATER 318
#define NOT_EQUAL 319
#define PLUS 320
#define MINUS 321
#define MULTIPLY 322
#define DIVIDE 323

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 31 "parser.y" /* yacc.c:355  */

        Symbol symbol;

#line 276 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  161

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   117,   117,   123,   130,   136,   143,   150,   158,   165,
     173,   182,   191,   198,   206,   213,   220,   228,   234,   241,
     250,   258,   266,   274,   283,   289,   296,   304,   311,   319,
     325,   332,   338,   345,   351,   357,   363,   369,   375,   381,
     388,   396,   403,   411,   419,   427,   434,   442,   449,   449,
     460,   460,   470,   470,   480,   487,   494,   501,   508,   515,
     522,   530,   537,   545,   552,   559,   566,   573,   580,   587,
     594,   601,   608,   615,   622,   629,   636,   644,   651,   658,
     665,   672,   679,   686,   693,   701,   709,   716,   724,   733
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMA", "COLON", "SEMICOLON",
  "LEFT_PARENTHESE", "RIGHT_PARENTHESE", "LEFT_SQUARE_PARENTHESE",
  "RIGHT_SQUARE_PARENTHESE", "LEFT_BRACKET", "RIGHT_BRACKET", "INCREMENT",
  "DECREMENT", "REMAINDER", "NOT", "ASSIGNMENT", "RIGHT_ARROW",
  "PLUS_ASSIGNMENT", "MINUS_ASSIGNMENT", "MULTIPLY_ASSIGNMENT",
  "DIVIDE_ASSIGNMENT", "BOOL", "BREAK", "CHAR", "CONTINUE", "DO", "ELSE",
  "ENUM", "EXTERN", "FALSE", "FLOAT", "FOR", "FN", "IF", "IN", "INT",
  "LET", "LOOP", "MATCH", "MUT", "PRINT", "PRINTLN", "PUB", "READ",
  "RETURN", "SELF", "STATIC", "STR", "STRUCT", "TRUE", "USE", "WHERE",
  "WHILE", "IDENTIFIER", "INTEGER", "STRING", "OR", "AND", "LESS",
  "LESS_EQUAL", "EQUAL", "GREATER_EQUAL", "GREATER", "NOT_EQUAL", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "$accept", "program", "declarations",
  "declaration", "constantDeclaration", "variableDeclaration", "type",
  "functions", "function", "functionDeclaration", "parameterList",
  "parameter", "functionBody", "block", "blockCodes", "blockCode",
  "statement", "assignment", "outputStatement", "functionPrint",
  "functionPrintln", "returnStatement", "conditionalStatement", "$@1",
  "ifStatement", "$@2", "elseStatement", "$@3", "loopStatement",
  "whileStatementStart", "blockStatement", "blockStatementStart",
  "functionInvocationStatement", "functionInvocation", "argumentList",
  "expression", "term", "identifier", "boolean", "integer", "string", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323
};
# endif

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -49

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      34,   -45,   -32,    19,    -7,     8,  -108,  -108,  -108,    -7,
      18,  -108,    28,   -45,     0,  -108,  -108,  -108,  -108,   435,
    -108,  -108,     3,    16,   -19,   467,  -108,    40,  -108,  -108,
     437,  -108,  -108,    36,   435,  -108,  -108,  -108,   467,   467,
    -108,  -108,    32,  -108,    54,  -108,   435,  -108,    65,    27,
      71,    83,    86,    87,   -19,  -108,   467,  -108,  -108,  -108,
      76,   467,   467,  -108,  -108,  -108,  -108,   467,  -108,    82,
    -108,    88,  -108,  -108,  -108,   467,  -108,   113,  -108,  -108,
     146,   177,    66,   467,    89,  -108,   464,   467,   -19,    80,
     -45,   -19,     7,   210,   467,   336,  -108,  -108,  -108,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   467,
     467,   467,   367,  -108,  -108,  -108,  -108,  -108,   398,  -108,
    -108,    91,    49,   241,  -108,   -19,  -108,  -108,  -108,   467,
    -108,   274,  -108,  -108,   476,   486,   -12,   -12,   -12,   -12,
     -12,   -12,    -3,    -3,  -108,  -108,  -108,    18,    18,  -108,
     467,  -108,  -108,   305,  -108,    18,  -108,  -108,  -108,  -108,
    -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     5,     6,     7,     3,    18,
       0,    85,     0,     0,     0,     1,     2,     4,    17,     0,
      19,    27,     0,     0,     0,     0,    57,     0,    43,    44,
       0,    55,    31,     0,    30,    32,    33,    34,     0,     0,
      35,    36,    47,    37,     0,    38,     0,    39,     0,     0,
      20,     0,    25,     0,     0,    10,     0,    14,    15,    16,
       0,     0,     0,    87,    86,    88,    89,     0,    80,     0,
      76,    81,    82,    83,    84,     0,    45,     0,    28,    29,
       0,     0,     0,     0,     0,    58,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    78,    79,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,    41,    42,    52,    49,     0,    56,
      59,     0,    62,     0,    22,     0,    24,    26,    11,     0,
      12,     0,    77,    75,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    50,     0,     0,    60,
       0,    40,    23,     0,     9,     0,    53,    54,    61,    13,
      51
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,    94,    44,  -108,  -108,   -53,    57,  -108,  -108,
      11,  -108,  -108,  -107,    -9,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,  -108,
    -108,  -108,  -108,    -4,   -48,   -25,     6,     5,  -108,  -108,
    -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    32,     6,     7,    60,     8,     9,    10,
      51,    52,    20,    21,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    82,    42,   155,   117,   147,    43,    44,
      45,    46,    47,    68,   121,   122,    70,    71,    72,    73,
      74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      69,    92,    99,    57,    24,    77,    12,    14,    13,    11,
      50,    99,   128,    80,    81,    48,    25,    58,    23,    15,
      54,    55,    11,   129,    49,    79,     1,    53,    19,    59,
      48,    93,    56,    86,    22,   124,    95,    84,   127,    49,
     156,   157,    48,    87,     5,     2,    75,    78,   160,     5,
     112,    49,   150,   108,   109,   110,   111,    11,   118,   -48,
      83,    16,   123,    99,   110,   111,    18,     1,    96,   131,
      85,     2,   152,    97,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,    98,    88,    90,
      89,    91,    94,   116,    86,    53,    99,   125,   149,    17,
     119,   126,   158,     0,   153,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   113,     0,
       0,     0,     0,     0,     0,     0,     0,    99,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   114,     0,     0,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   115,     0,     0,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   130,     0,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   151,     0,     0,     0,
       0,     0,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   154,
       0,     0,     0,     0,     0,     0,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     159,     0,     0,     0,     0,     0,     0,     0,     0,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   132,     0,     0,     0,     0,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   146,     0,     0,     0,     0,     0,
       0,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   148,     0,     0,     0,     0,
       0,     0,    99,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,     0,     0,     0,
       0,     0,    76,    61,     0,    26,     0,     0,     0,     0,
       0,     0,    62,     0,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    63,     0,    27,
      61,   120,     2,    61,     0,     0,    28,    29,     0,    62,
      30,     0,    62,     0,     0,     0,     0,    64,    31,    11,
      99,    11,    65,    66,    63,     0,     0,    63,     0,     0,
      99,     0,     0,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    64,     0,     0,    64,    11,    65,
      66,    11,    65,    66,     0,     0,     0,     0,     0,     0,
      67,     0,     0,    67,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111
};

static const yytype_int16 yycheck[] =
{
      25,    54,    14,    22,     4,    30,     1,     2,    40,    54,
       7,    14,     5,    38,    39,    19,    16,    36,    13,     0,
       4,     5,    54,    16,    19,    34,    33,    22,    10,    48,
      34,    56,    16,     6,     6,    88,    61,    46,    91,    34,
     147,   148,    46,    16,     0,    37,     6,    11,   155,     5,
      75,    46,     3,    65,    66,    67,    68,    54,    83,    27,
       6,     4,    87,    14,    67,    68,     9,    33,    62,    94,
       5,    37,   125,    67,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,     5,    17,     3,
       7,     4,    16,    27,     6,    90,    14,    17,     7,     5,
      11,    90,   150,    -1,   129,    -1,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    14,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,     7,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    14,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    30,    -1,    34,
       6,     7,    37,     6,    -1,    -1,    41,    42,    -1,    15,
      45,    -1,    15,    -1,    -1,    -1,    -1,    50,    53,    54,
      14,    54,    55,    56,    30,    -1,    -1,    30,    -1,    -1,
      14,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    50,    54,    55,
      56,    54,    55,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    -1,    -1,    66,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    37,    70,    71,    72,    73,    74,    76,    77,
      78,    54,   106,    40,   106,     0,    76,    71,    76,    10,
      81,    82,     6,   106,     4,    16,    10,    34,    41,    42,
      45,    53,    72,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    93,    97,    98,    99,   100,   101,   102,   106,
       7,    79,    80,   106,     4,     5,    16,    22,    36,    48,
      75,     6,    15,    30,    50,    55,    56,    66,   102,   104,
     105,   106,   107,   108,   109,     6,     5,   104,    11,    83,
     104,   104,    92,     6,    83,     5,     6,    16,    17,     7,
       3,     4,    75,   104,    16,   104,   105,   105,     5,    14,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,   104,     5,     5,     5,    27,    95,   104,    11,
       7,   103,   104,   104,    75,    17,    79,    75,     5,    16,
       5,   104,     7,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,     7,    96,     7,     7,
       3,     5,    75,   104,     5,    94,    82,    82,   103,     5,
      82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    77,
      78,    78,    78,    78,    79,    79,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    85,    85,
      86,    87,    87,    88,    89,    90,    90,    91,    92,    91,
      94,    93,    96,    95,    97,    98,    99,   100,   101,   102,
     102,   103,   103,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   105,   105,   105,
     105,   105,   105,   105,   105,   106,   107,   107,   108,   109
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     5,     7,
       4,     6,     6,     8,     1,     1,     1,     2,     1,     2,
       4,     5,     6,     7,     3,     1,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     3,     1,     1,     2,     3,     1,     0,     3,
       0,     6,     0,     3,     5,     1,     3,     1,     2,     3,
       4,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 117 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("declarations functions", "program");
                                        } 
                                }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 123 "parser.y" /* yacc.c:1646  */
    {       
                                        if(DEBUG) {     
                                                Trace("functions", "program"); 
                                        }
                                }
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 130 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("declaration declarations", "declarations"); 
                                        }
                                }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 136 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("declaration", "declarations"); 
                                        }
                                }
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 143 "parser.y" /* yacc.c:1646  */
    { 
                                        declaration((yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("constantDeclaration", "declaration");                                
                                        }        
                                }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 150 "parser.y" /* yacc.c:1646  */
    { 
                                        declaration((yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("variableDeclaration", "declaration"); 
                                        }
                                }
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 158 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = constantDeclaration((yyvsp[-3].symbol).name, unknown, (yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("let identifier = expression;", "constantDeclaration");
                                        }  
                                }
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 165 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = constantDeclaration((yyvsp[-5].symbol).name, (yyvsp[-3].symbol).type, (yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("let identifier : type = expression;", "constantDeclaration"); 
                                        }
                                }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 173 "parser.y" /* yacc.c:1646  */
    { 
                                        Symbol expression;
                                        expression.kind == unknown;
                                        (yyval.symbol) = variableDeclaration((yyvsp[-1].symbol).name, unknown, expression);
                                        if(DEBUG) {
                                                Trace("let mut identifier;", "variableDeclaration"); 
                                        }
                                }
#line 1671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 182 "parser.y" /* yacc.c:1646  */
    { 
                                        Symbol expression;
                                        expression.kind == unknown;
                                        (yyval.symbol) = variableDeclaration((yyvsp[-3].symbol).name, (yyvsp[-1].symbol).type, expression);
                                        if(DEBUG) {
                                                Trace("let mut identifier : type;", "variableDeclaration"); 
                                        }
                                }
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 191 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = variableDeclaration((yyvsp[-3].symbol).name, unknown, (yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("let mut identifier = expression;", "variableDeclaration"); 
                                        }
                                }
#line 1695 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 198 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = variableDeclaration((yyvsp[-5].symbol).name, (yyvsp[-3].symbol).type, (yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("let mut identifier : type = expression;", "variableDeclaration");
                                        }
                                }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 206 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol).type = boolean;
                                        if(DEBUG) {
                                                Trace("bool", "type");
                                        }
                                }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 213 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol).type = integer;
                                        if(DEBUG) {
                                                Trace("int", "type");
                                        }   
                                }
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 220 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol).type = string;
                                        if(DEBUG) {
                                                Trace("str", "type");
                                        }   
                                }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 228 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("function functions", "functions"); 
                                        }
                                }
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 234 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("function", "functions"); 
                                        }
                                }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 241 "parser.y" /* yacc.c:1646  */
    {
                                        exitFunctionScope((yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("functionDeclaration functionBody", "function");
                                                printf("/* delete the scope. */\n");
                                        }
                                }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 250 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = enterFunctionScope((yyvsp[-2].symbol).name, voidFunction);
                                        if(DEBUG) {
                                                Trace("fn identifier()", "functionDeclaration"); 
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 258 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = enterFunctionScope((yyvsp[-3].symbol).name, voidFunction);
                                        if(DEBUG) {
                                                Trace("fn identifier(parameterList)", "functionDeclaration");
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 266 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = enterFunctionScope((yyvsp[-4].symbol).name, (yyvsp[0].symbol).type);
                                        if(DEBUG) {
                                                Trace("fn identifier() -> type", "functionDeclaration");
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 274 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = enterFunctionScope((yyvsp[-5].symbol).name, (yyvsp[0].symbol).type);
                                        if(DEBUG) {
                                                Trace("fn identifier(parameterList) -> type", "functionDeclaration"); 
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 283 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("parameter, parameterList", "parameterList"); 
                                        }
                                }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 289 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("parameter", "parameterList"); 
                                        }
                                }
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 296 "parser.y" /* yacc.c:1646  */
    { 
                                        getParameter((yyvsp[-2].symbol).name, (yyvsp[0].symbol).type);
                                        if(DEBUG) {
                                                Trace("identifier : type", "parameterList");
                                        }
                                }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("block", "functionBody"); 
                                        }
                                }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 311 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("{ blockCodes }", "block"); 
                                                printf("/* delete the scope. */\n");
                                        }
                                }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 319 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("blockCode blockCodes", "blockCodes"); 
                                        }
                                }
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 325 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("blockCode", "blockCodes"); 
                                        }
                                }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 332 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("declaration", "blockCode"); 
                                        }
                                }
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 338 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("statement", "blockCode"); 
                                        }
                                }
#line 1911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 345 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("assignment", "statement"); 
                                        }
                                }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 351 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("output", "statement");
                                        } 
                                }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 357 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("returnStatement", "statement"); 
                                        }
                                }
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 363 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("conditionalStatement", "statement"); 
                                        }
                                }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 369 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("loopStatement", "statement"); 
                                        }
                                }
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 375 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("blockStatement", "statement"); 
                                        }
                                }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 381 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("functionInvocationStatement", "statement"); 
                                        }
                                }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 388 "parser.y" /* yacc.c:1646  */
    { 
                                        assignment((yyvsp[-3].symbol).name, (yyvsp[-1].symbol));
                                        if(DEBUG) {
                                                Trace("identifier = expression;", "assignment"); 
                                        }
                                }
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 396 "parser.y" /* yacc.c:1646  */
    { 
                                        printStatement((yyvsp[-1].symbol));
                                        if(DEBUG) { 
                                                Trace("functionPrint expression;", "outputStatement"); 
                                        }
                                }
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 403 "parser.y" /* yacc.c:1646  */
    {
                                        printlnStatement((yyvsp[-1].symbol)); 
                                        if(DEBUG) { 
                                                Trace("functionPrintln expression;", "outputStatement"); 
                                        }
                                }
#line 2014 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 411 "parser.y" /* yacc.c:1646  */
    {
                                        loadOutputFunction;
                                        if(DEBUG) {
                                                Trace("print", "functionPrint");
                                        }
                                }
#line 2025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 419 "parser.y" /* yacc.c:1646  */
    {
                                        loadOutputFunction;
                                        if(DEBUG) {
                                                Trace("println", "functionPrintln");
                                        }
                                }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 427 "parser.y" /* yacc.c:1646  */
    { 
                                        returnStatement;
                                        if(DEBUG) {
                                                Trace("return;", "returnStatement"); 
                                        }
                                }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 434 "parser.y" /* yacc.c:1646  */
    {
                                        returnValueStatement((yyvsp[-1].symbol)); 
                                        if(DEBUG) {
                                                Trace("return expression;", "returnStatement"); 
                                        }
                                }
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 442 "parser.y" /* yacc.c:1646  */
    {
                                        exitIfStatementScope();
                                        if(DEBUG) {
                                                Trace("ifStatement", "conditionalStatement"); 
                                        }
                                }
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 449 "parser.y" /* yacc.c:1646  */
    {
                                        exitIfElseStatementScope();
                                }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 452 "parser.y" /* yacc.c:1646  */
    {
                                        exitElseStatementScope();
                                        if(DEBUG) {
                                                Trace("ifStatement elseStatement", "conditionalStatement"); 
                                        }
                                }
#line 2088 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 460 "parser.y" /* yacc.c:1646  */
    {
                                        enterIfStatementScope((yyvsp[-1].symbol));
                                }
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 463 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("if(expression) block", "ifStatement"); 
                                        }
                                }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 470 "parser.y" /* yacc.c:1646  */
    {
                                        enterElseStatementScope();
                                }
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 473 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("else block", "elseStatement"); 
                                        }
                                }
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 480 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("while(expression) block", "loopStatement"); 
                                        }
                                }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 487 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                printf("/* create a new whileStatement scope. */\n");
                                        }
                                }
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 494 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                Trace("{ blockCodes }", "blockStatement");
                                        }
                                }
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 501 "parser.y" /* yacc.c:1646  */
    {
                                        if(DEBUG) {
                                                printf("/* create a new blockStatement scope. */\n");
                                        }
                                }
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 508 "parser.y" /* yacc.c:1646  */
    { 
                                        if(DEBUG) {
                                                Trace("functionInvocation;", "functionInvocationStatement"); 
                                        }
                                }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 515 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = functionInvocation((yyvsp[-2].symbol).name);
                                        if(DEBUG) {
                                                Trace("identifier()", "functionInvocation"); 
                                        }
                                }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 522 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = functionInvocation((yyvsp[-3].symbol).name);
                                        if(DEBUG) {
                                                Trace("identifier(argumentList)", "functionInvocation"); 
                                        }
                                }
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 530 "parser.y" /* yacc.c:1646  */
    { 
                                        getArgument((yyvsp[-2].symbol));
                                        if(DEBUG) {
                                                Trace("expression, argumentList", "argumentList");
                                        } 
                                }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 537 "parser.y" /* yacc.c:1646  */
    { 
                                        getArgument((yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression", "argumentList");
                                        } 
                                }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 545 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = or((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression || expression", "expression"); 
                                        }
                                }
#line 2229 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 552 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = and((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression && expression", "expression");
                                        }
                                }
#line 2240 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 559 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = less((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression < expression", "expression"); 
                                        }
                                }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 566 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = lessEqual((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression <= expression", "expression");
                                        }
                                }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 573 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = equal((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression == expression", "expression"); 
                                        }
                                }
#line 2273 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 580 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = greaterEqual((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression >= expression", "expression"); 
                                        }
                                }
#line 2284 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 587 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = greater((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression > expression", "expression"); 
                                        }
                                }
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 594 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = notEqual((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression != expression", "expression"); 
                                        }
                                }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 601 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = plus((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression + expression", "expression"); 
                                        }
                                }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 608 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = minus((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression - expression", "expression"); 
                                        }
                                }
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 615 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = multiply((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression * expression", "expression"); 
                                        }
                                }
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 622 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = divide((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression / expression", "expression"); 
                                        }
                                }
#line 2350 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 629 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = mod((yyvsp[-2].symbol), (yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("expression % expression", "expression"); 
                                        }
                                }
#line 2361 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 636 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace("term", "expression"); 
                                        }
                                }
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 644 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = (yyvsp[-1].symbol);
                                        if(DEBUG) {
                                                Trace("(expression)", "term"); 
                                        }
                                }
#line 2383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 651 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = not((yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("!term", "term"); 
                                        }
                                }
#line 2394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 658 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = neg((yyvsp[0].symbol));
                                        if(DEBUG) {
                                                Trace("-term", "term"); 
                                        }
                                }
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 665 "parser.y" /* yacc.c:1646  */
    {
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace("functionInvocation", "term"); 
                                        }
                                }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 672 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = loadIdentifier((yyvsp[0].symbol).name);
                                        if(DEBUG) {
                                                Trace("identifier", "term"); 
                                        }
                                }
#line 2427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 679 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace("boolean", "term"); 
                                        }
                                }
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 686 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace("integer", "term"); 
                                        }
                                }
#line 2449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 693 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace("string", "term"); 
                                        }
                                }
#line 2460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 701 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol).name = (yyvsp[0].symbol).name;
                                        if(DEBUG) {
                                                Trace((yyvsp[0].symbol).name, "identifier"); 
                                        }
                                }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 709 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = loadBoolean(true);
                                        if(DEBUG) {
                                                Trace("true", "boolean"); 
                                        }
                                }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 716 "parser.y" /* yacc.c:1646  */
    { 
                                        (yyval.symbol) = loadBoolean(false);
                                        if(DEBUG) {
                                                Trace("false", "boolean"); 
                                        }
                                }
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 724 "parser.y" /* yacc.c:1646  */
    { 
                                        loadInteger((yyvsp[0].symbol).object.value.integer);
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) {
                                                Trace(integerToString((yyvsp[0].symbol).object.constant.integer), "integer"); 
                                        }
                                }
#line 2505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 733 "parser.y" /* yacc.c:1646  */
    { 
                                        loadString((yyvsp[0].symbol).object.value.string);
                                        (yyval.symbol) = (yyvsp[0].symbol);
                                        if(DEBUG) { 
                                                Trace((yyvsp[0].symbol).object.constant.string, "string"); 
                                        }
                                }
#line 2517 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2521 "y.tab.c" /* yacc.c:1646  */
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
#line 742 "parser.y" /* yacc.c:1906  */


int yyerror(char* msg) {
    printf("%s\n", msg);
    exit(1);
}

int main() {
    start();
    yyparse();
    end();
}
