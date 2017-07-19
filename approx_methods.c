#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <stdlib.h>
/*
 *created by Arya HajiTaheri
 */
#define CE 2.71828 // constant e
#define F(x) (pow(CE,-x)-x) // your function goes here
#define FD(x) ((-1*pow(CE,-x))-x) // your derivative goes here
#define E 0.0000001 // max error

double Newton();
double Bisection();

int main() {
	Newton();
	Bisection();
	return 0;
}
double  Newton() {
	double x0, x1, f0, fd0, error;
	printf("This program calculates roots by Newton-Raphson Method:");
	printf("\n\nComputing: F(x): 2.31*pow(10, -14)*( pow(x, -5) + (2 * L*L*x*2) - pow(L, 4)*x)\n");
	printf("\nEnter the initial value: ");
	scanf("%lf", &x0);
	printf("\n f(x0)\t\tfd(x0)\t\tx1\t\tError");
	printf("\n =============================================================");

Newton:
	f0 = F(x0);
	fd0 = FD(x0);
	x1 = x0 - (f0 / fd0);
	error = fabs((x1 - x0) / x1);

	if (error < E) {
		printf("\n =============================================================");
		printf("\n\n Approximate Root = %.7lf\n", fabs(x1));
	}
	else {
		printf("\n%.3lf\t\t%.3lf\t\t%.5lf\t\t%.4lf", F(x0), FD(x0), x1, error);
		x0 = x1;
		goto Newton;
	}
	printf("\n");
	system("pause");
	return x1;
}


double Bisection() {
	double x1, x2, x0;
	system("cls");
	printf("\nVAC: This program calculates roots by Bisection method:\n");
	printf("\nFunction used: F(x) C*( pow(x, -5) + (2 * L*L*x*2) - pow(L, 4)*x)\n\n");
	system("pause");
	system("cls");
	printf("\nInput Low and High boundries:\n");

	scanf("%lf%lf", &x1, &x2);

	double F1 = F(x1), F2 = F(x2), f0, e, root;

	if (F1*F2 > 0) { goto end; }											//saftey check

	printf("\n\n\tX1\t\t  X2\t\t  X0\t\tf(X0)\t\t  Error");
	printf("\n================================================================================");

begin:
	x0 = (x1 + x2) / 2;
	f0 = F(x0);
	printf("\n\t%f\t%f\t%f\t%f\t%f\n", x1, x2, x0, F(x0), fabs((x2 - x1) / x2));

	if (F1*f0 < 0) { x2 = x0; }
	else {
		x1 = x0;
		F1 = f0;
	}

	if (fabs((x2 - x1) / x2) < E) {
		root = (x1 + x2) / 2;
		printf("\n\n\tApproximate Root = %lf\n\n\n", root);
		goto end;
	}
	else { goto begin; }
end:
	system("pause");
	return 0;
}
