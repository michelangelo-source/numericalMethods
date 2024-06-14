#pragma once
double kwadraturaInterpolacyjna(double(*function)(double), double a, double b, double h);
double kwadraturaNewtonCotesa(double(*function)(double), double a, double b, double h);