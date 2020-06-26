#include <stdio.h>
#include <string.h>

int main()
{
    int arr[32];
    char str[500];
    int bits[32];
    char result[32];
    scanf("%s", str);
    int j = 0;

    for (int i = 0; i < 32; i++) {
        arr[i] = 0;
    }

    while (str[j] != '\0') {
        if (str[j] == '\n') {
            break;
        }
        arr[(j + 1) % 32] = arr[(j + 1) % 32] + (int)(str[j]);
        j++;
    }

    for (int i = 0; i < 32; i++) {
        bits[i] = (arr[31 - i]) ^ (arr[i] << 1);
        int b = (bits[i] % 85) + 34;
        result[i] = (char)b;
    }

    for (int i = 0; i < 32; i++) {
        printf("%c", result[i]);
    }

    return 0;
}
