#include<iostream>
#include<string>
#include<stack>
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
	pair<int, int>myPair;
	myPair.first = i;
	myPair.second = j;
	stack<pair<int, int>>st;
	st.push(myPair);
	while (!st.empty())
	{

		pair<int, int> tempPair;
		tempPair = st.top();
		st.pop();

		pair<int, int>otherPair;
		otherPair = tempPair;
		//if (i > m || j > n) return;
		//if (maze[i][j] == notAccessible) break;
		if (tempPair.first > m || tempPair.second > n) break;

		if (maze[tempPair.first + 1][tempPair.second] == emptyCell && tempPair.first <= m && tempPair.second <= n)
		{
			counter++;
			otherPair.first = i + 1;
			otherPair.second = j;
			st.push(otherPair);
			//dfs(i + 1, j);
		}

		if (maze[tempPair.first - 1][tempPair.second] == emptyCell  && tempPair.first <= m && tempPair.second <= n)
		{
			counter++;
			otherPair.first = i - 1;
			otherPair.second = j;
			st.push(otherPair);
			//dfs(i - 1, j);
		}
		if (maze[tempPair.first][tempPair.second + 1] == emptyCell  && tempPair.first <= m && tempPair.second <= n)
		{
			counter++;
			otherPair.first = i;
			otherPair.second = j + 1;
			st.push(otherPair);
			//dfs(i, j + 1);
		}
		if (maze[tempPair.first][tempPair.second - 1] == emptyCell && tempPair.first <= m && tempPair.second <= n)
		{
			counter++;
			otherPair.first = i;
			otherPair.second = j - 1;
			st.push(otherPair);
			//dfs(i, j - 1);
		}
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
	/*scanf_s("%d", &m);
	scanf_s("%d", &n);*/
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
