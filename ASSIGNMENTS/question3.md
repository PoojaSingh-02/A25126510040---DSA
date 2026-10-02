#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int precedence(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char x;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {

        // If operand, add to postfix
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }

        // If opening parenthesis
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        // If closing parenthesis
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop();   // Remove '('
        }

        // If operator
        else {
            while (top != -1 && stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(infix[i])) {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


<img width="562" height="157" alt="image" src="https://github.com/user-attachments/assets/9e42d0a8-e9e7-46ff-b22f-8064b399c3f2" />
