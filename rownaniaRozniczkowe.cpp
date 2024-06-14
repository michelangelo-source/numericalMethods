#include "rownaniaRozniczkowe.h"
#include "przykladoweFunckje.h"

void metodaEulera(double(*function)(double),double tkrok,double Tjajo,double tkoniec){
	for (double i = tkrok; i < tkoniec; i += tkrok) {
		Tjajo = Tjajo + tkrok * function(Tjajo);

	}
		std::cout.precision(10);
		std::cout << Tjajo << std::endl;
}
void metodaZmodyfikowanegoEulera(double(*function)(double), double tkrok, double Tjajo, double tkoniec) {
	for (double i = tkrok; i < tkoniec; i += tkrok) {
		Tjajo = Tjajo+tkrok * function(Tjajo + 1 / 2 * tkrok * function(Tjajo));
	
	}
	std::cout.precision(10);
	std::cout << Tjajo << std::endl;
}
void metodaHuenaEulera(double(*function)(double), double tkrok, double Tjajo, double tkoniec) {
	for (double i = tkrok; i < tkoniec; i += tkrok) {
		Tjajo = Tjajo + 0.5 *tkrok*(function(Tjajo)+function(Tjajo+(tkrok*function(Tjajo))));

	}
	std::cout.precision(10);
	std::cout << Tjajo << std::endl;
}
