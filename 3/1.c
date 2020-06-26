#include <stdio.h>

int main()
{
    int matrix[100][100];
    int m;
    int n;
    int i, j;
    int x = 0;
    int count = 0;
    int total;
    scanf("%d %d", &m, &n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    total = m * n;

    while (x < m && x < n && count < total) {
        for (j = x; j <= n - 1; j++) {
            if (count == total - 1) {
                printf("%d", matrix[x][j]);
                count++;
                break;
            } else {
                printf("%d ", matrix[x][j]);
                count++;
            }
        }
        for (i = x + 1; i <= m - 1; i++) {
            if (count >= total) {
                break;
            } else if (count == total - 1) {
                printf("%d", matrix[i][n - 1]);
                count++;
                break;
            } else {
                printf("%d ", matrix[i][n - 1]);
                count++;
            }
        }
        for (j = n - 2; j >= x; j--) {
            if (count >= total) {
                break;
            } else if (count == total - 1) {
                printf("%d", matrix[m - 1][j]);
                count++;
                break;
            } else {
                printf("%d ", matrix[m - 1][j]);
                count++;
            }
        }
        for (i = m - 2; i >= x + 1; i--) {
            if (count >= total) {
                break;
            } else if (count == total - 1) {
                printf("%d", matrix[i][x]);
                count++;
                break;
            } else {
                printf("%d ", matrix[i][x]);
                count++;
            }
        }
        x++;
        m--;
        n--;
    }

    return 0;
}
