#include <stdio.h>

int main()
{
    int N; //the number of the total stairs
    scanf("%d", &N);
    int step[50]; //step[N]'s all methods
    step[0] = 0;
    step[1] = 0;
    step[2] = 1;
    step[3] = 1;
    for (int i = 4; i <= N; i++) {
        step[i] = step[i - 2] + step[i - 3];
    }
    printf("%d", step[N]);
    return 0;
}
