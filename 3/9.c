#include <stdio.h>

int main()
{
    int matrix[100][100];
    int m;
    int n;
    int nIndex = 0;
    int mIndex = 0;
    int matrixpass[110][110];
    int times;
    int p = 0; //matrix[p][p]: start point
    // input m, n
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // initialize k,l
    int k = m; //right edge
    int l = n; //lower edge

    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            matrixpass[i][j] = 0;
        }
    }

    for (times = 0; times < m * n;) {
        while (matrixpass[mIndex][nIndex] == 0 && nIndex <= l - 1) { //right
            printf("%d", matrix[mIndex][nIndex]);
            matrixpass[mIndex][nIndex] = 1;
            nIndex++;
            times++;
            if (times != m * n) {
                printf(" ");
            }
        }
        mIndex++;
        nIndex--;
        while (matrixpass[mIndex][nIndex] == 0 && mIndex <= k - 1) { //down
            printf("%d", matrix[mIndex][nIndex]);
            matrixpass[mIndex][nIndex] = 1;
            mIndex++;
            times++;
            if (times != m * n) {
                printf(" ");
            }
        }
        mIndex--;
        nIndex--;
        while (matrixpass[mIndex][nIndex] == 0 && nIndex >= p) { //left
            printf("%d", matrix[mIndex][nIndex]);
            matrixpass[mIndex][nIndex] = 1;
            nIndex--;
            times++;
            if (times != m * n) {
                printf(" ");
            }
        }
        mIndex--;
        nIndex++;
        while (matrixpass[mIndex][nIndex] == 0 && mIndex >= p + 1) { //up
            printf("%d", matrix[mIndex][nIndex]);
            matrixpass[mIndex][nIndex] = 1;
            mIndex--;
            times++;
            if (times != m * n) {
                printf(" ");
            }
        }
        mIndex++;
        nIndex++;

        k--;
        l--;
        p++;
    }

    return 0;
}
