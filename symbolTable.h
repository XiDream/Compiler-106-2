#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DUMP_TABLE          1

#define SPACE               4
#define TOKEN_MAX_LENG      256
#define NAME_MAX_LENG       256
#define KIND_MAX_LENG       8
#define TYPE_MAX_LENG       7
#define SYMBOL_MAX_AMOUNT   256
#define SCOPE_MAX_AMOUNT    256
#define GLOBAL              0

static const char* KindName[] = { "value", "constant", "variable", "function", "none" };
static const char* TypeName[] = { "boolean", "int", "string", "void" };
static const char* ScopeKindName[] = { "global", "function", "if", "else", "while", "block" };

typedef union Value Value;
typedef union Constant Constant;
typedef struct Variable Variable;
typedef struct Function Function;

typedef struct Symbol Symbol;
typedef enum { value, constant, variable, function, none } SymbolKind;
typedef enum { boolean, integer, string, voidFunction, unknown } SymbolType;
typedef union SymbolObject SymbolObject;

typedef struct Scope Scope;
typedef enum { global, functionScope, ifStatement, elseStatement, whileStatement, blockStatement } ScopeKind;

typedef struct SymbolTable SymbolTable;

union Value {
    bool boolean;
    int integer;
    char* string;
};

union Constant {
    bool boolean;
    int integer;
    char* string;
};

struct Variable {
    int id;
    Value initial;
    bool uninitialized;
};

struct Function {
    int parameterAmount;
    Symbol* parameter;
};

union SymbolObject {
    Value value;
    Constant constant;
    Variable variable;
    Function function;
}; 

struct Symbol {
    bool isGlobal;
    char* name;
    SymbolKind kind;
    SymbolType type;
    SymbolObject object;
    Scope* scope;
};

struct Scope {
    char* name;
    ScopeKind kind;
    int symbolAmount;
    Symbol* symbol;
    Scope* child;
    Scope* parent;
};

struct SymbolTable {
    Scope* scope;
};

char* integerToString(int integer);
char* realToString(double real);

int getValueLength(Symbol symbol);

Symbol* newSymbol(bool isGlobal, char* name, SymbolKind kind, SymbolType type, SymbolObject object, Scope* scope);
void dumpSymbol(Symbol symbol);
void dumpSymbolTypeSetting(Symbol symbol, int nameMaxLength, int fieldMaxLength, int valueMaxLength, int kindMaxLength, int typeMaxLength, int scopeMaxLength);

char* getScopeName(Scope* parent, ScopeKind kind, char* name);
Scope* newScope(char* name, ScopeKind kind, Scope* parent, int symbolMaxAmount);
void deleteScope(Scope* scope);
Scope* currentScope(Scope* start);

SymbolTable* newSymbolTable();
void deleteSymbolTable(SymbolTable* symbolTable);
Symbol* lookupSymbol(SymbolTable* symbolTable, char* name);
Symbol* lookupSymbolFromScope(Scope* scope, char* name);
bool insertSymbol(SymbolTable* symbolTable, Symbol* symbol);
void dumpSymbolTable(SymbolTable* symbolTable);
bool checkMainFunction(SymbolTable* symbolTable);

#endif