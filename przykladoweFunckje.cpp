#include"przykladoweFunckje.h"
double przyklad1(double x) {
    return(x * x * pow(sin(x), 3));
}
double przyklad2(double x) {
    return((x - 1) * exp(pow(x, 2)));
}
double przyklad3(double x) {
    return(sin(x) / x);
}
double przyklad4(double x) {
    return (sin(1 / x));
}
double przykladApro(double arg) {
    return (sin(-arg) + exp(-arg) - pow(arg, 3));
}
double stefanBoltzman(double T) {
    return (-1e-12 * pow(T, 4));
}
double przyklad5(double x) {
    return (x * x * x + x * x - 3 * x - 3);
}
double przyklad6(double x) {
    return (x * x - 2);
}
double przyklad7(double x) {
    return (sin(x * x) - x * x);
}
double przyklad8(double x) {
    return (sin(x * x) - x * x + 0.5);
}