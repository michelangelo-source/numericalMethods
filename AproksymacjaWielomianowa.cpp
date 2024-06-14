#include "AproksymacjaWielomianowa.h"
#include "kwadratura_gausa_Lagrande.h"
#include "OrtogonalizacjaGramShmidt.h"


double* aproksymacja(double a, double b,int size, double(*function)(double)) {
	double X4[5] = { -0.906180,-0.538469,0 ,0.538469,0.906180 };
	double A4[5] = { 0.236927,0.478629,0.568889,0.478629,0.236927 };
	double** B = new double* [size];
	for (int i = 0; i < size; ++i) {
		B[i] = new double[size] {0};
	}
	B=grahamSzmit(a, b, size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << B[i][j] << " ; ";
		}
		std::cout << std::endl;
	}
	//ortonormalizacja
	for (int i = 0; i < size; i++) {
		double norma = sqrt(kwadraturaGaussLagradneWielomianow(B[i], B[i], a, b, A4, X4, size, size, 100));
		for (int j = 0; j < size; j++) {
			B[i][j] /= norma;
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << B[i][j] << " ; ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	//wyliczanie alpha
	double* alpha = new double[size];
	for (int i = 0; i < size; i++) {
		alpha[i] = kwadraturaGaussLagradneWielomianuZFunckja(B[i],function , a, b, A4, X4, size, size, 100);
		std::cout << alpha[i]<< " ; ";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	//wyliczanie wspl apro
	double* W = new double[size] {0};
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			W[i] += alpha[j] * B[j][i];
		}
		
	}
	std::cout << std::endl;
	std::cout << std::endl;
	for (int i = 0; i < size; i++) {
		
		std::cout << W[i] << " ; ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return W;
}
