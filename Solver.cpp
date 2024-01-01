#include "Solver.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

dobule* defineN(double L, double boundaryLeft, double boundaryRight, int N)
{
	double* n = new double[N];
	double h = L / N;
	double x;

	n[0] = boundaryLeft;
	n[N - 1] = boundaryRight;

	for (int i = 1; i < N - 1; i++)
	{
		x = -L / 2.0 + i * h;
		n[i] = (h + x) / (h * h) * (-h < x) + (h - x) / (h * h) * (h > x);
	}

	return n;
}

void solve(double* A, double* n, double T, double L, double boundaryLeft, double boundaryRight, int N)
{
	double h = L / N;
	double t = 0.0;
	//Para asegurar la convergencia, el paso de tiempo tiene que cumplir la relación k/(h^2)<=1/2.
	//To ensure convergence, time step must satisfy the relationship k/(h^2)<=1/2.
	double k = h * h / 2;

	while (t < T)
	{
		for (int i = 0; i < N; i++)
		{
			n[i] = A[3 * i] * n[i];
		}
		t += k;

		writeResults(n, t, h, k, L);
	}
}

void writeResults(double* n, double t, double h, double k, int N, double L)
{
	double x;

	ofstream file{ "results/t-"+ to_string(t) +"-h-" + to_string(h) + "-k-" + to_string(k) + ".csv" };
	file << "x_i,n_i\n";

	for (int i = 0; i < N; i++)
	{
		x = -L / 2.0 + i * h;
		file << to_string(x) + "," + to_string(n[i]);
	}

	file.close();
}