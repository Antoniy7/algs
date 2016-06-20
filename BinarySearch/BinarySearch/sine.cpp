#include<iostream>
#include<cmath>
using namespace std;

double factoriel(int x)
{
	double temp=1;
	for (int i = 1; i <= x; i++)
		temp *= i;

	return temp;
}
double sine(int x, int n)
{
	double result=0;
	double chislitel=0;
	double chislitelZnak=0;
	double znamenatel=0;
	for (int i = 0; i <= n; i++)
	{
		chislitelZnak = pow(-1, i);
		chislitel = pow(x, (2 * i) + 1);
		znamenatel = factoriel((2 * i + 1));

		result += (chislitel*chislitelZnak) / znamenatel;
	}
	return result;
}

int main()
{
	int x,n;
	cin >> x>>n;
	cout << sine(x,n) << endl;
	

	system("pause");
	return 0;
}
