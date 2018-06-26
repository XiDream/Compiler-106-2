#include "symbolTable.h"

char* integerToString(int integer) {
    char* string = (char*) malloc(sizeof(char) * TOKEN_MAX_LENG);
    sprintf(string, "%d", integer);
    return string;
}

char* realToString(double real) {
    char* string = (char*) malloc(sizeof(char) * TOKEN_MAX_LENG);
    sprintf(string, "%g", real);
    return string;
}

int getValueLength(Symbol symbol) {
        int trueLength = 4;
        int falseLength = 5;
        int globalLength = 8;
        int localLength = 6;
        int functionValueLength = 1;

        switch(symbol.kind) {
                case constant:
                        switch(symbol.type) {
                                case boolean:
                                        if(symbol.object.constant.boolean == true) {
                                                return trueLength;
                                        }
                                        else {
                                                return falseLength;
                                        }
                                case integer:
                                        return strlen(integerToString(symbol.object.constant.integer));
                                case string:
                                        return strlen(symbol.object.constant.string);
                        }
                case variable:
                        if(symbol.isGlobal) {
                                return strlen(symbol.name) + globalLength;
                        }              
                        else {
                                return strlen(integerToString(symbol.object.variable.id)) + localLength;
                        }
                case function:                 
                        return functionValueLength;
        }
}

Symbol* newSymbol(bool isGlobal, char* name, SymbolKind kind, SymbolType type, SymbolObject object, Scope* scope) {
        Symbol* newSymbol = malloc(sizeof(Symbol));
        newSymbol->isGlobal = isGlobal;
        newSymbol->name = strdup(name);
        newSymbol->kind = kind;
        newSymbol->type = type;
        newSymbol->object = object;
        newSymbol->scope = scope;
        return newSymbol;
}

void dumpSymbol(Symbol symbol) {
        printf("/* %s  ", symbol.name);
        if(symbol.isGlobal) {
                printf("global  ");
        }
        else {
                printf("local  ");
        }
        printf("%s  ", KindName[symbol.kind]);
        printf("%s  ", TypeName[symbol.type]);
        switch(symbol.kind) {
                case constant:
                        switch(symbol.type) {
                                case boolean:
                                        if(symbol.object.constant.boolean == true) {
                                                printf("true  ");
                                        }
                                        else {
                                                printf("false  ");
                                        }
                                        break;
                                case integer:
                                        printf("%d  ", symbol.object.constant.integer);
                                        break;
                                case string:
                                        printf("%s  ", symbol.object.constant.string);
                                        break;
                        }
                        break;
                case variable:
                        if(symbol.isGlobal) {
                                printf("example.%s  ", symbol.name);
                        }
                        else {
                                printf("local_%d  ", symbol.object.variable.id);
                        }
                        break;
                case function:
                        printf("X  ");
                        break;
        }
        printf("%s */\n", symbol.scope->name);
}

void dumpSymbolTypeSetting(Symbol symbol, int nameMaxLength, int fieldMaxLength, int valueMaxLength, int kindMaxLength, int typeMaxLength, int scopeMaxLength) {
        const int space = SPACE;
        const int globalFieldLength = 6;
        const int localFieldLength = 5;
        int fieldLength = symbol.isGlobal ? globalFieldLength : localFieldLength;

        int nameSpace = nameMaxLength - strlen(symbol.name) + space;
        int fieldSpace = fieldMaxLength - fieldLength + space;
        int valueSpace = valueMaxLength - getValueLength(symbol) + space;
        int kindSpace = kindMaxLength- strlen(KindName[symbol.kind]) + space;
        int typeSpace = typeMaxLength - strlen(TypeName[symbol.type]) + space;
        int scopeSpace = scopeMaxLength - strlen(symbol.scope->name);

        printf("/*  %s", symbol.name);
        while(nameSpace > 0) {
                printf(" ");
                nameSpace--;
        }

        if(symbol.isGlobal) {
                printf("global");
        }
        else {
                printf("local");
        }
        while(fieldSpace > 0) {
                printf(" ");
                fieldSpace--;
        }

        switch(symbol.kind) {
                case constant:
                        switch(symbol.type) {
                                case boolean:
                                        if(symbol.object.constant.boolean == true) {
                                                printf("true");
                                        }
                                        else {
                                                printf("false");
                                        }
                                        break;
                                case integer:
                                        printf("%d", symbol.object.constant.integer);
                                        break;
                                case string:
                                        printf("%s", symbol.object.constant.string);
                                        break;
                        }
                        break;
                case variable:
                        if(symbol.isGlobal) {
                                printf("example.%s", symbol.name);
                        }
                        else {
                                printf("local_%d", symbol.object.variable.id);
                        }
                        break;
                case function:
                        printf("X");
                        break;
        }
        while(valueSpace > 0) {
                printf(" ");
                valueSpace--;
        }

        printf("%s", KindName[symbol.kind]);
        while(kindSpace > 0) {
                printf(" ");
                kindSpace--;
        }

        printf("%s", TypeName[symbol.type]);
        while(typeSpace > 0) {
                printf(" ");
                typeSpace--;
        }

        printf("%s", symbol.scope->name);
        while(scopeSpace > 0) {
                printf(" ");
                scopeSpace--;
        }

        printf("  */\n");
}

char* getScopeName(Scope* parent, ScopeKind kind, char* name) {
        char* newName = malloc(sizeof(char) * NAME_MAX_LENG);
        if(parent) {        
                if(kind == functionScope) {
                        sprintf(newName, "%s%s%s%s%s", parent->name, " -> ", ScopeKindName[kind], "_", name);
                }
                else {
                        sprintf(newName, "%s%s%s", parent->name, " -> ", ScopeKindName[kind]);
                }
        }
        else {
                newName = strdup("global");
        }
        return newName;
}

Scope* newScope(char* name, ScopeKind kind, Scope* parent, int symbolMaxAmount) {
        Scope* newScope = (Scope*) malloc(sizeof(Scope));
        newScope->name = getScopeName(parent, kind, name);
        newScope->kind = kind;
        newScope->symbolAmount = 0;
        newScope->symbol = (Symbol*) malloc(sizeof(Symbol) * symbolMaxAmount);
        newScope->child = NULL;
        if(parent) {
                newScope->parent = parent;
                parent->child = newScope;
        }
        else {
                newScope->parent = NULL;
        }
        return newScope;
}

void deleteScope(Scope* scope) {
        if(scope->parent) {
                Scope* parent = scope->parent;
                parent->child = NULL;
        }
        free(scope->symbol);
        free(scope);
}

Scope* currentScope(Scope* start) {
        Scope* this = start; 
        while(this->child) {
                this = this->child;
        }
        return this;
}

SymbolTable* newSymbolTable() {
        SymbolTable* newSymbolTable = (SymbolTable*) malloc(sizeof(SymbolTable));
        newSymbolTable->scope = newScope("global", global, NULL, SYMBOL_MAX_AMOUNT);
        return newSymbolTable;
}

void deleteSymbolTable(SymbolTable* symbolTable) {
        free(symbolTable);
}

Symbol* lookupSymbol(SymbolTable* symbolTable, char* name) {
        Scope* this = currentScope(symbolTable->scope);
        while(this) {
                for(int i = 0; i < this->symbolAmount; i++) {
                        if(strcmp(this->symbol[i].name, name) == 0) {
                                return &(this->symbol[i]);
                        }
                }
                this = this->parent;
        }
        return NULL;
}

Symbol* lookupSymbolFromScope(Scope* scope, char* name) {
        for(int i = 0; i < scope->symbolAmount; i++) {
                if(strcmp(scope->symbol[i].name, name) == 0) {
                        return &(scope->symbol[i]);
                }
        }
        return NULL;
}

bool insertSymbol(SymbolTable* symbolTable, Symbol* symbol) {
        Scope* current = currentScope(symbolTable->scope);
        if(!lookupSymbolFromScope(current, symbol->name)) {
                current->symbol[current->symbolAmount++] = *symbol;
                return true;
        }
        return false;
}

void dumpSymbolTable(SymbolTable* symbolTable) {
        if(DUMP_TABLE) {
                const int space = SPACE;
                const int spaceAmount = 5;

                const int symbolTableTitleLength = 16;
                const int nameLength = 4;
                const int fieldLength = 5;
                const int valueLength = 5;
                const int kindLength = 4;
                const int typeLength = 4;
                const int scopeLength = 5;

                int nameMaxLength = nameLength;
                int fieldMaxLength = 6;
                int valueMaxLength = valueLength;
                int kindMaxLength = kindLength;
                int typeMaxLength = typeLength;
                int scopeMaxLength = scopeLength;

                Scope *temp = symbolTable->scope;
                while(temp) {
                        Symbol* symbol = temp->symbol;
                        for(int i = 0; i < temp->symbolAmount; i++) {
                                int nameLength = strlen(symbol[i].name);
                                if(nameLength > nameMaxLength) {
                                        nameMaxLength = nameLength;
                                }
                                int valueLength = getValueLength(symbol[i]);
                                if(valueLength > valueMaxLength) {
                                        valueMaxLength = valueLength;
                                }
                                int kindLength = strlen(KindName[symbol[i].kind]);
                                if(kindLength > kindMaxLength) {
                                        kindMaxLength = kindLength;
                                }
                                int typeLength = strlen(TypeName[symbol[i].type]);
                                if(typeLength > typeMaxLength) {
                                        typeMaxLength = typeLength;
                                }
                                int scopeLength = strlen(symbol[i].scope->name);
                                if(scopeLength > scopeMaxLength) {
                                        scopeMaxLength = scopeLength;
                                }
                        }
                        temp = temp->child;
                }

                int totalLength = nameMaxLength + fieldMaxLength + valueMaxLength + kindMaxLength +  typeMaxLength + scopeMaxLength + space * spaceAmount;

                printf("\n/*  ");
                for(int i = 0; i < totalLength; i++) {
                        printf("-");
                }
                printf("  */\n");
                printf("/*  < Symbol Table >");
                for(int i = 0; i < totalLength - symbolTableTitleLength; i++) {
                        printf(" ");
                }
                printf("  */\n/*  ");
                for(int i = 0; i < totalLength; i++) {
                        printf("-");
                }
                printf("  */\n");

                printf("/*  name");
                for(int i = 0; i < nameMaxLength + space - nameLength; i++) {
                        printf(" ");
                }

                printf("field");
                for(int i = 0; i < fieldMaxLength + space - fieldLength; i++) {
                        printf(" ");
                }

                printf("value");
                for(int i = 0; i < valueMaxLength + space - valueLength; i++) {
                        printf(" ");
                }

                printf("kind");
                for(int i = 0; i < kindMaxLength + space - kindLength; i++) {
                        printf(" ");
                }

                printf("type");
                for(int i = 0; i < typeMaxLength + space - typeLength; i++) {
                        printf(" ");
                }

                printf("scope");
                for(int i = 0; i < scopeMaxLength - scopeLength; i++) {
                        printf(" ");
                }

                printf("  */\n");
                printf("/*  ");
                for(int i = 0; i < totalLength; i++) {
                        printf("-");
                }
                printf("  */\n");

                Scope* current = currentScope(symbolTable->scope);
                Scope* this = current;
                while(this) {
                        for(int i = 0; i < this->symbolAmount; i++) {
                                dumpSymbolTypeSetting(this->symbol[i], nameMaxLength, fieldMaxLength, valueMaxLength, kindMaxLength, typeMaxLength, scopeMaxLength);
                        }
                        this = this->parent;
                }
                deleteScope(current);
                printf("/*  ");
                for(int i = 0; i < totalLength; i++) {
                        printf("-");
                }
                printf("  */\n\n");
        }
        else {
                deleteScope(currentScope(symbolTable->scope));
        }
}

bool checkMainFunction(SymbolTable* symbolTable) {
        Scope* global = symbolTable->scope;
        Symbol* symbol = global->symbol;
        for(int i = 0; i < global->symbolAmount; i++) {
                if(symbol[i].kind == function && strcmp(symbol[i].name, "main") == 0) {
                        return true;
                }
        }
        return false;
}