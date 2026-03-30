#include <stdio.h>

int main() {
    int m, n, i, j;
    
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int sum = 0;

    // Input matrix
    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Diagonal sum
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("Sum of primary diagonal = %d", sum);

    return 0;
}