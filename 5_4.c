#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//#pragma warning(disable:4996)
// Created by Arya HajiTaheri
#define maxT 2
#define F(t,u) (pow(t,3)*u-1.5*u) // put your function here

double RK();
double heun();
double Euler();
double midpoint();
void print();

int main() {
	print();
	return 0;
}

void print() {
	printf("\nEuler: %lf\n\nMidpoint: %lf\n\nRunge-Kutta: %lf\n\nFourth-order Runge-Kutta: %lf\n\n", Euler(), midpoint(), RK(), heun());
	//system("pause");
}
double Euler() {
	double  t = 0.0, un = 1, tn = 0.0, dt = 0.01, un1;

	for (t = 0.0; t <= maxT; t += dt) {
		un1 = un + dt*F(t, un);
		un = un1;
	}
	return un1;
}
double midpoint() {
	double  t = 0.0, un = 1, tn = 0.0, dt = 0.01, un1;
	for (t = 0.0; t <= maxT + dt; t += dt) {
		un1 = un + dt*F(t + 0.5*dt, un + 0.5*dt*F(t, un));
		un = un1;
	}
	return un1;
}
double heun() {
	double  t = 0.0, un = 1, tn = 0.0, dt = 0.01, ustar, un1;

	for (t = 0.0; t <= maxT + dt; t += dt) {
		ustar = un + dt*F(t, un);
		un1 = un + (0.5*dt)*(F(t, un) + F(t, ustar));
		un = un1;
	}
	return un1;
}

double RK() {
	double  t = 0.0, un = 1, tn = 0.0, dt = 0.01, ustar, udstar, un1;

	for (t = 0.0; t <= maxT + dt; t += dt) {
		ustar = un + (dt*0.5)*F(t, un);
		udstar = un + dt*(2 * F(t + 0.5*dt, ustar) - F(t, un));
		un1 = un + (dt / 6)*(F(t, un) + 4 * F(t + 0.5*dt, ustar) + F(t + dt, udstar));
		un = un1;
	}
	return un1;
}