#include "ZeroweBisekcja.h"
double bisekcja(double epsilon, double(*function)(double),double x0,double x1) {
	double x2 = (x0 + x1) / 2;
	while (fabs(function(x2)) > epsilon) {
		if (function(x0) * function(x2) < 0) {
			x1 = x2;
		}
		else {
			x0 = x1;
			x1 = x2;
		}
		x2 = (x1 + x0) / 2;
	}
	return x2;
}
