#include "Horner.h"
#include "Interpolacja.h"
#include "ELiminacjaGaussa.h"
#include "LU.h"
#include "przykladoweFunckje.h"
#include "KwadraturyProste.h"
#include "kwadratura_gausa_Lagrande.h"
#include "OrtogonalizacjaGramShmidt.h"
#include "AproksymacjaWielomianowa.h"
#include "rownaniaRozniczkowe.h"
#include "ZeroweBisekcja.h"
int main() {

//horner///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*  double x = -4.0;
  double x1 = -1;
  //zadanie 1
  int rozmiar = 4;
  double* wspolczynniki = new double[rozmiar];
  wspolczynniki[0] =0.5;
  wspolczynniki[1] = (4.0/3.0);
  wspolczynniki[2] = -(13.0/6.0);
  wspolczynniki[3] = -2;

  std::cout << "wyniki Horenra: " << std::endl;
  std::cout << "x=-4 wynik: " << LiczHorenr(wspolczynniki, x, rozmiar) << std::endl;
  std::cout << "x=-1 wynik: " << LiczHorenr(wspolczynniki, x1, rozmiar) << std::endl;

  //zadanie 2
  x = 0;
  x1 = 2;

  wspolczynniki[0] = 0.5;
  wspolczynniki[1] = -(7.0 / 6.0);
  wspolczynniki[2] = (5.0 / 3.0);
  wspolczynniki[3] = -4;
  double* pkt = new double[rozmiar-1];
  pkt[0] = 0.0;
  pkt[1] = -1.0;
  pkt[2] = -4.0;


  std::cout << "wyniki newton " << std::endl;
  std::cout << "x=0 wynik: " << liczNewtonPrzyOgolnymHorenr(wspolczynniki, x, rozmiar, pkt) << std::endl;
  std::cout << "x=2 wynik: " << liczNewtonPrzyOgolnymHorenr(wspolczynniki, x1, rozmiar, pkt) << std::endl;



  */
//interpolAcja/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* int size = 5;
  double* pktX = new double[size];
  double* pktY = new double[size];
  pktX[0] = -2.0;
  pktX[1] = -1.0;
  pktX[2] = 0.0;
  pktX[3] = 1.0;
  pktX[4] = 2.0;

  pktY[0] = 5.0;
  pktY[1] = -2.0;
  pktY[2] = 4.0;
  pktY[3] = -7.0;
  pktY[4] = 2.0;

  double Y;
  for (double x = -2.0; x < 2.01; x += 0.01) {
      Y = interpolacjaLaGarange(x, pktX, pktY, size);
      std::cout << Y << "\n";
  }*/
  //eliminacja gausa/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*int size = 5;
  double** tablica = new double* [size];
  for (int i = 0; i < size; ++i) {
      tablica[i] = new double[size];
  }
  tablica[0][0] = 1;
  tablica[0][1] = -3;
  tablica[0][2] = 4;
  tablica[0][3] = 6.8;
  tablica[0][4] = 9;
  tablica[1][0] = -3;
  tablica[1][1] = 2;
  tablica[1][2] = 4.6;
  tablica[1][3] = 6.3;
  tablica[1][4] = -10;
  tablica[2][0] = 2;
  tablica[2][1] = -1;
  tablica[2][2] = 2.8;
  tablica[2][3] = -8.4;
  tablica[2][4] = -5;
  tablica[3][0] = -6;
  tablica[3][1] = 2;
  tablica[3][2] = 7;
  tablica[3][3] = -0.5;
  tablica[3][4] = -0.9;
  tablica[4][0] = 5;
  tablica[4][1] = -2;
  tablica[4][2] = -0.5;
  tablica[4][3] = 12;
  tablica[4][4] = -4;
  double* wyniki = new double[size];
  double* wpolwynik = new double[size];

  wpolwynik[0] = 74.64;
  wpolwynik[1] = -40.26;
  wpolwynik[2] = -2.32;
  wpolwynik[3] = 12.6;
  wpolwynik[4] = -8.9;

  wyniki = eliminacjaGaussa(tablica, wpolwynik, size);
  for (int i = 0; i < size; i++) {
      std::cout << wyniki[i] << std::endl;
  }*/
  ///// LU///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*int size = 3;
  double** tablica = new double* [size];
  for (int i = 0; i < size; ++i) {
      tablica[i] = new double[size];
  }
  tablica[0][0] = 60.;
  tablica[0][1] = 30.;
  tablica[0][2] = 20.;


  tablica[1][0] = 30.;
  tablica[1][1] = 20.;
  tablica[1][2] = 15.;


  tablica[2][0] = 20.;
  tablica[2][1] = 15.;
  tablica[2][2] = 12.;


  double** L = new double* [size];
  for (int i = 0; i < size; ++i) {
      L[i] = new double[size];
  }
  double** U = new double* [size];
  for (int i = 0; i < size; ++i) {
      U[i] = new double[size];
  }


  rozkladLU(size, tablica, L, U);


  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << tablica[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << "Macierz U: " << std::endl;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << U[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << "Macierz L: " << std::endl;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << L[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;

  tablica[0][0] = 3.;
  tablica[0][1] = 0.;
  tablica[0][2] = 1.;


  tablica[1][0] = 0.;
  tablica[1][1] = -1.;
  tablica[1][2] = 3.;


  tablica[2][0] = 1.;
  tablica[2][1] = 3.;
  tablica[2][2] = 0.;
  rozkladLU(size, tablica, L, U);
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << tablica[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << "Macierz U: " << std::endl;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << U[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << "Macierz L: " << std::endl;
  for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
          std::cout << L[i][j] << " ";
      }
      std::cout << std::endl;
  }
  std::cout << std::endl;*/
  //kwadratury proset///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* double wynik;
  std::cout << "Przyklad 1" << std::endl;
  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaInterpolacyjna(przyklad1, 0, 4.5, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 2" << std::endl;
  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaInterpolacyjna(przyklad2, -2.0, 2.0, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 3" << std::endl;

  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaInterpolacyjna(przyklad3, 0.00000001, 1.0, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 4" << std::endl;
  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaInterpolacyjna(przyklad4, 10e-4, 1, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 1" << std::endl;
  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaNewtonCotesa(przyklad1, 0, 4.5, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 2" << std::endl;
  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaNewtonCotesa(przyklad2, -2.0, 2.0, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 3" << std::endl;

  for (double krok = 10e-2; krok >= 10e-4; krok /= 10) {
      wynik = kwadraturaNewtonCotesa(przyklad3, 0.00000001, 1.0, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  std::cout << "Przyklad 4" << std::endl;
  for (double krok = 10e-2; krok >= 10e-6; krok /= 10) {
      wynik = kwadraturaNewtonCotesa(przyklad4, 10e-4, 1, krok);
      std::cout << krok << " ";
      std::cout << wynik << std::endl;
  }
  */
  ///kwaddratura lagrebdra ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* double X1[2] = { -0.577350,0.577350 };
  double A1[2] = { 1.0,1.0 };

  double X2[3] = { -0.774597,0.,0.774597 };
  double A2[3] = { 5 / 9,8 / 9,5 / 9 };

  double X3[4] = { -0.861136,-0.339981,0.339981,0.861136 };
  double A3[4] = { 0.347855,0.652145,0.652145, 0.347855 };

  double X4[5] = { -0.906180,-0.538469,0 ,0.538469,0.906180 };
  double A4[5] = { 0.236927,0.478629,0.568889,0.478629,0.236927 };
  double wynik = kwadraturaGaussLagradne(przyklad1, 0.00000001, 4.5, A4, X4, 5, 100);
  std::cout << wynik << std::endl;

  double W1[4] = { 1.,2.,1.,-2. };
  double W2[4] = { 2.,1.,-1.,10. };
  std::cout << kwadraturaGaussLagradneWielomianow(W1, W2, -2, 2, A4, X4, 5, 4, 100) << std::endl;
  */
  //grham szmit//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //grahamSzmit(-1, 1, 5);
  //aproksymajca/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* double* W = new double[5];
  W = aproksymacja(0, 1, 5, przykladApro);
  for (double x = -2.0; x <= 2.0; x += 0.01) {
      std::cout << x << ";" << przykladApro(x) << ";" << LiczHorenr(W, x, 5) << std::endl;

  }*/
  //rownian rozniczkowe /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* metodaEulera(stefanBoltzman, 0.001, 1200, 300);
  metodaZmodyfikowanegoEulera(stefanBoltzman, 0.001, 1200, 300);
  metodaHuenaEulera(stefanBoltzman, 0.0001, 1200, 300); */
  ////bisekcja/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /* double wynik1 = bisekcja(0.0001, przyklad5, -3, 3);
  double wynik2 = bisekcja(0.0001, przyklad6, -3, 3);
  double wynik3 = bisekcja(0.0001, przyklad7, -3, 3);
  double wynik4 = bisekcja(0.0001, przyklad8, -3, 3);
  std::cout << wynik1 << " " << wynik2 << " " << wynik3 << " " << wynik4 << " " << std::endl;
	*/
	return 0;
}