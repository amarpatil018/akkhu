#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char item;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        // If the character is an operand, add it to the postfix output
        if (isalnum(item)) {
            postfix[j++] = item;
        }
        // If the character is '(', push it to the stack
        else if (item == '(') {
            push(item);
        }
        // If the character is ')', pop and output from stack until '(' is found
        else if (item == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top != -1 && stack[top] == '(') {
                pop(); // Discard '('
            }
        }
        // An operator is encountered
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(item)) {
                postfix[j++] = pop();
            }
            push(item);
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter a valid Infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postnatal_placeholder = postfix);
    return 0;
}
