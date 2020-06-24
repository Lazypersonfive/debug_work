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
	double left;
	double right;
	double mid;
	left = -20.0;
	right = 20.0;
	mid = (left + right) / 2;

	if (fabs(f(p, q, mid)) < EPSILON) {
		return mid;
	} else if ((f(p, q, mid) < 0 && f(p, q, left) > 0) || (f(p, q, mid) > 0 && f(p, q, left) < 0)) {
		
		while (fabs(f(p, q, mid)) >= EPSILON) {
			if ((f(p, q, mid) < 0 && f(p, q, left) > 0) || (f(p, q, mid) > 0 && f(p, q, left) < 0)) {
				right = mid;
				mid = (left + right) / 2;
			} else if ((f(p, q, mid) < 0 && f(p, q, right) > 0) || (f(p, q, mid) > 0 && f(p, q, right) < 0)) {
				left = mid;
				mid = (left + right) / 2;
			}
		}
		
		return mid;
	}
	else if ((f(p, q, mid) < 0 && f(p, q, right) > 0) || (f(p, q, mid) > 0 && f(p, q, right) < 0)) {
		while (fabs(f(p, q, mid)) >= EPSILON) {
			if ((f(p, q, mid) < 0 && f(p, q, left) > 0) || (f(p, q, mid) > 0 && f(p, q, left) < 0)) {
				right = mid;
				mid = (left + right) / 2;
			} else if ((f(p, q, mid) < 0 && f(p, q, right) > 0) || (f(p, q, mid) > 0 && f(p, q, right) < 0)) {
				left = mid;
				mid = (left + right) / 2;
			}
		}
		return mid;
	}
	return mid;
}

/* Calculate the value of p*x+q */
double f(int p, int q, double x)
{
	return p * x + q;
}