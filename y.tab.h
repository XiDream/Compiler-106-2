/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 31 "parser.y" /* yacc.c:1909  */

        Symbol symbol;

#line 194 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
