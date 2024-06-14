#include "OrtogonalizacjaGramShmidt.h"
#include "kwadratura_gausa_Lagrande.h"
#include "Horner.h"


double** grahamSzmit(double a, double b,int size) {
	double X4[5] = { -0.906180,-0.538469,0 ,0.538469,0.906180 };
	double A4[5] = { 0.236927,0.478629,0.568889,0.478629,0.236927 };
	double** F = new double* [size];
	for (int i = 0; i < size; ++i) {
		F[i] = new double[size];
	}
	double** B = new double* [size];
	for (int i = 0; i < size; ++i) {
		B[i] = new double[size] {0};
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			F[i][j] = 0;
			
		}
		F[i][size - 1 - i] = 1;
	}
	
	B[0] = F[0];

	for (int i = 1; i < size; i++){
		B[i] = F[i];
		double* wektor = new double[size] {0};
		for (int j = 0; j < i; j++) {
			//fi
			double* W1= new double[size];
			W1 = F[i];

			// bj
			double* W2 = new double[size];
			W2 = B[j];

			double result = kwadraturaGaussLagradneWielomianow(W1, W2, a, b, A4, X4, size, size, 100) / kwadraturaGaussLagradneWielomianow(W2, W2, a, b, A4, X4, size, size, 100);
			for (int k = 0; k < size; k++) {
				wektor[k] += result*B[j][k];
			}
			
		}
		for (int j = 0; j < size; j++) {
			B[i][j] -= wektor[j];
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << B[i][j]<<" ; ";
		}
		std::cout << std::endl;
	}
	return 0;
}

