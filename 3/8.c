#include <stdio.h>

int main()
{
    int matrix[100][100];
    int m;
    int n;
    int i, j;
    int count = 0;
    int max;

    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (j < n - 1)
                scanf(" ");
        }
    }
    max = m * n;

    for (j = 0; j < n; j++) {
        printf("%d ", matrix[0][j]);
        count++;
    }

    do {
        int matrix_[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m - 1; j++) {
                matrix_[i][j] = matrix[j + 1][n - 1 - i];
            }
        }

        for (j = 0; j < m - 1; j++) {
            printf("%d", matrix_[0][j]);
            count++;
            if (count < max)
                printf(" ");
        }

        //cover original matrix with new matrix_
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                matrix[i][j] = matrix_[i][j];
            }
        }

        int t;
        t = m;
        m = n;
        n = t - 1;

    } while (m >= 1 && n >= 1);

    return 0;
}
