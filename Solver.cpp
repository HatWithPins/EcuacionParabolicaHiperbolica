#include "Solver.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

double* defineN(double L, double boundaryLeft, double boundaryRight, int N)
{
	double* n = new double[N + 1];
	double h = L / N;
	double x;

	n[0] = boundaryLeft;
	n[N] = boundaryRight;

	for (int i = 1; i < N; i++)
	{
		x = -L / 2.0 + i * h;
		n[i] = 0;
		n[i] += (h + x) / (h * h) * (-h < x && x < 0) + (h - x) / (h * h) * (h > x && x > 0);
	}

	return n;
}

double* defineA(double lambda, int N)
{
	int matrixLength = N + 2 * (N - 1);
	double* matrix = new double[matrixLength];

	matrix[0] = 1 - 2 * lambda;
	matrix[1] = lambda;
	matrix[matrixLength - 1] = 1 - 2 * lambda;
	matrix[matrixLength - 2] = lambda;

	for (int i = 3; i < matrixLength - 2; i += 3) {
		matrix[i - 1] = lambda;
		matrix[i] = 1 - 2 * lambda;
		matrix[i + 1] = lambda;
	}

	return matrix;
}

int solve(double* A, double* n_0, double T, double lambda, double L, double boundaryLeft, double boundaryRight, int N)
{
	double h = L / N;
	double t = 0.0;
	double* n_1 = new double[N + 1];
	n_1[0] = boundaryLeft;
	n_1[N] = boundaryRight;
	//Para asegurar la convergencia, el paso de tiempo tiene que cumplir la relación k/(h^2)<=1/2.
	//To ensure convergence, time step must satisfy the relationship k/(h^2)<=1/2.
	double k = h * h * lambda;
	int maxIterations = 10000;
	int iteration = 0;
	int matrixLength = N + 2 * (N - 1);

	writeResults(n_0, t, h, k, N, L);

	while (t < T)
	{
		for (int i = 1; i < N; i++)
		{
			n_1[i] = A[i * 3] * n_0[i] + A[i * 3 - 1] * n_0[i - 1] + A[i * 3 + 1] * n_0[i + 1];
		}
		t += k;

		writeResults(n_1, t, h, k, N, L);

		for (int i = 0; i < N + 1; i++)
		{
			n_0[i] = n_1[i];
		}

		if (iteration > maxIterations) return 1;
		iteration++;
	}

	return 0;
}

void writeResults(double* n, double t, double h, double k, int N, double L)
{
	double x;

	ofstream file{ "results/t-"+ to_string(t) +"-h-" + to_string(h) + "-k-" + to_string(k) + ".csv" };
	file << "x_i,n_i\n";

	for (int i = 0; i < N + 1; i++)
	{
		x = -L / 2.0 + i * h;
		file << to_string(x) + "," + to_string(n[i]) + "\n";
	}

	file.close();
}