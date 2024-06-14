#include "Interpolacja.h"

double interpolacjaLaGarange(double argument, double pktX[], double pktY[], int size) {
    double wynik=0;
    double licznik=1;
    double mianownik=1;
    for (int i = 0; i < size; i++) {
        licznik = 1;
        mianownik = 1;
        for (int j = 0; j < size; j++) {
            if (j != i) {
                licznik *= (argument - pktX[j]);
                mianownik *= (pktX[i] - pktX[j]);
            }
        }
        wynik += (pktY[i]*licznik/mianownik);
    }

    return wynik;
}




