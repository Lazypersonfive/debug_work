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
    double right = 20.0, left = -20.0;
    double mid;

    while (1) {
        mid = (right + left) / 2;
        if (fabs(f(p, q, mid)) < EPSILON) {
            return mid;
        } else if ((f(p, q, right) * f(p, q, mid)) < 0) {
            left = mid;
        } else {
            right = mid;
        }
    }
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
    return p * x + q;
}
