#ifndef ACTION_H
#define ACTION_H 

#include "labelStack.h"
#include "symbolTable.h"

#define TEST                            printf("/************ Testing ************/\n");
#define TESTsymbol(symbol)              TEST; printf("%s\n", symbol.name); printf("%s\n", KindName[symbol.kind]); printf("%s\n", TypeName[symbol.type]);

#define TAB                             for (int i = 0; i < tabAmount; i++) { printf("\t"); }

#define returnStatement                 TAB; printf("return\n");
#define loadOutputFunction              TAB; printf("getstatic java.io.PrintStream java.lang.System.out\n");
#define loadInteger(integer)            if(scopeCurrent->kind != global) { TAB; printf("sipush %d\n", integer); }
#define loadString(string)              if(scopeCurrent->kind != global) { TAB; printf("ldc ""%s""\n", string); }  

extern int line;

extern SymbolTable* symbolTable;
extern Scope* scopeCurrent;

extern bool getScopeKind;
extern ScopeKind newScopeKind;

extern Symbol* parameterList;
extern int parameterListLength;
extern Symbol* argumentList;
extern int argumentListLength;

extern LabelStack* elseLabelStack;
extern LabelStack* endifLabelStack;

extern int tabAmount;
extern int labelAmount;
extern int localVariableAmount;

void start();
void end();
Symbol* declaration(Symbol symbol);
Symbol constantDeclaration(char* name, SymbolType type, Symbol expression);
Symbol variableDeclaration(char* name, SymbolType type, Symbol expression);
Symbol enterFunctionScope(char* name, SymbolType type);
void getParameter(char* name, SymbolType type);
void enterIfStatementScope(Symbol expression);
void enterElseStatementScope();
void exitFunctionScope(Symbol symbol);
void exitIfStatementScope();
void exitIfElseStatementScope();
void exitElseStatementScope();
void exitStatementScope();
void assignment(char* symbolName, Symbol expression);
void printStatement(Symbol symbol);
void printlnStatement(Symbol symbol);
void returnValueStatement(Symbol symbol);
Symbol functionInvocation(char* name);
void getArgument(Symbol symbol);
void checkComputable(Symbol symbol);
void checkLogicalOperation(Symbol symbol);
int getOperandValue(Symbol symbol);
Symbol or(Symbol left, Symbol right);
Symbol and(Symbol left, Symbol right);
Symbol less(Symbol left, Symbol right);
Symbol lessEqual(Symbol left, Symbol right);
Symbol equal(Symbol left, Symbol right);
Symbol greaterEqual(Symbol left, Symbol right);
Symbol greater(Symbol left, Symbol right);
Symbol notEqual(Symbol left, Symbol right);
Symbol plus(Symbol left, Symbol right);
Symbol minus(Symbol left, Symbol right);
Symbol multiply(Symbol left, Symbol right);
Symbol divide(Symbol left, Symbol right);
Symbol mod(Symbol left, Symbol right);
Symbol not(Symbol symbol);
Symbol neg(Symbol symbol);
Symbol loadIdentifier(char* name);
Symbol loadBoolean(bool value);

#endif