// Toeplitz Matrix

#include <stdio.h>
#include <stdbool.h>

bool isToeplitz(int matrix[][100], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int m = 3, n = 4;
    int matrix[100][100] = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {9, 5, 1, 2}
    };

    if (isToeplitz(matrix, m, n))
        printf("true");
    else
        printf("false");

    return 0;
}