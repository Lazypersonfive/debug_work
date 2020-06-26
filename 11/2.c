#include <stdio.h>
#include <string.h>

int main()
{
    int arr[32] = { 0 };
    int bits[32];
    char input[500];
    char output[33];
    int i, j;
    int counter = 0;
    scanf("%s", input);

    while (input[counter] != '\0') {
        arr[(counter + 1) % 32] += (int)input[counter];
        counter++;
    }

    for (j = 0; j < 32; j++) {
        bits[j] = arr[31 - j] ^ (arr[j] << 1);
    }

    for (j = 0; j < 32; j++) {
        output[j] = (char)((bits[j] % 85) + 34);
        printf("%c", output[j]);
    }

    return 0;
}
