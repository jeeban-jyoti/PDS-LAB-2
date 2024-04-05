#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void push(Stack *stack, char item);
char pop(Stack *stack);
int isEmpty(Stack *stack);
char* removeDuplicates(char *s);

int main() {
    char input[MAX_SIZE];

    printf("Enter the string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *result = removeDuplicates(input);
    printf("Final string after duplicate removals: %s\n", result);

    free(result);
    return 0;
}

void push(Stack *stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

char* removeDuplicates(char *s) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        if (!isEmpty(&stack) && s[i] == stack.data[stack.top]) {
            pop(&stack);
        } else {
            push(&stack, s[i]);
        }
    }

    char *result = (char*)malloc((stack.top + 2) * sizeof(char));
    int j = stack.top;
    for (int i = stack.top; i >= 0; i--) {
        result[i] = pop(&stack);
    }
    result[j + 1] = '\0';

    return result;
}