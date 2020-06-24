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
    double a, b, c;
    a = -20;
    b = 20;
    c = (a + b) / 2;

    while (fabs(f(p, q, c)) >= EPSILON) {
        if (f(p, q, a) * f(p, q, c) < 0) {
            b = c;
        } else {
            a = c;
        }
        c = (a + b) / 2.0;
    }
    return c;
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
    return p * x + q;
}