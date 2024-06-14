#include "KwadraturyProste.h"

double kwadraturaInterpolacyjna(double(*function)(double),double a,double b, double h ) {
    double suma = 0;
    for (a; a < b;a+=h) {
        suma += (function(a) + function(a + h)) * h / 2;
    }
    return suma;
}
double kwadraturaNewtonCotesa(double(*function)(double), double a, double b, double h) {
    double suma = 0;
    for (a; a < b; a += h) {
        suma += (function(a) + function(a + h)+4*function((a+a+h)/2)) * h / 6;
    }
    return suma;
}



