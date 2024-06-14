#include "kwadratura_gausa_Lagrande.h"
#include "Horner.h"
double kwadraturaGaussLagradne(double(*function)(double), double a, double b, double A[],double X[],int n,double ile) {
	double suma = 0.0;
	double h = (b - a) / ile;
	for (int i = 0; i <ile; i++) {
		double x1 = a+(i*h);
		double x2 = a +((i + 1) * h);

		for (int i = 0; i < n; i++) {
			suma += A[i] * function(h/2 * X[i] + (x1+x2)/2);
		}
		
	
	}
	
	return suma *= h/2;
}
double kwadraturaGaussLagradneWielomianow(double W1[],double W2[], double a, double b, double A[], double X[], int n,int W_size,double ile) {
	double suma = 0.0;
	double h = (b - a) / ile;
	for (int i = 0; i < ile; i++) {
		double x1 = a + (i * h);
		double x2 = a + ((i + 1) * h);

		for (int i = 0; i < n; i++) {
			suma += A[i] * LiczHorenr(W1, h/2 * X[i] + (x1 + x2) / 2, W_size) * LiczHorenr(W2, h / 2 * X[i] + (x1 + x2) / 2, W_size);
		}


	}
	return suma *= h / 2;
}

double kwadraturaGaussLagradneWielomianuZFunckja(double W1[], double(*function)(double), double a, double b, double A[], double X[], int n, int W_size, double ile) {
	double suma = 0.0;
	double h = (b - a) / ile;
	for (int i = 0; i < ile; i++) {
		double x1 = a + (i * h);
		double x2 = a + ((i + 1) * h);
		for (int i = 0; i < n; i++) {
			suma += A[i] * LiczHorenr(W1, h / 2 * X[i] + (x1 + x2) / 2, W_size) * function(h / 2 * X[i] + (x1 + x2) / 2);
		}


	}

	return suma *= h / 2;
}