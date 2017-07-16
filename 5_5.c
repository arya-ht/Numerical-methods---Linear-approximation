#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <conio.h>

#pragma warning(disable:4996)

#define E  pow(10,-3)
#define ERROR 0.000001
#define MAXT 1.0

#define FD(t,u) (1/(E*u*u))
#define F(t,u) (1/(E*u*u))*t


double Newton(double,double);

int main() {
	double t=0.0, un = 1.0, dt = 0.01, un1, tempun1;

	for (t; t <= MAXT; t += dt) {
		un1 = Newton(t, un); + dt*FD(t, Newton(t, un));
		un1 = un + (dt / 2)*(FD(t, un)+FD(t,un1));

		un = un1;
		printf("dt = %lf\t t = %lf\t un1 = %lf\n", dt, t, un1);
	
	}

	// output is near 15.87
	system("pause");
	return 0;
}
double  Newton(double t, double u) {
	double  x1, f0, fd0, error;
Newton:
	f0 = F(t,u);
	fd0 = FD(t,u);
	x1 = u - (f0 / fd0);
	error = fabs((x1 - u) / x1);

	if (error < ERROR) {}
	else {
		u = x1;
		goto Newton;
	}
	return x1;
}