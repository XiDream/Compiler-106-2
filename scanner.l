%{

#include <ctype.h>
#include "symbolTable.h"
#include "y.tab.h"

#define DEBUG                   0

#define tokenText               yytext
#define tokenLength             yyleng
#define tokenValue              yylval

#define MAX_SYMBOLS             256
#define MAX_LINE_LENG           256
#define MAX_KEYWORD_LENG        8

#define TAB                     for (int i = 0; i < tabAmount; i++) { printf("\t"); }
#define LIST                    strcat(buf, tokenText);
#define ERROR                   TAB; printf("/* error occurred in line %d: undefined token '%s'. */\n", line, tokenText); exit(1);
#define PRINT_CODE              if(1) { TAB; printf("/* line %d: %s */\n", line++, buf); } buf[0] = '\0';

#define tokenIs(s)              strcmp(tokenText, s) == 0
#define token(t)                printf("<%s>\n", t);
#define tokenMark(t)            printf("<'%s'>\n", t);
#define tokenType(type, t)      printf("<%s: %s>\n", type, t);

int tokenDelimiter();
int tokenOperator();
int tokenKeyword();
int tokenIdentifier();
int tokenInteger();
int tokenReal();
int tokenString();

extern int tabAmount;

int line = 1;
char buf[MAX_LINE_LENG];

%}

/* Not Using */
compound                "+="|"-="|"*="|"/="
notUsing                "++"|"--"|{compound}

/* Delimiter */
comma                   ","
colon                   ":"
semicolon               ";"
parentheses             "("|")"
squareBrackets          "["|"]"
brackets                "{"|"}"
Delimiter               {comma}|{colon}|{semicolon}|{parentheses}|{squareBrackets}|{brackets}

/* Operator */
arithmetic              "+"|"-"|"*"|"/"
remainder               "%"
relational              "<"|"<="|">="|">"|"=="|"!="
logical                 "&&"|"||"|"!"
assignment              "="
declaration             "->"
Operator                {arithmetic}|{remainder}|{relational}|{logical}|{assignment}|{declaration}

/* Keyword */
Keyword                 bool|break|char|continue|do|else|enum|extern|false|float|for|fn|if|in|int|let|loop|match|mut|print|println|pub|read|return|self|static|str|struct|true|use|where|while

/* Identifier */
letter                  [A-Za-z]
digits                  [0-9]+
Identifier              {letter}({digits}|{letter}|"_")*

/* Integer Constant */            
Integer                 {digits}

/* Real Constant                                */
/* plainReal               {digits}"."{digits}  */
/* exp                     [Ee][+-]?{digits}    */
/* Real                    {plainReal}{exp}?    */

/* String Constant */
quote                   \"
exceptQuote             [^\"]*
doubleQuote             {quote}{quote}
characters              ({exceptQuote}|{doubleQuote})*
String                  {quote}{characters}{quote}

/* Whitespace */
Whitespace              [ \t]*

/* Newline */
Newline                 \r?\n

/* One Line Comment */
slash                   \/
OneLineComment          {slash}{slash}[^(\r?\n)]*

/* More Lines Comment */
star                    "*"
BeginComment            {slash}{star}
%x IN_COMMENT
EndComment              {star}{slash}

%%

{Delimiter}                     { LIST; return tokenDelimiter(); }
{Operator}                      { LIST; return tokenOperator(); }
{Keyword}                       { LIST; return tokenKeyword(); }
{Identifier}                    { LIST; return tokenIdentifier(); }
{Integer}                       { LIST; return tokenInteger(); }
{String}                        { LIST; return tokenString(); }

{Newline}                       { PRINT_CODE; }
{Whitespace}                    { LIST; }
{OneLineComment}                { LIST; }

{BeginComment}                  { LIST; BEGIN(IN_COMMENT); }
<IN_COMMENT>{Newline}           { PRINT_CODE; }
<IN_COMMENT>.                   { LIST; }
<IN_COMMENT>{EndComment}        { LIST; BEGIN(0); }

.                               { ERROR; }

%%

int tokenDelimiter() {
        if(DEBUG) {
                tokenMark(tokenText);
        }
        if(tokenIs(","))            return COMMA;
        if(tokenIs(":"))            return COLON;
        if(tokenIs(";"))            return SEMICOLON;
        if(tokenIs("("))            return LEFT_PARENTHESE;
        if(tokenIs(")"))            return RIGHT_PARENTHESE;
        if(tokenIs("["))            return LEFT_SQUARE_PARENTHESE;
        if(tokenIs("]"))            return RIGHT_SQUARE_PARENTHESE;
        if(tokenIs("{"))            return LEFT_BRACKET;
        if(tokenIs("}"))            return RIGHT_BRACKET;
}

int tokenOperator() {
        if(DEBUG) {
                tokenMark(tokenText);
        }
        if(tokenIs("+"))            return PLUS;
        if(tokenIs("-"))            return MINUS;
        if(tokenIs("*"))            return MULTIPLY;
        if(tokenIs("/"))            return DIVIDE;
        if(tokenIs("++"))           return INCREMENT;
        if(tokenIs("--"))           return DECREMENT;
        if(tokenIs("%"))            return REMAINDER;
        if(tokenIs("<"))            return LESS;
        if(tokenIs("<="))           return LESS_EQUAL;
        if(tokenIs(">="))           return GREATER_EQUAL;
        if(tokenIs(">"))            return GREATER;
        if(tokenIs("=="))           return EQUAL;
        if(tokenIs("!="))           return NOT_EQUAL;
        if(tokenIs("&&"))           return AND;
        if(tokenIs("||"))           return OR;
        if(tokenIs("!"))            return NOT;
        if(tokenIs("="))            return ASSIGNMENT;
        if(tokenIs("->"))           return RIGHT_ARROW;
        if(tokenIs("+="))           return PLUS_ASSIGNMENT;
        if(tokenIs("-="))           return MINUS_ASSIGNMENT;
        if(tokenIs("*="))           return MULTIPLY_ASSIGNMENT;
        if(tokenIs("/="))           return DIVIDE_ASSIGNMENT;
}

int tokenKeyword() {
        if(DEBUG) {
                char* keyword = strdup(tokenText);
                for(int i = 0; i < tokenLength; i++) {
                        keyword[i] = toupper(keyword[i]);
                }
                token(keyword);
        }
        if(tokenIs("bool"))         return BOOL;
        if(tokenIs("break"))        return BREAK;
        if(tokenIs("char"))         return CHAR;
        if(tokenIs("continue"))     return CONTINUE;
        if(tokenIs("do"))           return DO;
        if(tokenIs("else"))         return ELSE;
        if(tokenIs("enum"))         return ENUM;
        if(tokenIs("extern"))       return EXTERN;
        if(tokenIs("false"))        return FALSE;
        if(tokenIs("float"))        return FLOAT;
        if(tokenIs("for"))          return FOR;
        if(tokenIs("fn"))           return FN;
        if(tokenIs("if"))           return IF;
        if(tokenIs("in"))           return IN;
        if(tokenIs("int"))          return INT;
        if(tokenIs("let"))          return LET;
        if(tokenIs("loop"))         return LOOP;
        if(tokenIs("match"))        return MATCH;
        if(tokenIs("mut"))          return MUT;
        if(tokenIs("print"))        return PRINT;
        if(tokenIs("println"))      return PRINTLN;
        if(tokenIs("pub"))          return PUB;
        if(tokenIs("read"))         return READ;
        if(tokenIs("return"))       return RETURN;
        if(tokenIs("self"))         return SELF;
        if(tokenIs("static"))       return STATIC;
        if(tokenIs("str"))          return STR;
        if(tokenIs("struct"))       return STRUCT;
        if(tokenIs("true"))         return TRUE;
        if(tokenIs("use"))          return USE;
        if(tokenIs("where"))        return WHERE;
        if(tokenIs("while"))        return WHILE;
}

int tokenIdentifier() {
        if(DEBUG) {
                tokenType("identifier", tokenText);
        }  
        tokenValue.symbol.name = strdup(tokenText);
        return IDENTIFIER;
}

int tokenInteger() {
        if(DEBUG) {
                tokenType("integer", tokenText);
        }  
        tokenValue.symbol.kind = value;
        tokenValue.symbol.type = integer;
        tokenValue.symbol.object.value.integer = atoi(tokenText);
        return INTEGER;
}

int tokenString() {
        if(DEBUG) {
                tokenType("string", tokenText);
        }  
        tokenValue.symbol.kind = value;
        tokenValue.symbol.type = string;
        tokenValue.symbol.object.value.string = strdup(tokenText);
        return STRING;
}