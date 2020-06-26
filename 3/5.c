#include <stdio.h>

int main()
{
    int matrix[100][100];
    int m;
    int n;

    scanf("%d%d", &m, &n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int start = 0, column = n, row = m;
    int count = 0;
    while (start < column && start < row && count < m * n) {
        for (int j = start; j < column; j++) {
            if (count >= m * n) {
                break;
            } else if (count == m * n - 1) {
                printf("%d", matrix[start][j]);
                count++;
                break;
            } else {
                printf("%d ", matrix[start][j]);
                count++;
            }
        }
        for (int i = start + 1; i < row; i++) {
            if (count >= m * n) {
                break;
            } else if (count == m * n - 1) {
                printf("%d", matrix[i][column - 1]);
                count++;
                break;
            } else {
                printf("%d ", matrix[i][column - 1]);
                count++;
            }
        }
        for (int j = column - 2; j >= start; j--) {
            if (count >= m * n) {
                break;
            } else if (count == m * n - 1) {
                printf("%d", matrix[row - 1][j]);
                count++;
                break;
            } else {
                printf("%d ", matrix[row - 1][j]);
                count++;
            }
        }
        for (int i = row - 2; i > start; i--) {
            if (count >= m * n) {
                break;
            } else if (count == m * n - 1) {
                printf("%d", matrix[i][start]);
                count++;
                break;
            } else {
                printf("%d ", matrix[i][start]);
                count++;
            }
        }
        start++;
        column--;
        row--;
    }

    return 0;
}
