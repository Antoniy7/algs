#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int MAX_SIZE = 50052;
vector<string>arr(MAX_SIZE);
vector<string>temp(MAX_SIZE);


void MergeSort(int left, int right)
{
	if (right <= left) return;

	int middle = (left + right) / 2;

	MergeSort(left, middle);
	MergeSort(middle + 1, right);

	int i, j;
	for (i = middle + 1; i >left; i--)
		temp[i - 1] = arr[i - 1];

	for (j = middle; j < right; j++)
		temp[right + middle - j] = arr[j + 1];

	for (int k = left; k <= right; k++)
	{
		if (temp[i].compare(temp[j]) < 0)
		{
			arr[k] = temp[i];
			i++;
		}
		else
		{
			arr[k] = temp[j];
			j--;
		}
	}

}


int main()
{
	int size;
	string input;
	cin >> size;

	for (int i = 0; i < size; i++)
	{
		cin >> input;
		arr[i] = input;
	}

	MergeSort(0, size - 1);



	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;

	return 0;
}
