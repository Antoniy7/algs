#include<iostream>
using namespace std;


void CountingSort(int*&pArr, int size)
{
	int maxNumber = -1;


	for (int i = 0; i < size; i++)
	{
		if (pArr[i]>maxNumber)
			maxNumber = pArr[i];
	}

	int *repOfDigits = new int[maxNumber + 1];
	int*exitArray = new int[size];

	for (int i = 0; i <= maxNumber; i++)
		repOfDigits[i] = 0;

	for (int i = 0; i < size; i++) // counting
	{
		repOfDigits[pArr[i]]++;
	}

	for (int i = 1; i <= maxNumber; i++) // adding the previous to the current 
		repOfDigits[i] += repOfDigits[i - 1];

	for (int i = 0; i < size; i++)
	{
		exitArray[--repOfDigits[pArr[i]]] = pArr[i];

	}
	delete[] repOfDigits;
	pArr = exitArray;
}

int main()
{
	const int size = 4;

	int*arr = new int[size];
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 2;
	arr[3] = 1;

	CountingSort(arr, size);

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;




	return 0;
}