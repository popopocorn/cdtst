//순열

#include <vector>
using namespace std;

void comb_dfs(int start, int n, int m, vector<int>& path, vector<vector<int>>& result)
{
    if (path.size() == m)
    {
        result.push_back(path);
        return;
    }

    for (int i = start; i <= n; ++i)
    {
        path.push_back(i);
        comb_dfs(i + 1, n, m, path, result);
        path.pop_back();
    }
}

vector<vector<int>> combination(int n, int m)
{
    vector<vector<int>> result;
    vector<int> path;

    comb_dfs(1, n, m, path, result);

    return result;
}

//dfs
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs_stack(int start, const vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int cur = st.top();
        st.pop();

        if (visited[cur]) continue;

        visited[cur] = true;
        cout << cur << " ";

        // 스택은 LIFO라서 역순으로 넣어야
        // 재귀 DFS와 같은 순서가 나옴
        for (int i = graph[cur].size() - 1; i >= 0; --i)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                st.push(next);
            }
        }
    }
}

//bfs

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs_queue(int start, const vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        cout << cur << " ";

        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

// 개미전사
#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int cnt;
    cin >> cnt;
    vector<int> store(cnt);
    vector<int>dp(100, 0);
    for (int i = 0; i < cnt; ++i)
    {
        cin >> store[i];
    }
    dp[0] = store[0];
    dp[1] = max(store[0], store[1]);

    for (int i = 2; i < 4; ++i)
    {
        dp[i] = max(dp[i - 1], store[i] + dp[i - 2]);
    }
    cout << dp[3];
}

// 병사 배치하기 lis

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>soldiers(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> soldiers[i];
    }
    vector<int>dp(n, 1);

    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (soldiers[j] > soldiers[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << n - *max_element(dp.begin(), dp.end());
}
