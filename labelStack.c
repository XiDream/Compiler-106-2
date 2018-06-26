#include "labelStack.h"

LabelStack* newLabelStack() {
    LabelStack* labelStack = (LabelStack*) malloc(sizeof(LabelStack));
    labelStack->top = -1;
    labelStack->label = (int*) malloc(sizeof(int) * LABEL_MAX_AMOUNT);
    return labelStack;
}

void deleteLabelStack(LabelStack* labelStack) {
    free(labelStack->label);
    free(labelStack);
}

int getTopLabel(LabelStack* labelStack) {
    return labelStack->label[labelStack->top];
}

void pushLabel(LabelStack* labelStack, int label) {
    labelStack->label[++labelStack->top] = label;
}

int popLabel(LabelStack* labelStack) {
    if(labelStack->top == -1) {
        LABEL_POP_ERROR;
    }
    return labelStack->label[labelStack->top--];
}