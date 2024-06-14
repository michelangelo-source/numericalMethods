#pragma once
#include <iostream>
void metodaEulera(double(*function)(double), double tkrok, double Tjajo, double tkoniec);
void metodaZmodyfikowanegoEulera(double(*function)(double), double tkrok, double Tjajo, double tkoniec);
void metodaHuenaEulera(double(*function)(double), double tkrok, double Tjajo, double tkoniec);