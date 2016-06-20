#include<iostream>

#include<cmath>
#define INF 1000
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

const int MAX_SIZE = 300;
bool arrBool[MAX_SIZE];
int arrTemp[MAX_SIZE];
int arrInt[MAX_SIZE];
int main()
{
	int n;
	cin >> n;
	int value;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		arrInt[i] = value;
		sum += value;
		arrBool[i] = false;
		arrTemp[i] = -1;
	}
	arrBool[0] = true;
	arrTemp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = sum - arrInt[i]; j >= 0; j--)
		{
			if (arrBool[j] == true)// && arrTemp[j]!=-1)
			{
				//arrTemp[j + arrInt[i]] = j;
				arrBool[j + arrInt[i]] = true;
			}
		}
	}

	int result = INF;
	for (int i = sum; i > 0; i--)
	{
		if (arrBool[i] == true)
		{
			int temp = abs(i - (sum - i));
			if (temp< result)
			{
				result = temp;
			}
		}
	}


	//cout << arrTemp[n / 2] << endl;
	cout << result << endl;

	system("pause");
	return 0;
}


