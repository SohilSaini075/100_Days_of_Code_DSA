// Set matrix zeroes

#include <stdio.h>

int main() {
    int m, n;
    
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int firstRowZero = 0, firstColZero = 0;

    for(int j = 0; j < n; j++) {
        if(matrix[0][j] == 0) {
            firstRowZero = 1;
            break;
        }
    }

    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) {
            firstColZero = 1;
            break;
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if(firstRowZero) {
        for(int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }

    if(firstColZero) {
        for(int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }

    printf("\nMatrix after setting zeroes:\n");
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}