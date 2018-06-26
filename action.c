#include "action.h"

#define MainFunctionUndefined                               printf("\n/* error: main function is undefined. */"); exit(1);
#define MultipleDefinitions(name)                           printf("\n/* error occurred in line %d: multiple definitions of '%s' */", line, name); exit(1);
#define UndefinedError(name)                                printf("\n/* error occurred in line %d: '%s' is undefined. */", line, name); exit(1);
#define WrongUsage(name, kind)                              printf("\n/* error occurred in line %d: '%s' is not a %s. */", line, name, kind); exit(1);
#define ConditionalExpressionError                          printf("\n/* error occurred in line %d: conditional expression can't be converted to boolean value. /*\n", line); exit(1);
#define ReturnTypeError                                     printf("\n/* error occurred in line %d: the return value and the function type are incompatible. */", line); exit(1);
#define ExpressionTypeError(type)                           printf("\n/* error occurred in line %d: expression can't be converted to a %s. */", line, type); exit(1);
#define ExpressionComputeError                              printf("\n/* error occurred in line %d: some expression terms are not computable type. */", line); exit(1);
#define ExpressionDivisionError                             printf("\n/* error occurred in line %d: divisors cannot be zero. */", line); exit(1);
#define ExpressionLogicalOperationError                     WrongUsage("logical operand", "boolean value (0 or 1)");       
#define ExpressionInvocationError(name, object)             printf("\n/* error occurred in line %d: '%s' is not a computable %s type.*/", line, name, object); exit(1);
#define TooFewArgumentsError                                printf("\n/* error occurred in line %d: too few arguments in the function call. */", line); exit(1);
#define TooManyArgumentsError                               printf("\n/* error occurred in line %d: too many arguments in the function call. */", line); exit(1);
#define ArgumentsIncompatibleError                          printf("\n/* error occurred in line %d: the arguments and the parameters are incompatible types. */", line); exit(1);

#define VariableDeclarationError                            printf("\n/* error occurred in line %d: this compiler can't declare string variables. */", line); exit(1);
#define StoreError                                          printf("\n/* error occurred in line %d: this compiler only can store integer data to local variables. */", line); exit(1);

#define loadGlobalVariable(name)                            if(scopeCurrent->kind != global) { TAB; printf("getstatic int example.%s\n", name); }
#define loadLocalVariable(id)                               if(scopeCurrent->kind != global) { TAB; printf("iload %d\n", id); }
#define loadTrueValue                                       if(scopeCurrent->kind != global) { TAB; printf("iconst_1\n"); }
#define loadFalseValue                                      if(scopeCurrent->kind != global) { TAB; printf("iconst_0\n"); }

void start() {
    symbolTable = newSymbolTable();
    scopeCurrent = symbolTable->scope;
    elseLabelStack = newLabelStack();
    endifLabelStack = newLabelStack();
    printf("class example\n");
    printf("{\n");
}

void end() {
    if(!checkMainFunction(symbolTable)) {
        MainFunctionUndefined;
    }
    deleteLabelStack(elseLabelStack);
    deleteLabelStack(endifLabelStack);
    dumpSymbolTable(symbolTable);
    deleteSymbolTable(symbolTable);
    printf("}");
}

Symbol* declaration(Symbol symbol) {
    bool isGlobal = (scopeCurrent->kind == global) ? true : false;
    Symbol* declarationSymbol = newSymbol(isGlobal, symbol.name, symbol.kind, symbol.type, symbol.object, scopeCurrent);
    if(!insertSymbol(symbolTable, declarationSymbol)) {
        MultipleDefinitions(symbol.name);
    }
    if(isGlobal) {
        switch(symbol.kind) {
            case variable:
                switch(symbol.type) {
                    case boolean:
                        TAB; printf("field static boolean %s = %s\n", symbol.name, (symbol.object.variable.initial.boolean ? "true" : "false"));
                        break;
                    case integer:
                        TAB; printf("field static int %s = %d\n", symbol.name, symbol.object.variable.initial.integer);
                        break;
                }
                break;
            case function:
                if(strcmp(symbol.name, "main") == 0) {
                    TAB; printf("method public static void main(java.lang.String[])\n");
                    TAB; printf("max_stack 15\n");
                    TAB; printf("max_locals 15\n");
                    TAB; printf("{\n");
                    tabAmount++;
                }
                else {
                    TAB; printf("method public static %s %s", TypeName[symbol.type], symbol.name);
                    int functionParameters = symbol.object.function.parameterAmount;
                    if(functionParameters == 0) {
                        printf("()\n");
                    }
                    for(int i = 0; i < functionParameters; i++) {
                        if(i == 0) {
                            printf("(");
                        }
                        printf("%s", TypeName[symbol.object.function.parameter[i].type]);
                        if(i == symbol.object.function.parameterAmount - 1) {
                            printf(")\n");
                        }
                        else {
                            printf(", ");
                        }
                    }
                    TAB; printf("max_stack 15\n");
                    TAB; printf("max_locals 15\n");
                    TAB; printf("{\n");
                    tabAmount++;
                }
                break;
        }
    }
    else if(symbol.kind == variable) {
        if(symbol.type == string) {
            StoreError;
        }
        if(!symbol.object.variable.uninitialized) {
            TAB; printf("istore %d\n", symbol.object.variable.id);
        }
    }
    return declarationSymbol;
}

Symbol constantDeclaration(char* name, SymbolType type, Symbol expression) {
    if(expression.kind != value && expression.kind != constant) {
        ExpressionTypeError("constant value");
    }
    SymbolObject returnObject;
    if(type == unknown) {
        type = expression.type;
    }
    if(expression.type == type) {
        switch(type) {
            case boolean:
                switch(expression.kind) {
                    case value:
                        returnObject.constant.boolean = expression.object.value.boolean;
                        break;
                    case constant:
                        returnObject.constant.boolean = expression.object.constant.boolean;
                        break;
                }
                break;
            case integer:
                switch(expression.kind) {
                    case value:
                        returnObject.constant.integer = expression.object.value.integer;
                        break;
                    case constant:
                        returnObject.constant.integer = expression.object.constant.integer;
                        break;
                }
                break;
            case string:
                switch(expression.kind) {
                    case value:
                        returnObject.constant.string = strdup(expression.object.value.string);
                        break;
                    case constant:
                        returnObject.constant.string = strdup(expression.object.constant.string);
                        break;
                }
                break;
        }
    }
    else {
        switch(type) {
            case boolean:
                if(expression.type == integer) {
                    switch(expression.kind) {
                        case value:
                            if(expression.object.value.integer == 0) {
                                returnObject.constant.boolean = false;
                            }
                            else {
                                returnObject.constant.boolean = true;
                            }
                            break;
                        case constant:
                            if(expression.object.constant.integer == 0) {
                                returnObject.constant.boolean = false;
                            }
                            else {
                                returnObject.constant.boolean = true;
                            }
                            break;
                    }
                }
                else {
                    ExpressionTypeError(TypeName[boolean]);
                }
                break;
            case integer:
                if(expression.type == boolean) {
                    switch(expression.kind) {
                        case value:
                            if(expression.object.value.boolean == true) {
                                returnObject.constant.integer = 1;
                            }
                            else {
                                returnObject.constant.integer = 0;
                            }
                            break;
                        case constant:
                            if(expression.object.constant.boolean == true) {
                                returnObject.constant.integer = 1;
                            }
                            else {
                                returnObject.constant.integer = 0;
                            }
                            break;
                    }
                }
                else {
                    ExpressionTypeError(TypeName[integer]);
                }
                break;
            case string:
                ExpressionTypeError(TypeName[string]);
                break;
        }
    }
    Symbol returnSymbol;
    returnSymbol.name = name;
    returnSymbol.kind = constant;
    returnSymbol.type = type;
    returnSymbol.object = returnObject;
    return returnSymbol;
}

Symbol variableDeclaration(char* name, SymbolType type, Symbol expression) {
    SymbolObject returnObject;
    if(type == string) {
        VariableDeclarationError;
    }
    if(type == unknown) {
        if(expression.type == string) {
            VariableDeclarationError;
        }
        type = expression.type;
    }
    if(expression.type == unknown) {
        returnObject.variable.uninitialized = true;
    }
    else {
        returnObject.variable.uninitialized = false;
    }
    if(expression.type == type) {
        switch(type) {
            case boolean:
                switch(expression.kind) {
                    case value:
                        returnObject.variable.initial.boolean = expression.object.value.boolean;
                        break;
                    case constant:
                        returnObject.variable.initial.boolean = expression.object.constant.boolean;
                        break;
                }
                break;
            case integer:
                switch(expression.kind) {
                    case value:
                        returnObject.variable.initial.integer = expression.object.value.integer;
                        break;
                    case constant:
                        returnObject.variable.initial.integer = expression.object.constant.integer;
                        break;
                }
                break;
        }
    }
    else {
        switch(type) {
            case boolean:
                if(expression.type == integer) {
                    switch(expression.kind) {
                        case value:
                            if(expression.object.value.integer == 0) {
                                returnObject.variable.initial.boolean = false;
                            }
                            else {
                                returnObject.variable.initial.boolean = true;
                            }
                            break;
                        case constant:
                            if(expression.object.constant.integer == 0) {
                                returnObject.variable.initial.boolean = false;
                            }
                            else {
                                returnObject.variable.initial.boolean = true;
                            }
                            break;
                    }
                }
                else {
                    ExpressionTypeError(TypeName[boolean]);
                }
                break;
            case integer:
                if(expression.type == boolean) {
                    switch(expression.kind) {
                        case value:
                            if(expression.object.value.boolean == true) {
                                returnObject.variable.initial.integer = 1;
                            }
                            else {
                                returnObject.variable.initial.integer = 0;
                            }
                            break;
                        case constant:
                            if(expression.object.constant.boolean == true) {
                                returnObject.variable.initial.integer = 1;
                            }
                            else {
                                returnObject.variable.initial.integer = 0;
                            }
                            break;
                    }
                }
                else {
                    ExpressionTypeError(TypeName[integer]);
                }
                break;
        }
    }
    if(scopeCurrent->kind == global) {
        returnObject.variable.id = -1;
    }
    else {
        returnObject.variable.id = localVariableAmount++;
    }
    Symbol returnSymbol;
    returnSymbol.name = name;
    returnSymbol.kind = variable;
    returnSymbol.type = type;
    returnSymbol.object = returnObject;
    return returnSymbol;
}

Symbol enterFunctionScope(char* name, SymbolType type) {
    SymbolObject object;
    object.function.parameterAmount = parameterListLength;
    object.function.parameter = parameterList;
    Symbol newFunction;
    newFunction.name = name;
    newFunction.kind = function;
    newFunction.type = type;
    newFunction.object = object;
    Symbol* functionDeclaration = declaration(newFunction);
    scopeCurrent = newScope(name, functionScope, scopeCurrent, SYMBOL_MAX_AMOUNT);
    for(int i = 0; i < parameterListLength; i++) {
        functionDeclaration->object.function.parameter[i].scope = scopeCurrent;
        declaration(functionDeclaration->object.function.parameter[i]);
    }
    parameterList = NULL;
    parameterListLength = 0;
    return newFunction;
}

void getParameter(char* name, SymbolType type) {
    if(!parameterList) {
        parameterList = (Symbol*) malloc(sizeof(Symbol) * SYMBOL_MAX_AMOUNT);
    }
    Symbol symbol;
    symbol.name = name;
    symbol.kind = variable;
    symbol.type = type;
    symbol.object.variable.id = parameterListLength;
    symbol.object.variable.uninitialized = true;
    parameterList[parameterListLength++] = symbol;
}

void enterIfStatementScope(Symbol expression) {
    if(expression.type == string) {
        ConditionalExpressionError;
    }
    TAB; printf("ifeq L%d\n", labelAmount);
    pushLabel(elseLabelStack, labelAmount++);
    scopeCurrent = newScope("", ifStatement, scopeCurrent, SYMBOL_MAX_AMOUNT);
}

void enterElseStatementScope() {
    printf("L%d:\n", popLabel(elseLabelStack));
    scopeCurrent = newScope("", elseStatement, scopeCurrent, SYMBOL_MAX_AMOUNT);
}

void exitFunctionScope(Symbol symbol) {
    if(symbol.type == voidFunction) {
        returnStatement;
    }
    tabAmount--;
    TAB; printf("}\n");
    localVariableAmount = 0;
    scopeCurrent = scopeCurrent->parent;
    dumpSymbolTable(symbolTable);
}

void exitIfStatementScope() {
    printf("L%d:\n", popLabel(elseLabelStack));
    scopeCurrent = scopeCurrent->parent;
    dumpSymbolTable(symbolTable);
}

void exitIfElseStatementScope() {
    TAB; printf("goto L%d\n", labelAmount);
    pushLabel(endifLabelStack, labelAmount++);
    scopeCurrent = scopeCurrent->parent;
    dumpSymbolTable(symbolTable);
}

void exitElseStatementScope() {
    printf("L%d:\n", popLabel(endifLabelStack));
    scopeCurrent = scopeCurrent->parent;
    dumpSymbolTable(symbolTable);
}

void exitStatementScope() {
    if(scopeCurrent->kind == functionScope) {
        return;
    }
    scopeCurrent = scopeCurrent->parent;
    dumpSymbolTable(symbolTable);
}

void assignment(char* symbolName, Symbol expression) {
    Symbol* symbol = lookupSymbol(symbolTable, symbolName);
    if(!symbol) {
        UndefinedError(symbolName);
    }
    if(symbol->kind != variable) {
        WrongUsage(symbolName, KindName[variable]);
    }
    if(symbol->type == unknown) {
        symbol->type = expression.type;
    }
    if(symbol->isGlobal) {
        TAB; printf("putstatic %s example.%s\n", TypeName[symbol->type], symbol->name);
    }
    else {
        TAB; printf("istore %d\n", symbol->object.variable.id);
    }
}

void printStatement(Symbol symbol) {
    switch(symbol.type) {
        case boolean:
            TAB; printf("invokevirtual void java.io.PrintStream.print(boolean)\n");
            break;
        case integer:
            TAB; printf("invokevirtual void java.io.PrintStream.print(int)\n");
            break;
        case string:
            TAB; printf("invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
            break;
    }
}

void printlnStatement(Symbol symbol) {
    switch(symbol.type) {
        case boolean:
            TAB; printf("invokevirtual void java.io.PrintStream.println(boolean)\n");
            break;
        case integer:
            TAB; printf("invokevirtual void java.io.PrintStream.println(int)\n");
            break;
        case string:
            TAB; printf("invokevirtual void java.io.PrintStream.println(java.lang.String)\n");
            break;
    }
}

void returnValueStatement(Symbol symbol) {
    if(symbol.type != integer) {
        ReturnTypeError;
    }
    else {
        TAB; printf("ireturn\n");
    }
}

Symbol functionInvocation(char* name) {
    Symbol* symbol = lookupSymbol(symbolTable, name);
    if(!symbol) {
        UndefinedError(name);
    }
    if(symbol->kind != function) {
        WrongUsage(name, KindName[function]);
    }
    if(symbol->object.function.parameterAmount < argumentListLength) {
        TooFewArgumentsError;
    }
    if(symbol->object.function.parameterAmount > argumentListLength) {
        TooManyArgumentsError;
    }
    TAB; printf("invokestatic %s example.%s", TypeName[symbol->type], symbol->name);
    printf("(");
    for(int i = 0; i < argumentListLength; i++) {
        SymbolType parameterType = symbol->object.function.parameter[i].type;
        SymbolType argumentType = argumentList[i].type;
        if(parameterType == string && argumentType != string) {
            ArgumentsIncompatibleError;
        }
        else if(argumentType == string) {
            ArgumentsIncompatibleError;
        }
        else {
            printf("%s", TypeName[parameterType]);
            if(i != argumentListLength - 1) {
                printf(", ");
            }
            else {
                printf(")\n");
            }
        }
    }
    free(argumentList);
    argumentList = NULL;
    argumentListLength = 0;
    return *symbol;
}

void getArgument(Symbol symbol) {
    if(!argumentList) {
        argumentList = (Symbol*) malloc(sizeof(Symbol) * SYMBOL_MAX_AMOUNT);
    }
    argumentList[argumentListLength++] = symbol;
}

void checkComputable(Symbol symbol) {
    if(symbol.type == string) {
        if(symbol.kind == constant) {
            ExpressionInvocationError(symbol.name, KindName[constant]);
        }
        else if(symbol.kind == variable) {
            ExpressionInvocationError(symbol.name, KindName[variable]);
        }
        else if(symbol.kind == function) {
            ExpressionInvocationError(symbol.name, KindName[function]);
        }
        else {
            ExpressionComputeError;
        }
    }
}

int getOperandValue(Symbol symbol) {
    switch(symbol.kind) {
        case value:
            switch(symbol.type) {
                case boolean:
                    return symbol.object.value.boolean;
                case integer:
                    return symbol.object.value.integer;
            }
        case constant:
            switch(symbol.type) {
                case boolean:
                    return symbol.object.constant.boolean;
                case integer:
                    return symbol.object.constant.integer;
            }
    }
}

Symbol or(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) || getOperandValue(right);
    }
    TAB; printf("ior\n");
    return returnSymbol;
}

Symbol and(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) && getOperandValue(right);
    }
    TAB; printf("iand\n");
    return returnSymbol;
}

Symbol less(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) < getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("iflt L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol lessEqual(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) <= getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("ifle L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol equal(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) == getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("ifeq L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol greaterEqual(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) >= getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("ifge L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol greater(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) > getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("ifgt L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol notEqual(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.boolean = getOperandValue(left) != getOperandValue(right);
    }
    int trueLabel = labelAmount++;
    int nextStatementLabel = labelAmount++;
    TAB; printf("isub\n");
    TAB; printf("ifnq L%d\n", trueLabel);
    TAB; printf("iconst_0\n");
    TAB; printf("goto L%d\n", nextStatementLabel);
    printf("L%d:\n", trueLabel);
    TAB; printf("iconst_1\n");
    printf("L%d:\n", nextStatementLabel);
    return returnSymbol;
}

Symbol plus(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.integer = getOperandValue(left) + getOperandValue(right);
    }
    TAB; printf("iadd\n");
    return returnSymbol;
}

Symbol minus(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.integer = getOperandValue(left) - getOperandValue(right);
    }
    TAB; printf("isub\n");
    return returnSymbol;
}

Symbol multiply(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        returnSymbol.kind = value;
        returnSymbol.object.value.integer = getOperandValue(left) * getOperandValue(right);
    }
    TAB; printf("imul\n");
    return returnSymbol;
}

Symbol divide(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        if(getOperandValue(right) == 0) {
            ExpressionDivisionError;
        }
        returnSymbol.kind = value;
        returnSymbol.object.value.integer = getOperandValue(left) / getOperandValue(right);
    }
    TAB; printf("idiv\n");
    return returnSymbol;
}

Symbol mod(Symbol left, Symbol right) {
    checkComputable(left);
    checkComputable(right);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    if(left.kind == variable || right.kind == variable || left.kind == function || right.kind == function) {
        returnSymbol.kind = variable;
    }
    else {
        if(getOperandValue(right) == 0) {
            ExpressionDivisionError;
        }
        returnSymbol.kind = value;
        returnSymbol.object.value.integer = getOperandValue(left) % getOperandValue(right);
    }
    TAB; printf("irem\n");
    return returnSymbol;
}

Symbol not(Symbol symbol) {
    checkComputable(symbol);
    Symbol returnSymbol;
    returnSymbol.type = boolean;
    switch(symbol.kind) {
        case value:
        case constant:
            returnSymbol.kind = value;
            returnSymbol.object.value.boolean = !getOperandValue(symbol);
            break;
        case variable:
        case function:
            returnSymbol.kind = variable;
            break;
    }
    TAB; printf("sipush 1\n");
    TAB; printf("ixor\n");
    return returnSymbol;
}

Symbol neg(Symbol symbol) {
    checkComputable(symbol);
    Symbol returnSymbol;
    returnSymbol.type = integer;
    switch(symbol.kind) {
        case value:
        case constant:
            returnSymbol.kind = value;
            returnSymbol.object.value.integer = -getOperandValue(symbol);
            break;
        case variable:
        case function:
            returnSymbol.kind = variable;
            break;
    }
    TAB; printf("ineg\n");
    return returnSymbol;
}

Symbol loadIdentifier(char* name) {
    Symbol* symbol = lookupSymbol(symbolTable, name);
    if(!symbol) {
        UndefinedError(name);
    }
    switch(symbol->kind) {
        case constant:
            switch(symbol->type) {
                case boolean:
                    if(symbol->object.constant.boolean == true) {
                        loadTrueValue;
                    }
                    else {
                        loadFalseValue;
                    }
                    break;
                case integer:
                    loadInteger(symbol->object.constant.integer);
                    break;
                case string:
                    loadString(symbol->object.constant.string);
                    break;
            } 
            break;
        case variable:
            if(symbol->isGlobal) {
                loadGlobalVariable(symbol->name);
            }
            else {
                loadLocalVariable(symbol->object.variable.id);
            }
            break;
        case function:
            WrongUsage(symbol->name, "constant or variable");
            break;
    }
    return *symbol;
}

Symbol loadBoolean(bool value) {
    Symbol symbol;
    symbol.kind = value;
    symbol.type = boolean;
    symbol.object.value.boolean = value;
    if(value == true) {
        loadTrueValue;
    }
    else {
        loadFalseValue;
    }
    return symbol;
}