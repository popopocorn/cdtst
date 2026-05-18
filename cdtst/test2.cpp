#include<iostream>
#include<vector>

using namespace std;

int main()
{

}
//1
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt;
	int answer = 0;
	cin >> cnt;
	vector<int>milks(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> milks[i];
	}

	sort(milks.begin(), milks.end(), [](int a, int b) {
		return a > b;
		});
	if (milks.size() <= 3)
	{
		for (int i = 0; i < milks.size() - 1; ++i)
		{
			answer += milks[i];
		}
	}
	else
	{
		int r = 0;
		for (int i = 0; i < milks.size(); ++i)
		{
			++r;
			if (r % 3 != 0)answer += milks[i];
		}
	}
	cout << answer;
}

//2
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dir[8][2] =
{
	{-1, 0},
	{-1, 1},
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
};

int find(vector<vector<char>>board, int y, int x)
{
	int answer = 0;
	vector<int>temp;
	for (int i = 0; i < 8; ++i)
	{
		int newy = y;
		int newx = x;
		int d = 0;
		while (true)
		{
			newy += dir[i][0];
			newx += dir[i][1];
			if (newy<0 || newy>board.size() - 1)break;
			if (newx<0 || newx>board[0].size() - 1)break;
			if (board[newy][newx] == '.' || board[newy][newx] == '+')
			{
				break;
			}
			++d;
		}
		temp.push_back(d);

	}
	answer = *min_element(temp.begin(), temp.end());
	return answer;
}

int main()
{
	int cnt;
	cin >> cnt;
	int n, m;
	vector<int>a;
	for (int i = 0; i < cnt; ++i)
	{
		vector<int> answer;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m));
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				cin >> board[j][k];
			}
		}

		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (board[j][k] == '+')
				{
					answer.push_back(find(board, j, k));
				}
			}
		}
		a.push_back(*max_element(answer.begin(), answer.end()));
	}

	for (int i : a)
	{
		cout << i << endl;
	}
}
//3
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt, joker;
	cin >> cnt >> joker;
	vector<char>cards(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> cards[i];
	}
	int d, k, o, r;
	d = count(cards.begin(), cards.end(), 'd');
	k = count(cards.begin(), cards.end(), 'k');
	o = count(cards.begin(), cards.end(), 'o');
	r = count(cards.begin(), cards.end(), 'r');
	int answer = 0;
	answer = {
		d * d + k * k + o * o + r * r
	};
	while (true)
	{
		k -= 2;
		o -= 2;
		r -= 1;
		d -= 1;
		if (k >= 0 && o >= 0 && r >= 0 && d >= 0)
		{
			answer += 7;
		}
		else {
			if (k > 0)k = 0;
			if (r > 0)r = 0;
			if (o > 0)o = 0;
			if (d > 0)d = 0;
			int t = k + r + o + d + joker;
			if (t >= 0)answer += 7;
			break;
		}
	}
	cout << answer;
}

//4
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, m, o;
	cin >> n >> m >> o;
	vector<vector<int>>dp(n, vector<int>(m));
	int idxY, idxX;
	idxX = o % m;
	idxY = o / n;

	dp[0][0] = 1;
	if (o != 0 && o != m * n) {
		for (int i = 0; i < idxY; ++i)
		{
			for (int j = 0; j < idxX; ++j)
			{
				if (i == 0 && j == 0)continue;
				if (i == 0)
				{
					dp[i][j] = dp[i][j - 1];
					continue;
				}
				if (j == 0)
				{
					dp[i][j] = dp[i - 1][j];
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}


		--idxX;
		--idxY;
		for (int i = idxY; i < n; ++i)
		{
			for (int j = idxX; j < m; ++j)
			{
				if (i == idxY && j == idxX)continue;
				if (i == idxY)
				{
					dp[i][j] = dp[i][j - 1];

					continue;
				}
				if (j == idxX)
				{
					dp[i][j] = dp[i - 1][j];

					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

			}
		}
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (i == 0 && j == 0)continue;
				if (i == 0)
				{
					dp[i][j] = dp[i][j - 1];
					continue;
				}
				if (j == 0)
				{
					dp[i][j] = dp[i - 1][j];
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}


	cout << dp[n - 1][m - 1];

}

//5
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;
	vector<vector<int>>board(cnt, vector<int>(cnt));
	vector<vector<int>>dp(cnt, vector<int>(cnt));

	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			cin >> board[i][j];
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			if (board[i][j] + i < cnt)dp[board[i][j] + i][j] += dp[i][j];
			if (board[i][j] + j < cnt)dp[i][board[i][j] + j] += dp[i][j];
		}
	}

	cout << dp[cnt - 1][cnt - 1] / 4;
}


//6
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>tks(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> tks[i];
	}
	int minT = 0;
	int maxT = *max_element(tks.begin(), tks.end()) * m;
	int mid = 0;
	int answer = 10e9;
	while (minT <= maxT)
	{
		mid = (minT + maxT) / 2;
		int sum = 0;

		for (int i = 0; i < n; ++i)
		{
			sum += mid / tks[i];
		}
		if (sum >= m)
		{
			if (answer > mid)answer = mid;
			maxT = mid - 1;
		}
		else
		{
			minT = mid + 1;

		}
	}
	cout << answer;
}