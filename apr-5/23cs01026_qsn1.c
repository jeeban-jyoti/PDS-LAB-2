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
void reverseString(char *str);

int main() {
    char input[MAX_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0';

    reverseString(input);
    printf("Reversed string: %s\n", input);

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

void reverseString(char *str) {
    Stack stack;
    stack.top = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        push(&stack, str[i]);
    }

    for (int i = 0; !isEmpty(&stack); i++) {
        str[i] = pop(&stack);
    }
}