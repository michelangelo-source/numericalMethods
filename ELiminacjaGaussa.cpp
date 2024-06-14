#include "ELiminacjaGaussa.h"
double* eliminacjaGaussa(double* tab[],double wspolwynik[], int size) {
   
    double** tablica = new double* [size];
    for (int i = 0; i < size; ++i) {
        tablica[i] = new double[size+1];
    }//tworzenie rozszerzonej
    tablica = tab;
    for (int i = 0; i < size; i++) {
        tablica[i][size] = wspolwynik[i];
    }//przypisanie

    double wspolczynnik;
    for (int z = 0; z < size - 1; z++) {
        for (int i = 0; i < size -z - 1; i++) {
            wspolczynnik = tablica[z+i + 1][z] / tablica[z][z];
            for (int j = z; j <  size+1; j++) {
                tablica[z + i + 1][j] -= wspolczynnik * tablica[z][j];
            }
        }
    }//diagonalizacja
    
    double* wyniki = new double[size];
    wyniki[size - 1] = tablica[size-1][size]/ tablica[size - 1][size-1];
    int licznik = 1;
    double suma = 0;
    for (int i = size-2; i >= 0; i--) {
       
        suma = 0;
        for (int j = size; j > size - licznik; j--) {
            suma += wyniki[j - 1] * tablica[i][j-1];
        }
        licznik++;
        wyniki[i] = (tablica[i][size] -suma)/tablica[i][i] ;
    }//wyliczenie

    


    return wyniki;
}

