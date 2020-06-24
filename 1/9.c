#include <stdio.h>
#include <math.h>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);

int main()
{
    int p;
    int q;
    scanf("%d %d", &p, &q);
    printf("%.4f\n", bisection(p, q, f));
    return 0;
}

/* Calculate the value you want */
double bisection(int p, int q, double (*func)(int, int, double))
{
    double a = -20;
    double b = 20;

    while (fabs(f(p, q, (a + b) / 2)) >= EPSILON) {
        if (f(p, q, (a + b) / 2) * f(p, q, a) < 0) {
            b = (a + b) / 2;
        } else {
            a = (a + b) / 2;
        }
    }

    return (a + b) / 2;
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
    return p * x + q;
}