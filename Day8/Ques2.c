// Power Of Two

#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;
    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    scanf("%d", &n);

    if (isPowerOfTwo(n))
        printf("true");
    else
        printf("false");

    return 0;
}