#include<iostream>
using namespace std;

double binarySearch(int x)
{
	double finish = x;
	double start = 1.00013;
	double middle;
	middle = (start + finish) / 2;

	while (start <= finish)
	{
		middle = (start + finish) / 2;

		if (middle*middle == x)
			return middle;

		else if (middle*middle < x)
			start = middle + 0.00025;
		else if (middle*middle>x)
			finish = middle - 0.00025;
	}
	return middle;
}

int main()
{

	int number;
	cin >> number;

	//double root = binarySearch(number);
	
	//cout << root << endl;

	int k;
	cin >> k;
    
	//double value=binarySearch(number);
    //value = binarySearch(value);
	
	double value = number;

	for (int i = 1; i <= k; i++)
	{
		value = binarySearch(value);

	}


	cout << value << endl;
	
	system("pause");
	return 0;
}