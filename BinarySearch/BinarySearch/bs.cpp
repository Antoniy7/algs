#include<iostream>
#include<algorithm>
using namespace std;


int arr[100001];

int n;
int k;


int bs()
{
	int left = 1;
	int right = arr[n - 1] - arr[0];
	int middle;
	int sum = 0;
	int best = -1;
	int lastPosition = 0;
	int counter = 1;

	while (left <=  right)
	{
		counter = 1;
		sum = arr[0]; 
		lastPosition = 0;

		middle = (left + right) / 2;
		
		for (int i = 1; i < n; i++)
		{
			if ((arr[i]-sum  ) >= middle)
			{
				sum= arr[i];
				counter++;

			}

			//sum += arr[i];
		}
		
		if (counter >= k)
		{
			if (middle>best)
				best = middle;

			left = middle + 1;
		}
		else if (counter < k)
			right = middle - 1;
	/*	else
			left = middle + 1;*/
		
	}

	return best;
}


int main()
{

     cin >> n >> k;
	//scanf("%d", &n);
	//scanf("%d", &k);

	for (int i = 0; i < n; i++)
		 cin >> arr[i]; //scanf("%d", &arr[i]);

	
	sort(arr, arr + n);
   


	int path=bs();

	cout << path << endl;

	//system("pause");
	return 0;
}





