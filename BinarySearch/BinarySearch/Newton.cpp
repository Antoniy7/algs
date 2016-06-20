#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{
	
	int root;
	cin >> root;
	double approximation = 100;
	const int numberOfLoops = 100000;

	for (int i = 1; i <= numberOfLoops; i++)
		approximation = approximation - (approximation*approximation - root) / (2 * approximation);

	cout << approximation << endl;

	system("pause");
	return 0;
}
