#include "Horner.h"


double LiczHorenr(double wspolczynniki[], double argument, int size) {
    double wynik = wspolczynniki[0];

    for (int i = 1; i < size; i++) {
        wynik = wynik * argument + wspolczynniki[i];
    }
    return wynik;
}
double liczNewtonPrzyOgolnymHorenr(double wspolczynniki[], double argument, int size, double pkt[]) {
    double wynik = wspolczynniki[0];

    for (int i = 1; i < size; i++) {
        wynik = wynik * (argument - pkt[i - 1]) + wspolczynniki[i];
    }
    return wynik;
}