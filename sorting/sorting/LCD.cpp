#include<iostream>
#include<stack>
using namespace std;

stack<int> theArray[1 << 16];

void radixSort(int*arr, int size) // least significant digit
{
	int mask = (1 << 16) - 1;


	for (int i = 0; i < size; i++)
	{
		theArray[arr[i] & mask].push(arr[i]);  // a & mask
	}

	for (int i = ((1 << 16) - 1), j = size - 1; i > 0; i--)
	{
		while (!theArray[i].empty())
		{
			arr[j--] = theArray[i].top();
			theArray[i].pop();
		}
	}


	mask <<= 16;
	for (int i = 0; i < size; i++)
	{
		theArray[(arr[i] & mask) >> 16].push(arr[i]);  // a & mask
	}


	for (int i = ((1 << 16) - 1), j = size - 1; i > 0; i--)
	{
		while (!theArray[i].empty())
		{
			arr[j--] = theArray[i].top();
			theArray[i].pop();
		}
	}

}

const int MAXTMP = 10000000;
int tmpArray[MAXTMP];
int tmpN;

void roar(int*left, int*mid, int*right, char sth)
{
	cout << "meow" << endl;
	tmpN = 0;
	int *p1 = left, *p2 = right - 1;

	while (p1 != mid || p2 != mid - 1)
	{
		if (p1 == mid) tmpArray[tmpN++] = *(p2--);
		else if (p2 == mid - 1) tmpArray[tmpN++] = *(p1++);
		else if (*p1 > *p2) tmpArray[tmpN++] = *(p1++);
		else tmpArray[tmpN++] = *(p2--);
	}


	int idx = 0;
	//for (int i = 0; i < tmpN; i++) *(left + i) = tmpArray[i];
	if (sth == 'd') while (left != right) { *(left++) = tmpArray[idx++]; }
	else while (left != right) { *(--right) = tmpArray[idx++]; }
}


void meow(int*arr, int size, char sth = 'n')
{
	if (size <= 1) return;

	int m = size / 2;

	meow(arr, m, 'd');
	meow(arr + m, size - m, 'a');

	if (sth != 'n') roar(arr, arr + m, arr + size, sth);


}


int main()
{



	int arr[12];
	arr[0] = 20;
	arr[1] = 520;
	arr[2] = 320;
	arr[3] = 660;
	arr[4] = 120;


	meow(arr, 5);

	//	radixSort(arr, 5);


	cout << "meow" << endl;

	system("pause");

	return 0;
}