// Reverse Polish Notation (RPN) expression 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_op(const char *s) {
    return (strlen(s) == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    long long st[100000];
    int top = -1;

    char tok[64];
    for (int i = 0; i < n; i++) {
        if (scanf("%63s", tok) != 1) return 0;

        if (!is_op(tok)) {
            st[++top] = atoll(tok);
        } else {
            long long b = st[top--];
            long long a = st[top--];
            long long r = 0;

            if (tok[0] == '+') r = a + b;
            else if (tok[0] == '-') r = a - b;
            else if (tok[0] == '*') r = a * b;
            else if (tok[0] == '/') r = a / b;

            st[++top] = r;
        }
    }

    printf("%lld", st[top]);
    return 0;
}