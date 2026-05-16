#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int verticesCnt;
	int edghCnt;
	cin >> verticesCnt >> edghCnt;
	vector<vector<int>> graph;
	for (int i = 0; i < edghCnt; ++i)
	{
		int p1, p2, cost;
		cin >> p1 >> p2 >> cost;
		graph[p1][p2] = cost;
		graph[p2][p1] = cost;
	}

}
