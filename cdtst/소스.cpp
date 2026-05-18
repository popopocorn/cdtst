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

	cout << dp[cnt - 1][cnt - 1];
}

