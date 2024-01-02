#include "EcuacionParabolicaHiperbolica.h"

using namespace std;

int steps(double lambda, double boundaryLeft, double boundaryRight, int N, double T, double L)
{
	MetodoQR metodoQR(N, lambda);
	metodoQR.Solve();

	double* A = metodoQR.GetMatrix();
	double* n = defineN(L, boundaryLeft, boundaryRight, N);

	return solve(A, n, T, lambda, L, boundaryLeft, boundaryRight, N);
}

int main(int argc, char** argv)
{
	
	string argument;
	size_t pos;
	size_t check;
	double boundaryLeft = 0.0;
	double boundaryRight = 0.0;
	int N = 3;
	double T = 1.0;
	double L = 1.0;
	int expectedArguments = 6;
	vector<string> expectedArgumentsList = { "boundary_left=", "boundary_right=", "N=", "T=", "L="};

	//Se comprueba el número de parámetros recibidos. 
	//Checking the number of received parameters.
	if (argc > expectedArguments)
	{
		cout << "Error, expected " << expectedArguments - 1 << ", but received " << argc - 1 << endl;
		return -1;
	}

	//Se comprueban los nombres de los parámetros.
	//Checking if parameter names are correct.
	try
	{
		for (int i = 1; i < argc; i++)
		{
			argument = argv[i];
			check = argument.find(expectedArgumentsList[i - 1]);
			if (check < 0 || check > argument.size())
			{
				vector<string> exceptionVector = { argument, expectedArgumentsList[i - 1] };
				throw(exceptionVector);
			}
			pos = argument.find("=");

			try
			{
				if (argument.substr(0, pos) == "boundary_left")
				{
					boundaryLeft = stod(argument.substr(pos + 1));
				}
				else if (argument.substr(0, pos) == "boundary_right")
				{
					boundaryRight = stod(argument.substr(pos + 1));
				}
				else if (argument.substr(0, pos) == "N")
				{
					N = stoi(argument.substr(pos + 1));
				}
				else if (argument.substr(0, pos) == "T")
				{
					T = stod(argument.substr(pos + 1));
				}
				else if (argument.substr(0, pos) == "L")
				{
					L = stod(argument.substr(pos + 1));
				}
			}
			catch (const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				return -1;
			}
		}
	}
	catch (vector<string> errorVector)
	{
		cout << "Error, expected " << errorVector[1] << "something, but received " << errorVector[0] << endl;
		return -1;
	}

	double lambda = 0.3;

	return steps(lambda, boundaryLeft, boundaryRight, N, T, L);
}
