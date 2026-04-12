#include<iostream>
#include<vector>
using namespace std;

int dir[8][2]
=
{
	{1, 0},
	{1, 1},
	{0, 1},
	{-1, 1},
	{-1, 0},
	{-1, -1},
	{0, -1},
	{1, -1},
};

int main()
{
	int w, h;
	vector<vector<char>> board;
	vector<vector<char>> visited;

	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)return;
		board.resize(h, vector<char>(w, '0'));
		visited.resize(h, vector<char>(w, '0'));
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{

			}
		}

	}
}