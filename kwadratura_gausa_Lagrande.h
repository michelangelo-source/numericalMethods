#pragma once
double kwadraturaGaussLagradne(double(*function)(double), double a, double b, double A[], double X[], int n, double ile);
double kwadraturaGaussLagradneWielomianow(double W1[], double W2[], double a, double b, double A[], double X[], int n, int W_size, double ile);
double kwadraturaGaussLagradneWielomianuZFunckja(double W1[], double(*function)(double), double a, double b, double A[], double X[], int n, int W_size, double ile);