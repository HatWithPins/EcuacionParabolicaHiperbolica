#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

//Definición de n
//Define n
double* defineN(double L = 1.0, double boundaryLeft = 0.0, double boundaryRight = 0.0, int N = 3);
void solve(double* A, double* n, double T, double L = 1.0, double boundaryLeft = 0.0, double boundaryRight = 0.0, int N = 3);
void writeResults(double* n, double t, double h, double k, int N, double L);
#endif