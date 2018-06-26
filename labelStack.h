#ifndef LABEL_STACK_H
#define LABEL_STACK_H

#include <stdio.h>
#include <stdlib.h>

#define LABEL_MAX_AMOUNT    256

#define LABEL_POP_ERROR     printf("/* error occurred in line %d: label stack pop error. */\n", line); exit(1);

extern int line;

typedef struct LabelStack LabelStack;

struct LabelStack {
    int top;
    int* label;
};

LabelStack* newLabelStack();
void deleteLabelStack(LabelStack* labelStack);
int getTopLabel(LabelStack* labelStack);
void pushLabel(LabelStack* labelStack, int label);
int popLabel(LabelStack* labelStack);

#endif