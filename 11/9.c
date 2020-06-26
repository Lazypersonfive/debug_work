#include <stdio.h>
#include <string.h>

int main()
{
    char in[500];
    char out[33];
    char oneC;
    int oneInt;
    int i;
    int j;
    int k;
    int arr[32];
    int bits[32];

    scanf("%s", in);
    k = strlen(in);

    // initialize arr
    for (i = 0; i < 32; i++) {
        arr[i] = 0;
    }

    // assign arr
    for (i = 1; i <= k; i++) {
        oneC = in[i - 1];
        oneInt = (int)oneC;
        arr[i % 32] += oneInt;
    }

    // assign bits
    for (j = 0; j < 32; j++) {
        oneInt = arr[31 - j] ^ (arr[j] << 1);
        bits[j] = oneInt;
    }

    // get result string
    for (j = 0; j < 32; j++) {
        oneInt = (bits[j] % 85 + 34);
        oneC = (char)oneInt;
        out[j] = oneC;
    }
    out[32] = '\0';
    printf("%s", out);

    return 0;
}
