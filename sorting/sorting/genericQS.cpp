#include<iostream>
#include<vector>
using namespace std;

const int MAX_SIZE = 1024;
int arr[MAX_SIZE];

int Partition(int, int);

void quickSort(int left, int right)
{
	if (left < right)
	{
		int m = Partition(left, right);
		quickSort(left, m);
		quickSort(m + 1, right);
	}
}
int Partition(int left, int right)
{
	int x = arr[left];
	int i = left;
	int j;

	for (j = left + 1; j<right; j++)
	{
		if (arr[j] <= x)
		{
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[left]);

	return i;
}



int main()
{
	//int n; 
	//cin>>n;
	//for(int i=0;i<n;i++)
	//   cin>>a[i];

	//quickSort(0,n-1)

	cout << "yolo" << endl;
	return 0;
}