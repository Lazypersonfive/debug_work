#include <stdio.h>

long long int fun(int n)
{
    if (n == 1)
        return 0;
    if (n == 2 || n == 3)
        return 1;
    else
        return fun(n - 2) + fun(n - 3);
}

int main()
{
    int n;

    scanf("%d", &n);
    printf("%lld", fun(n));

    return 0;
}
