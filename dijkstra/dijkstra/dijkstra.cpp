#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX //Infinity

const int SIZE = 300000; //Maximum possible number of vertices
bool  inputVisited[SIZE] = { 0, }; // so much false .. ;x 
queue<pair<int, int>>input;

vector<pair<int, int> > a[SIZE]; //Adjacency list
int dis[SIZE]; //Stores shortest distance
bool vis[SIZE] = { 0 }; //Determines whether the node has been visited or not

void Dijkstra(int source, int n) //Algorithm for SSSP
{
	for (int i = 0; i<SIZE; i++) //Set initial distances to Infinity
		dis[i] = INF;
	//Comparator Determining Priority (shortest edge comes first)
	class prioritize{ public: bool operator ()(pair<int, int>&p1, pair<int, int>&p2){ return p1.second>p2.second; } };
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize> pq; //vertex,weight pairs
	pq.push(make_pair(source, dis[source] = 0)); //Pushing the source with distance from itself as 0
	while (!pq.empty())
	{
		pair<int, int> curr = pq.top(); //Current vertex. The shortest distance for this has been found
		pq.pop();
		int cv = curr.first, cw = curr.second; //'cw' the final shortest distance for this vertex
		if (vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
			continue;
		vis[cv] = true;
		for (int i = 0; i<a[cv].size(); i++) //Iterating through all adjacent vertices
		if (!vis[a[cv][i].first] && a[cv][i].second + cw<dis[a[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
			pq.push(make_pair(a[cv][i].first, (dis[a[cv][i].first] = a[cv][i].second + cw))); //Set the new distance and add to priority queue
	}
}

int pain() //Driver Function for Dijkstra SSSP
{
	int n, m, x, y, w;//Number of vertices and edges
	//cout<<"Enter number of vertices and edges in the graph\n";
	cin >> n >> m;
	for (int i = 0; i<m; i++) //Building Graph
	{
		cin >> x >> y >> w; //Vertex1, Vertex2, weight of edge
		a[x].push_back(make_pair(y, w));
	}

	pair<int, int>myPair;
	int numberOfTests;
	cin >> numberOfTests;
	int source;
	int target;

	for (int j = 1; j <= numberOfTests; j++)
	{

		cin >> source;
		cin >> target;
		myPair.first = source;
		

		myPair.second = target;
		input.push(myPair);
	}
	while (!input.empty())
	{
		myPair = input.front();
		input.pop();
		int tempSource = myPair.first;
		int tempDes = myPair.second;
		if (inputVisited[tempSource]!=true)
			Dijkstra(tempSource, n);//SSSP from source (Also passing number of vertices as parameter)
		
		inputVisited[source] = true;
		if (dis[tempDes] != INF)
			cout << dis[tempDes] << "\n";
		else
		    cout << "unreachable\n";
	}

	//system("pause");
	return 0;
}