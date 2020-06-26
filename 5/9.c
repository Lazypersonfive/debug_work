#include <stdio.h>
#include <string.h>
int main()
{
    int i, j;
    char name[10][21] = { 0 };
    for (i = 0, j = 0; i < 10; i++) {
        scanf("%s", name[i]);
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 9; j++) {
            if (strcmp(name[j], name[j + 1]) > 0) {
                char temp[21];
                strcpy(temp, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], temp);
            }
        }
    }

    for (i = 0, j = 0; i < 10; i++) {
        printf("%s\n", &name[i][j]);
    }

    return 0;
}
