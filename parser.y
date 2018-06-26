%{

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

%}

%union {
        Symbol symbol;
}

%token <symbol>         COMMA
                        COLON
                        SEMICOLON
                        LEFT_PARENTHESE
                        RIGHT_PARENTHESE
                        LEFT_SQUARE_PARENTHESE
                        RIGHT_SQUARE_PARENTHESE
                        LEFT_BRACKET
                        RIGHT_BRACKET

                        INCREMENT
                        DECREMENT
                        REMAINDER
                        NOT
                        ASSIGNMENT
                        RIGHT_ARROW
                        PLUS_ASSIGNMENT
                        MINUS_ASSIGNMENT
                        MULTIPLY_ASSIGNMENT
                        DIVIDE_ASSIGNMENT

                        BOOL
                        BREAK
                        CHAR
                        CONTINUE
                        DO
                        ELSE
                        ENUM
                        EXTERN
                        FALSE
                        FLOAT
                        FOR
                        FN
                        IF
                        IN
                        INT
                        LET
                        LOOP
                        MATCH
                        MUT
                        PRINT
                        PRINTLN
                        PUB
                        READ
                        RETURN
                        SELF
                        STATIC
                        STR
                        STRUCT
                        TRUE
                        USE
                        WHERE
                        WHILE

                        IDENTIFIER
                        INTEGER
                        STRING

%left                   OR
%left                   AND
%left                   LESS LESS_EQUAL EQUAL GREATER_EQUAL GREATER NOT_EQUAL
%left                   PLUS MINUS
%left                   MULTIPLY DIVIDE REMAINDER

%type <symbol>          declaration
                        constantDeclaration
                        variableDeclaration
                        type
                        functionDeclaration
                        parameterList
                        function
                        functionInvocation
                        assignment
                        expression
                        term
                        identifier 
                        boolean 
                        integer 
                        string 

%%   

program:                        declarations functions {
                                        if(DEBUG) {
                                                Trace("declarations functions", "program");
                                        } 
                                } 
|                       
                                functions {       
                                        if(DEBUG) {     
                                                Trace("functions", "program"); 
                                        }
                                }
;

declarations:                   declaration declarations {
                                        if(DEBUG) {
                                                Trace("declaration declarations", "declarations"); 
                                        }
                                }
|               
                                declaration { 
                                        if(DEBUG) {
                                                Trace("declaration", "declarations"); 
                                        }
                                }
;

declaration:                    constantDeclaration { 
                                        declaration($1);
                                        if(DEBUG) {
                                                Trace("constantDeclaration", "declaration");                                
                                        }        
                                }
| 
                                variableDeclaration { 
                                        declaration($1);
                                        if(DEBUG) {
                                                Trace("variableDeclaration", "declaration"); 
                                        }
                                }
;

constantDeclaration:            LET identifier ASSIGNMENT expression SEMICOLON { 
                                        $$ = constantDeclaration($2.name, unknown, $4);
                                        if(DEBUG) {
                                                Trace("let identifier = expression;", "constantDeclaration");
                                        }  
                                }
| 
                                LET identifier COLON type ASSIGNMENT expression SEMICOLON { 
                                        $$ = constantDeclaration($2.name, $4.type, $6);
                                        if(DEBUG) {
                                                Trace("let identifier : type = expression;", "constantDeclaration"); 
                                        }
                                }
;

variableDeclaration:            LET MUT identifier SEMICOLON { 
                                        Symbol expression;
                                        expression.kind == unknown;
                                        $$ = variableDeclaration($3.name, unknown, expression);
                                        if(DEBUG) {
                                                Trace("let mut identifier;", "variableDeclaration"); 
                                        }
                                }
| 
                                LET MUT identifier COLON type SEMICOLON { 
                                        Symbol expression;
                                        expression.kind == unknown;
                                        $$ = variableDeclaration($3.name, $5.type, expression);
                                        if(DEBUG) {
                                                Trace("let mut identifier : type;", "variableDeclaration"); 
                                        }
                                }
| 
                                LET MUT identifier ASSIGNMENT expression SEMICOLON { 
                                        $$ = variableDeclaration($3.name, unknown, $5);
                                        if(DEBUG) {
                                                Trace("let mut identifier = expression;", "variableDeclaration"); 
                                        }
                                }
| 
                                LET MUT identifier COLON type ASSIGNMENT expression SEMICOLON { 
                                        $$ = variableDeclaration($3.name, $5.type, $7);
                                        if(DEBUG) {
                                                Trace("let mut identifier : type = expression;", "variableDeclaration");
                                        }
                                }
;

type:                           BOOL { 
                                        $$.type = boolean;
                                        if(DEBUG) {
                                                Trace("bool", "type");
                                        }
                                }
| 
                                INT { 
                                        $$.type = integer;
                                        if(DEBUG) {
                                                Trace("int", "type");
                                        }   
                                }
|                               
                                STR { 
                                        $$.type = string;
                                        if(DEBUG) {
                                                Trace("str", "type");
                                        }   
                                }
;

functions:                      function functions { 
                                        if(DEBUG) {
                                                Trace("function functions", "functions"); 
                                        }
                                }
|
                                function {
                                        if(DEBUG) {
                                                Trace("function", "functions"); 
                                        }
                                }
;

function:                       functionDeclaration functionBody {
                                        exitFunctionScope($1);
                                        if(DEBUG) {
                                                Trace("functionDeclaration functionBody", "function");
                                                printf("/* delete the scope. */\n");
                                        }
                                }
;

functionDeclaration:            FN identifier LEFT_PARENTHESE RIGHT_PARENTHESE { 
                                        $$ = enterFunctionScope($2.name, voidFunction);
                                        if(DEBUG) {
                                                Trace("fn identifier()", "functionDeclaration"); 
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
|
                                FN identifier LEFT_PARENTHESE parameterList RIGHT_PARENTHESE { 
                                        $$ = enterFunctionScope($2.name, voidFunction);
                                        if(DEBUG) {
                                                Trace("fn identifier(parameterList)", "functionDeclaration");
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
| 
                                FN identifier LEFT_PARENTHESE RIGHT_PARENTHESE RIGHT_ARROW type { 
                                        $$ = enterFunctionScope($2.name, $6.type);
                                        if(DEBUG) {
                                                Trace("fn identifier() -> type", "functionDeclaration");
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
| 
                                FN identifier LEFT_PARENTHESE parameterList RIGHT_PARENTHESE RIGHT_ARROW type { 
                                        $$ = enterFunctionScope($2.name, $7.type);
                                        if(DEBUG) {
                                                Trace("fn identifier(parameterList) -> type", "functionDeclaration"); 
                                                printf("/* create a new function scope. */\n");
                                        }
                                }
;

parameterList:                  parameter COMMA parameterList { 
                                        if(DEBUG) {
                                                Trace("parameter, parameterList", "parameterList"); 
                                        }
                                }
|
                                parameter {
                                        if(DEBUG) {
                                                Trace("parameter", "parameterList"); 
                                        }
                                }
;

parameter:                      identifier COLON type { 
                                        getParameter($1.name, $3.type);
                                        if(DEBUG) {
                                                Trace("identifier : type", "parameterList");
                                        }
                                }
;

functionBody:                   block {
                                        if(DEBUG) {
                                                Trace("block", "functionBody"); 
                                        }
                                }
;

block:                          LEFT_BRACKET blockCodes RIGHT_BRACKET { 
                                        if(DEBUG) {
                                                Trace("{ blockCodes }", "block"); 
                                                printf("/* delete the scope. */\n");
                                        }
                                }
;

blockCodes:                     blockCode blockCodes { 
                                        if(DEBUG) {
                                                Trace("blockCode blockCodes", "blockCodes"); 
                                        }
                                }        
| 
                                blockCode { 
                                        if(DEBUG) {
                                                Trace("blockCode", "blockCodes"); 
                                        }
                                }
;

blockCode:                      declaration { 
                                        if(DEBUG) {
                                                Trace("declaration", "blockCode"); 
                                        }
                                }
| 
                                statement { 
                                        if(DEBUG) {
                                                Trace("statement", "blockCode"); 
                                        }
                                }
;

statement:                      assignment { 
                                        if(DEBUG) {
                                                Trace("assignment", "statement"); 
                                        }
                                }
| 
                                outputStatement { 
                                        if(DEBUG) {
                                                Trace("output", "statement");
                                        } 
                                }
| 
                                returnStatement { 
                                        if(DEBUG) {
                                                Trace("returnStatement", "statement"); 
                                        }
                                }
| 
                                conditionalStatement { 
                                        if(DEBUG) {
                                                Trace("conditionalStatement", "statement"); 
                                        }
                                }
| 
                                loopStatement { 
                                        if(DEBUG) {
                                                Trace("loopStatement", "statement"); 
                                        }
                                }
|                               
                                blockStatement { 
                                        if(DEBUG) {
                                                Trace("blockStatement", "statement"); 
                                        }
                                }
| 
                                functionInvocationStatement { 
                                        if(DEBUG) {
                                                Trace("functionInvocationStatement", "statement"); 
                                        }
                                }
;

assignment:                     identifier ASSIGNMENT expression SEMICOLON { 
                                        assignment($1.name, $3);
                                        if(DEBUG) {
                                                Trace("identifier = expression;", "assignment"); 
                                        }
                                }
;

outputStatement:                functionPrint expression SEMICOLON { 
                                        printStatement($2);
                                        if(DEBUG) { 
                                                Trace("functionPrint expression;", "outputStatement"); 
                                        }
                                }
|
                                functionPrintln expression SEMICOLON {
                                        printlnStatement($2); 
                                        if(DEBUG) { 
                                                Trace("functionPrintln expression;", "outputStatement"); 
                                        }
                                }
;

functionPrint:                  PRINT {
                                        loadOutputFunction;
                                        if(DEBUG) {
                                                Trace("print", "functionPrint");
                                        }
                                }
;

functionPrintln:                PRINTLN {
                                        loadOutputFunction;
                                        if(DEBUG) {
                                                Trace("println", "functionPrintln");
                                        }
                                }
;

returnStatement:                RETURN SEMICOLON { 
                                        returnStatement;
                                        if(DEBUG) {
                                                Trace("return;", "returnStatement"); 
                                        }
                                }
|
                                RETURN expression SEMICOLON {
                                        returnValueStatement($2); 
                                        if(DEBUG) {
                                                Trace("return expression;", "returnStatement"); 
                                        }
                                }
;

conditionalStatement:           ifStatement {
                                        exitIfStatementScope();
                                        if(DEBUG) {
                                                Trace("ifStatement", "conditionalStatement"); 
                                        }
                                }
|
                                ifStatement {
                                        exitIfElseStatementScope();
                                }
                                elseStatement {
                                        exitElseStatementScope();
                                        if(DEBUG) {
                                                Trace("ifStatement elseStatement", "conditionalStatement"); 
                                        }
                                }
;

ifStatement:                    IF LEFT_PARENTHESE expression RIGHT_PARENTHESE {
                                        enterIfStatementScope($3);
                                }
                                block {
                                        if(DEBUG) {
                                                Trace("if(expression) block", "ifStatement"); 
                                        }
                                }
;

elseStatement:                  ELSE {
                                        enterElseStatementScope();
                                }
                                block {
                                        if(DEBUG) {
                                                Trace("else block", "elseStatement"); 
                                        }
                                }
;

loopStatement:                  whileStatementStart LEFT_PARENTHESE expression RIGHT_PARENTHESE block { 
                                        if(DEBUG) {
                                                Trace("while(expression) block", "loopStatement"); 
                                        }
                                }
;

whileStatementStart:            WHILE {
                                        if(DEBUG) {
                                                printf("/* create a new whileStatement scope. */\n");
                                        }
                                }
;

blockStatement:                 blockStatementStart blockCodes RIGHT_BRACKET {
                                        if(DEBUG) {
                                                Trace("{ blockCodes }", "blockStatement");
                                        }
                                }
;

blockStatementStart:            LEFT_BRACKET {
                                        if(DEBUG) {
                                                printf("/* create a new blockStatement scope. */\n");
                                        }
                                }
;

functionInvocationStatement:    functionInvocation SEMICOLON { 
                                        if(DEBUG) {
                                                Trace("functionInvocation;", "functionInvocationStatement"); 
                                        }
                                }
;

functionInvocation:             identifier LEFT_PARENTHESE RIGHT_PARENTHESE { 
                                        $$ = functionInvocation($1.name);
                                        if(DEBUG) {
                                                Trace("identifier()", "functionInvocation"); 
                                        }
                                }
|
                                identifier LEFT_PARENTHESE argumentList RIGHT_PARENTHESE { 
                                        $$ = functionInvocation($1.name);
                                        if(DEBUG) {
                                                Trace("identifier(argumentList)", "functionInvocation"); 
                                        }
                                }
;

argumentList:                   expression COMMA argumentList { 
                                        getArgument($1);
                                        if(DEBUG) {
                                                Trace("expression, argumentList", "argumentList");
                                        } 
                                }
| 
                                expression { 
                                        getArgument($1);
                                        if(DEBUG) {
                                                Trace("expression", "argumentList");
                                        } 
                                }
;

expression:                     expression OR expression { 
                                        $$ = or($1, $3);
                                        if(DEBUG) {
                                                Trace("expression || expression", "expression"); 
                                        }
                                }
|                               
                                expression AND expression { 
                                        $$ = and($1, $3);
                                        if(DEBUG) {
                                                Trace("expression && expression", "expression");
                                        }
                                }
|
                                expression LESS expression { 
                                        $$ = less($1, $3);
                                        if(DEBUG) {
                                                Trace("expression < expression", "expression"); 
                                        }
                                }
|                               
                                expression LESS_EQUAL expression { 
                                        $$ = lessEqual($1, $3);
                                        if(DEBUG) {
                                                Trace("expression <= expression", "expression");
                                        }
                                }
| 
                                expression EQUAL expression {
                                        $$ = equal($1, $3);
                                        if(DEBUG) {
                                                Trace("expression == expression", "expression"); 
                                        }
                                }
| 
                                expression GREATER_EQUAL expression {
                                        $$ = greaterEqual($1, $3);
                                        if(DEBUG) {
                                                Trace("expression >= expression", "expression"); 
                                        }
                                }
| 
                                expression GREATER expression {
                                        $$ = greater($1, $3);
                                        if(DEBUG) {
                                                Trace("expression > expression", "expression"); 
                                        }
                                }
| 
                                expression NOT_EQUAL expression {
                                        $$ = notEqual($1, $3);
                                        if(DEBUG) {
                                                Trace("expression != expression", "expression"); 
                                        }
                                }
|
                                expression PLUS expression {
                                        $$ = plus($1, $3);
                                        if(DEBUG) {
                                                Trace("expression + expression", "expression"); 
                                        }
                                }
| 
                                expression MINUS expression {
                                        $$ = minus($1, $3);
                                        if(DEBUG) {
                                                Trace("expression - expression", "expression"); 
                                        }
                                }
| 
                                expression MULTIPLY expression {
                                        $$ = multiply($1, $3);
                                        if(DEBUG) {
                                                Trace("expression * expression", "expression"); 
                                        }
                                }
| 
                                expression DIVIDE expression {
                                        $$ = divide($1, $3);
                                        if(DEBUG) {
                                                Trace("expression / expression", "expression"); 
                                        }
                                }
|                               
                                expression REMAINDER expression {
                                        $$ = mod($1, $3);
                                        if(DEBUG) {
                                                Trace("expression % expression", "expression"); 
                                        }
                                }
| 
                                term {
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace("term", "expression"); 
                                        }
                                }
;

term:                           LEFT_PARENTHESE expression RIGHT_PARENTHESE { 
                                        $$ = $2;
                                        if(DEBUG) {
                                                Trace("(expression)", "term"); 
                                        }
                                }
| 
                                NOT term { 
                                        $$ = not($2);
                                        if(DEBUG) {
                                                Trace("!term", "term"); 
                                        }
                                }
| 
                                MINUS term { 
                                        $$ = neg($2);
                                        if(DEBUG) {
                                                Trace("-term", "term"); 
                                        }
                                }
| 
                                functionInvocation {
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace("functionInvocation", "term"); 
                                        }
                                }
| 
                                identifier { 
                                        $$ = loadIdentifier($1.name);
                                        if(DEBUG) {
                                                Trace("identifier", "term"); 
                                        }
                                }
| 
                                boolean { 
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace("boolean", "term"); 
                                        }
                                }
| 
                                integer { 
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace("integer", "term"); 
                                        }
                                }
| 
                                string { 
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace("string", "term"); 
                                        }
                                }
;

identifier:                     IDENTIFIER { 
                                        $$.name = $1.name;
                                        if(DEBUG) {
                                                Trace($1.name, "identifier"); 
                                        }
                                }
;

boolean:                        TRUE { 
                                        $$ = loadBoolean(true);
                                        if(DEBUG) {
                                                Trace("true", "boolean"); 
                                        }
                                }
| 
                                FALSE { 
                                        $$ = loadBoolean(false);
                                        if(DEBUG) {
                                                Trace("false", "boolean"); 
                                        }
                                }
;

integer:                        INTEGER { 
                                        loadInteger($1.object.value.integer);
                                        $$ = $1;
                                        if(DEBUG) {
                                                Trace(integerToString($1.object.constant.integer), "integer"); 
                                        }
                                }
;

string:                         STRING { 
                                        loadString($1.object.value.string);
                                        $$ = $1;
                                        if(DEBUG) { 
                                                Trace($1.object.constant.string, "string"); 
                                        }
                                }
;

%%

int yyerror(char* msg) {
    printf("%s\n", msg);
    exit(1);
}

int main() {
    start();
    yyparse();
    end();
}