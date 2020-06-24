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

/*get the value you want to calculate */
double bisection(int p, int q, double (*func)(int, int, double))
{
    double left = -20;
    double right = 20;
    double mid;
    mid = (left + right) / 2;
    double c = func(p, q, mid);

    while (fabs(c) >= EPSILON) {
        if ((c * func(p, q, left)) > 0) {
            left = mid;
            mid = (left + right) / 2;
            c = func(p, q, mid);
        } else {
            right = mid;
            mid = (right + left) / 2;
            c = func(p, q, mid);
        }
    }

    return mid;
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
    return p * x + q;
}