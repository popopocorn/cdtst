//±âº»
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	
}


//1
#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int cnt;
	int sol = 0;
	vector<char> chair;
	char temp;
	cin >> cnt;
	for (int i = 0; i < cnt; ++i)
	{
		cin >> temp;
		chair.push_back(temp);
	}
	for (int i = 0; i < cnt; ++i)
	{
		if (i == 0)++sol;
		if (chair[i] == 'S')
		{
			++sol;
		}
		else if (chair[i] == 'L')
		{
			++sol;
			++i;
		}
	}
	if (sol > cnt)sol = cnt;
	cout << sol;
}


//2

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt;



	cin >> cnt;
	char temp;
	for (int i = 0; i < cnt; ++i)
	{
		bool mis = false;
		vector<vector<char>> plate(9);
		vector<vector<char>> etalp(9, vector<char>(9));
		int col = 0;
		for (int j = 0; j < 13; ++j)
		{
			for (int k = 0; k < 13; ++k)
			{
				cin >> temp;
				if (isdigit(temp) || temp == '.')
				{
					plate[col].push_back(temp);
				}
				if (plate[col].size() == 9)++col;
			}

		}
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				int c = count(plate[j].begin(), plate[j].end(), k + '1');
				if (c > 1)
				{
					mis = true;
					break;
				}
				etalp[k][j] = plate[j][k];

			}
			if (mis)break;
		}
		for (int j = 0; j < 9; ++j)
		{
			for (int k = 0; k < 9; ++k)
			{
				int c = count(etalp[j].begin(), etalp[j].end(), k + '1');
				if (c > 1)
				{
					mis = true;
					break;
				}
			}
			if (mis)break;
		}


		if (mis)cout << 'N' << endl;
		else cout << 'Y' << endl;;


	}

}


//3

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct v {
	int n;
	int s;
	int tic;
	int score;

};

int main()
{
	int cnt, tmp;;
	cin >> cnt;
	vector<v> list(cnt);
	for (int i = 0; i < cnt; ++i) {
		list[i].n = i;

		cin >> tmp;
		list[i].s = tmp;
	}
}

//4

#include<iostream>
#include<vector>

using namespace std;

int dir[4][2] =
{
	{1, 0},
	{-1, 0},
	{0, 1},
	{0, -1},

};

void find(vector<vector<char>> pic,
	vector<vector<char>>& visited, char color,
	int cnt, int x, int y)
{
	visited[y][x] = '1';
	for (int i = 0; i < 4; ++i) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		if (ny >= 0 && ny < cnt && nx >= 0 && nx < cnt)
		{
			if (pic[ny][nx] == color && visited[ny][nx] == '0')
				find(pic, visited, color, cnt, nx, ny);
		}

	}
}

int main()
{
	int cnt;
	char temp;
	int sol = 0;
	cin >> cnt;
	vector<vector<char>> pic(cnt, vector<char>(cnt));
	vector<vector<char>> visited(cnt, vector<char>(cnt, '0'));
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			cin >> temp;
			pic[i][j] = temp;
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			if (visited[i][j] == '0')
			{
				find(pic, visited, pic[i][j], cnt, j, i);
				++sol;
			}

		}
	}
	cout << sol << ' ';

	sol = 0;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			visited[i][j] = '0';
			if (pic[i][j] == 'R') pic[i][j] = 'G';
		}
	}
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			if (visited[i][j] == '0')
			{
				find(pic, visited, pic[i][j], cnt, j, i);
				++sol;
			}

		}
	}
	cout << sol;
}


//5

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int f, g, s, u, d;
	cin >> f >> s >> g >> u >> d;
	vector<int>dist(f, -1);
	bool find = false;
	if (g == s)
	{
		cout << 0;
		return 0;
	}
	queue<int>q;
	dist[s] = 0;
	q.push(s);
	while (not q.empty())
	{
		if (find)break;
		int f = q.front();
		q.pop();

		int p[2] =
		{
			f + u,
			f - d
		};

		for (int n : p)
		{
			if (n<0 || n>f)continue;
			if (dist[n] == -1)
			{
				dist[n] = dist[f] + 1;
				q.push(n);
			}
			if (n == g)
			{
				cout << dist[n];
				find = true;

				break;
			}
		}
	}
	if (not find)cout << "use the stairs";


}


//6



#include<iostream>
#include<vector>

using namespace std;

void comb(int foods, vector<vector<int>>& result,
	int size, int startidx,
	vector<int> temp)
{

	if (temp.size() == size)
	{
		result.push_back(temp);
		return;
	}

	for (int i = startidx; i < foods; ++i) {

		temp.push_back(i);
		comb(foods, result, size, i + 1, temp);
		temp.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int temp;
	vector<vector<int>> v(m, vector<int>(n));


	vector<int>t;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> temp;
			v[j][i] = temp;
		}
	}
	for (int i = 1; i < m; ++i)
	{
		vector <vector<int>>foods;
		comb(m, foods, i, 0, t);

	}

}
