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
    double a = -20.0;
    double b = 20.0;
    double x = 0.0;
    double fa, fb, fx;

    do
    {
        fa = f(p, q, a);
        fb = f(p, q, b);
        x = (a + b) / 2.0;
        fx = f(p, q, x);

        if ((fb > 0 && fx < 0) || (fb < 0 && fx > 0)) {
            a = x;
        } else {
            b = x;
        }
    } while (fabs(fx) >= EPSILON);

    return x;
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
    return p * x + q;
}