#include<iostream>
#include<string>
//#include<vector>
//#include<algorithm>
using namespace std;

#define emptyCell '.'
#define notAccessible '*'
char maze[1005][1005];
int counter;
char result[1005][1005];
int n, m;
void dfs(int i, int j)
{
	if (i > m || j > n) return;
	//if (maze[i][j] == notAccessible) return;

	if (maze[i + 1][j] == emptyCell && i <= m && j <= n)
	{
		counter++; dfs(i + 1, j);
	}

	if (maze[i - 1][j] == emptyCell  && i <= m && j <= n)
	{
		counter++; dfs(i - 1, j);
	}
	if (maze[i][j + 1] == emptyCell  && i <= m && j <= n)
	{
		counter++; dfs(i, j + 1);
	}
	if (maze[i][j - 1] == emptyCell && i <= m && j <= n)
	{
		counter++; dfs(i, j - 1);
	}
}
char intToChar(int number)
{
	int temp = (number + 1) % 10;
	char value = '0' + temp;

	return value;
}

int main()
{

	//int n, m;
	cin >> m >> n;
	counter = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> maze[i][j];
			result[i][j] = maze[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			counter = 0;
			if (maze[i][j] == notAccessible)
			{
				dfs(i, j);
				result[i][j] = intToChar(counter);
			}
		}

	}

	string temp;
	int tcoun = 0;
	for (int i = 0; i < m; i++)
	{


		for (int j = 0; j < n; j++)
			temp += result[i][j];

		cout << temp;
		cout << endl;
		temp = "";
	}

	//	system("pause");
	return 0;
}
