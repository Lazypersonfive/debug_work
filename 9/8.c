#include <stdio.h>

long double factorial(int n)
{
    long double result = 1;
    int i;
    for (i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

long long C(int n, int m)
{
    long long result;
    result = (long long)(factorial(n) / (factorial(m) * factorial(n - m)));
    return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long i = 0;
    int x;
    int y;
    for (x = 0; x <= n / 2; x++) {
        for (y = 0; y <= n / 3; y++) {
            if (x * 2 + y * 3 == n) {
                i += C(x + y, x);
            }
        }
    }
    printf("%lld", i);
    return 0;
}
