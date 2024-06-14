#include "LU.h"
void jajo(double* tab[],int size) {
    for (int i = 0; i < size; i++) {
        if (tab[i][i] == 0) {

            if (i > 0) {
                for (int j = 0; j < size; j++) {
                    std::swap(tab[i][j], tab[i - 1][j]);
                }
            }
            else {
                for (int j = 0; j < size; j++) {
                    std::swap(tab[i][j], tab[i + 1][j]);
                }
            }
            jajo(tab, size);
        }
        
    }
}

void rozkladLU(int size, double* tab[], double* L[], double* U[]) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            L[i][j]=0.;
            U[i][j] = 0.;
        }
    }
    for (int i = 0; i < size; i++) {
        L[i][i] = 1;

    }

    jajo(tab,size);

    double suma;
    for (int j = 0; j < size; j++) {

        for (int i = 0; i <= j; i++) {
            suma = 0.;

            for (int k = 0; k < i; k++) {
                suma += L[i][k] * U[k][j];
            }
            U[i][j] = tab[i][j] - suma;
        }

        for (int i = j + 1; i < size; i++) {
            suma = 0.;
            for (int k = 0; k < j; k++) {
                suma += L[i][k] * U[k][j];
            }
            if (U[j][j]) {
                L[i][j] = (tab[i][j] - suma) / U[j][j];
            }
        }
    }
    }