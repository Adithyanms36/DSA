#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = c;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char ch;

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();
            pop(); // remove '('
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';
}

int evaluatePostfix(char postfix[]) {
    int evalStack[MAX];
    int evalTop = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            evalStack[++evalTop] = ch - '0';
        } else {
            int val2 = evalStack[evalTop--];
            int val1 = evalStack[evalTop--];
            switch (ch) {
                case '+': evalStack[++evalTop] = val1 + val2; break;
                case '-': evalStack[++evalTop] = val1 - val2; break;
                case '*': evalStack[++evalTop] = val1 * val2; break;
                case '/': evalStack[++evalTop] = val1 / val2; break;
                case '^': evalStack[++evalTop] = pow(val1, val2); break;
            }
        }
    }
    return evalStack[evalTop];
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;

    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Convert Infix to Postfix\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix expression: %s\n", postfix);
                break;

            case 2:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                printf("Result: %d\n", evaluatePostfix(postfix));
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
