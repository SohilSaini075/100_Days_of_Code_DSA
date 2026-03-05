/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssoc(char op) {
    return op == '^';
}

int main() {
    char s[1005];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    int n = (int)strlen(s);
    if (n > 0 && s[n - 1] == '\n') s[n - 1] = '\0';

    char st[1005];
    int top = -1;

    for (int i = 0; s[i]; i++) {
        char c = s[i];
        if (c == ' ' || c == '\t') continue;

        if (isalnum((unsigned char)c)) {
            putchar(c);
        } else if (c == '(') {
            st[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && st[top] != '(') {
                putchar(st[top--]);
            }
            if (top >= 0 && st[top] == '(') top--;
        } else {
            while (top >= 0 && st[top] != '(') {
                char t = st[top];
                int p1 = prec(t), p2 = prec(c);
                if (p1 > p2 || (p1 == p2 && !isRightAssoc(c))) {
                    putchar(st[top--]);
                } else {
                    break;
                }
            }
            st[++top] = c;
        }
    }

    while (top >= 0) {
        if (st[top] != '(') putchar(st[top]);
        top--;
    }

    return 0;
}