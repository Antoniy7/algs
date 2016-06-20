#include<iostream>
#include<stdlib.h>     /* srand, rand */
#include<time.h>      /* time */
#include<fstream>
using namespace std;

template<typename TYPE>
void GenerateMatrix(TYPE** &matrix, TYPE size)
{
	matrix = new TYPE*[size];

	for (int i = 0; i < size; i++)
	{
		matrix[i] = new TYPE[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			matrix[i][j] = rand() % 10 + 1 + (i*0.4); 
	}
}
template<typename TYPE>
void print(TYPE** &matrix, TYPE size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

template<typename TYPE>
TYPE** MultipyAxB_cache_friendly(TYPE**&matrixA, TYPE**&matrixB, TYPE size)
{
	TYPE**matrixC = new TYPE*[size];

	for (int i = 0; i <size; i++)
	{
		matrixC[i] = new TYPE[size];
	}
	TYPE*temp = new TYPE[size];

	for (int j = 0; j < size; j++)
	{
		for (int k = 0; k < size; k++)
			temp[k] = matrixB[k][j];

		for (int i = 0; i < size; i++)
		{
			double s = 0;
			for (int k = 0; k < size; k++)
				s += matrixA[i][k] * temp[k];
			matrixC[i][j] = s;
		}
	}
	delete[] temp;
	return matrixC;
}
template<typename TYPE>
void write_to_File(TYPE**matrixC, TYPE size)
{
	ofstream outBinFile;
	outBinFile.open("BINFILE.BIN", ios::out | ios::binary);
	outBinFile.write(reinterpret_cast<char*> (&size), sizeof(TYPE));

	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j <size; j++)
		{
			outBinFile.write(reinterpret_cast<char*> (&matrixC[i][j]), sizeof(TYPE));
		}
	}

	outBinFile.close();
}
template<typename TYPE>
TYPE** read_from_binary(char*name)
{
	ifstream inBinFile;
	inBinFile.open(name, ios::in | ios::binary);
	TYPE size;
	inBinFile.read(reinterpret_cast<char*> (&size), sizeof(TYPE));
	TYPE**matrixC = new TYPE*[size];
	for (int i = 0; i < size; i++)
		matrixC[i] = new TYPE[size];

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			inBinFile.read(reinterpret_cast<char*>(&matrixC[i][j]), sizeof(TYPE));

	inBinFile.close();
	return matrixC;

}

int main()
{
	// INTEGERS
	const int size = 2;                         // change size of the matrix;
	srand(time(NULL));
	int**matrixA;
	int**matrixB;
	int**matrixC;
	GenerateMatrix<int>(matrixA, size);
	cout << "MATRIX A:\n";
	print<int>(matrixA, size);
	cout << endl;
	GenerateMatrix<int>(matrixB, size);
	cout << "MATRIX B:\n";
	print<int>(matrixB, size);
	cout << endl;
	matrixC = MultipyAxB_cache_friendly<int>(matrixA, matrixB, size);
	cout << "MATRIX AxB:\n";
	print<int>(matrixC, size);

	//BINFILE.BIN
	write_to_File<int>(matrixC, size);
	int**matrixD = read_from_binary<int>("BINFILE.BIN");
	cout << endl;
	cout << "MATRIX AxB after writing and reading in binary:\n";
	print<int>(matrixD, size);

	cout << endl;


	// double
	const double size1 = 2;
	srand(time(NULL));
	double**matrixA1;
	double**matrixB1;
	double**matrixC1;
	GenerateMatrix<double>(matrixA1, size);
	cout << "MATRIX A:\n";
	print<double>(matrixA1, size);
	cout << endl;
	GenerateMatrix<double>(matrixB1, size);
	cout << "MATRIX B:\n";
	print<double>(matrixB1, size);
	cout << endl;
	matrixC1 = MultipyAxB_cache_friendly<double>(matrixA1, matrixB1, size);
	cout << "MATRIX AxB:\n";
	print<double>(matrixC1, size);

	//BINFILE.BIN
	write_to_File<double>(matrixC1, size);
	double**matrixD1 = read_from_binary<double>("BINFILE.BIN");
	cout << endl;
	cout << "MATRIX AxB after writing and reading in binary:\n";
	print<double>(matrixD1, size);



	getchar();
	return 0;
}