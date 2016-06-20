/*#include<iostream>
#include<cmath>
using namespace std;

float func(float x)
{
	float y;
	y = (cos(x));
	return y;
}

int main()
{
	double arr[110];
	double initialGuess = 12542;
	int temp=0;
	cin >> temp;
	for (int i = 1; i <= 100;i++)
	{
		arr[temp++] = func(initialGuess);
		cout << arr[temp - 1] << endl;
 	}

	cout << arr[temp] << endl;

	system("pause");
	return 0;
}
*/

#include<iostream>
#include<cmath>
using namespace std;

float func(float x)
{
	float y;
	y = (cos(x) + 5) / 13;
	return y;
}

int main()
{
	
	int j = 0;
	double guess;
	double temp;
	cin >> guess;
	for (int i = 1; i <= 8;i++)
	{
		temp = func(guess);
		
		cout << j << "  " <<guess << endl;
		guess = temp;

	}
	
	system("pause");
	return 0;
}
