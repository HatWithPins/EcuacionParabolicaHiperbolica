#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//Definici�n de n
//Define n
double* defineN(double L = 1.0, double boundaryLeft = 0.0, double boundaryRight = 0.0, int N = 3);
int solve(double* A, double* n, double T, double lambda = 0.4, double L = 1.0, double boundaryLeft = 0.0, double boundaryRight = 0.0, int N = 3);
void writeResults(double* n, double t, double h, double k, int N, double L);
#endif