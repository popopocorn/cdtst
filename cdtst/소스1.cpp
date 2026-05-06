////////////////////////////////////////////////////////////////////////////
//백준 1100
#include<iostream>

using namespace std;

int main() {
	int cnt = 0;
	char a;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> a;
			if (i % 2 == 0) {
				if (j % 2 == 0 && a == 'F') ++cnt;
			}
			else {
				if (j % 2 != 0 && a == 'F') ++cnt;
			}
		}
	}
	cout << cnt;
}
////////////////////////////////////////////////////////////////////////////
//백준 10250
#include<iostream>

using namespace std;

int main() {
	int cnt = 0;
	int wid, hei, num;

	cin >> cnt;
	for (int i = 0; i < cnt; ++i) {
		int sol = 0;
		cin >> hei >> wid >> num;
		for (int w = 1; w < wid + 1; ++w) {
			for (int h = 1; h < hei + 1; ++h) {
				sol += 1;
				if (sol == num) {
					cout << h * 100 + w << '\n';
				}
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////
//백준 13413

#include<iostream>
#include<string>
using namespace std;

int main() {
	int cnt = 0;
	cin >> cnt;

	for (int i = 0; i < cnt; ++i) {
		int length;
		int sol = 0;
		cin >> length;
		string before;
		string after;
		cin >> before >> after;

		int beforeW = 0;
		int afterW = 0;
		int dif = 0;

		for (int j = 0; j < length; ++j)
		{
			if (before[j] == 'W') ++beforeW;
			if (after[j] == 'W') ++afterW;
			if (before[j] != after[j]) ++dif;
		}
		int dis = abs(beforeW - afterW);
		if (dis != 0)
		{
			sol += dis;
		}
		dif -= dis;
		sol += dif / 2;
		cout << sol << '\n';
	}
}

////////////////////////////////////////////////////////////////////////////
//tukorea online judge 0079

#include<iostream>
#include<string>


using namespace std;

int main()
{

	string inputStr;
	string bomb;

	cin >> inputStr >> bomb;
	bool erase = false;
	while (not erase)
	{
		size_t idx = inputStr.find(bomb);
		if (idx == string::npos) erase = true;
		else
		{
			inputStr.erase(idx, bomb.size());
		}

	}
	cout << inputStr;
}
////////////////////////////////////////////////////////////////////////////
//tukorea online judge 0071

#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main() {
	string a;
	string b;

	int w, h;


	cin >> a >> b;
	vector<vector<char>> sol(b.size(), vector<char>(a.size(), '.'));
	bool find = false;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			if (a[i] == b[j])
			{
				w = i;
				h = j;

				find = true;
				break;
			}
		}
		if (find) break;
	}
	for (int i = 0; i < a.size(); ++i) {
		sol[h][i] = a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		sol[i][w] = b[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		for (int j = 0; j < a.size(); ++j) {
			cout << sol[i][j];
		}
		cout << '\n';
	}
}


////////////////////////////////////////////////////////////////////////////
//프로그래머스 다트 

#include<iostream>
#include <string>
#include<vector>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int round = 0;

	vector<int>scoreboard;


	for (int i = 0; i < dartResult.size(); ++i)
	{

		if (isdigit(dartResult[i]))
		{
			if (isdigit(dartResult[i + 1]))
			{
				scoreboard.push_back(10);
				++i;
			}
			else
			{
				scoreboard.push_back(dartResult[i] - '0');
			}
		}
		else {
			switch (dartResult[i])
			{
			case 'S':
				if (isdigit(dartResult[i + 1])) ++round;
				break;
			case 'D':
				scoreboard[round] = pow(scoreboard[round], 2);
				if (isdigit(dartResult[i + 1])) ++round;
				break;
			case 'T':
				scoreboard[round] = pow(scoreboard[round], 3);
				if (isdigit(dartResult[i + 1])) ++round;
				break;
			case '*':
				if (round != 0)
				{
					scoreboard[round - 1] *= 2;
					scoreboard[round] *= 2;
				}
				else {
					scoreboard[round] *= 2;
				}
				++round;
				break;
			case '#':
				scoreboard[round] *= -1;
				++round;
				break;
			default:
				break;
			}
		}
	}
	for (int s : scoreboard)
	{

		answer += s;
	}

	return answer;
}

int main() {
	cout << solution("1D2S#10S");
}

////////////////////////////////////////////////////////////////////////////
//백준 11047

#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, k;
	int sol = 0;
	vector<int> coins;
	cin >> n >> k;


	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		if (v <= k)
		{
			coins.push_back(v);
		}
	}
	for (int i = coins.size() - 1; i >= 0; --i)
	{
		if (coins[i] <= k)
		{
			sol += (k / coins[i]);
			k = k % coins[i];
		}
	}
	cout << sol;
}

////////////////////////////////////////////////////////////////////////////
//백준  2798

#include<iostream>
#include<vector>

using namespace std;


int main() {
	int cnt, num;
	int sum = 0;
	vector<int>deck;
	int sol = 0;
	cin >> cnt >> num;
	int temp;
	for (int i = 0; i < cnt; ++i) {
		cin >> temp;
		deck.push_back(temp);
	}
	for (int i = 0; i < cnt - 2; ++i)
	{
		for (int j = i + 1; j < cnt - 1; ++j)
		{
			for (int k = j + 1; k < cnt; ++k) {
				temp = deck[i] + deck[j] + deck[k];
				if (temp <= num && sol < temp)
				{

					sol = temp;

				}
			}
		}
	}
	cout << sol;
}

////////////////////////////////////////////////////////////////////////////
//tukorea 0067

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt = 0;
	vector<char> pme;
	vector<int> height;
	cin >> cnt;
	char temp;
	int h = 0;
	for (int i = 0; i < cnt; ++i)
	{

		cin >> temp;
		switch (temp)
		{
		case '+':
			pme.push_back('/');
			height.push_back(h);
			++h;
			break;
		case '-':
			--h;
			pme.push_back('\\');
			height.push_back(h);
			break;
		case '=':
			pme.push_back('_');
			height.push_back(h);
			break;
		default:
			break;
		}
	}
	auto [minit, maxit] = minmax_element(height.begin(), height.end());
	int min = *minit;
	int max = *maxit;


	for (int& n : height)
	{
		n -= min;
	}
	h = max - min + 1;
	vector<vector<char>> sol;
	sol.resize(h, vector<char>(cnt, '.'));
	for (int j = 0; j < cnt; ++j) {

		sol[h - 1 - height[j]][j] = pme[j];
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < cnt; ++j)
		{
			cout << sol[i][j];
		}
		cout << '\n';
	}


}


////////////////////////////////////////////////////////////////////////////
//tukorea 0099

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

struct food {
	int tan;
	int dan;
	int gi;
};

struct nutSum {
	int maxT;
	int maxD;
	int maxG;
	int maxC;

};

nutSum Cal(vector<food> foods)
{
	nutSum sum{};
	for (const food& f : foods)
	{
		sum.maxT += f.tan;
		sum.maxD += f.dan;
		sum.maxG += f.gi;

		sum.maxC += f.tan * 4 + f.dan * 4 + f.gi * 9;
	}
	return sum;

}
void combination(vector<food> list, vector<vector<food>>& result,
	int size, int startidx,
	vector<food> temp)
{

	if (temp.size() == size)
	{
		result.push_back(temp);
		return;
	}

	for (int i = startidx; i < list.size(); ++i) {

		temp.push_back(list[i]);
		combination(list, result, size, i + 1, temp);
		temp.pop_back();

	}

}


int main()
{
	int cnt, t, d, g;

	int maxT, maxD, maxG, maxC;
	int solution = 0;

	cin >> cnt;
	vector<food> foodlist;
	vector<vector<food>> sol;
	vector<food> temp;
	for (int i = 0; i < cnt + 1; ++i)
	{
		if (i < cnt) {
			cin >> t >> d >> g;
			foodlist.push_back({ t,d, g });
		}
		else {
			cin >> maxT >> maxD >> maxG >> maxC;
		}

	}

	for (int i = 1; i < 4; ++i) {
		combination(foodlist, sol, i, 0, temp);
	}
	for (const vector<food>& f : sol)
	{
		nutSum sum = Cal(f);
		if (sum.maxC > maxC) continue;
		if (sum.maxT > maxT) continue;
		if (sum.maxD < maxD) continue;
		if (sum.maxG > maxG) continue;
		++solution;
	}
	cout << solution;


}

////////////////////////////////////////////////////////////////////////////
//프로그래머스 체육복

#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> students(n, 1);
	for (int i : lost) --students[i - 1];
	for (int i : reserve) ++students[i - 1];

	for (int i = 0; i < n; ++i)
	{
		if (students[i] == 0)
		{
			if (i > 0)
			{
				if (students[i - 1] > 1)
				{
					++students[i];
					--students[i - 1];

					continue;
				}

			}
			if (i < n - 1)
			{
				if (students[i + 1] > 1)
				{
					++students[i];
					--students[i + 1];

					continue;
				}
			}
		}
	}
	answer = n - count(students.begin(), students.end(), 0);

	return answer;
}

int main()
{
	int n = 5;
	vector<int> lost = { 2, 4 };
	vector<int> reserve = { 1,3,5 };

	cout << solution(n, lost, reserve);
}

////////////////////////////////////////////////////////////////////////////
//백준 1260

#include<iostream>
#include<deque>
#include<queue>
#include<algorithm>

using namespace std;

void DFS(vector<vector<bool>> graph, int start)
{
	int startIdx = start - 1;
	vector<int> done;
	vector<bool> visit(graph[startIdx].size(), false);

	deque<int> DFSStack;

	DFSStack.push_back(startIdx);

	int travel;
	while (!DFSStack.empty()) {

		int first = DFSStack.back();
		DFSStack.pop_back();
		if (not visit[first])
		{
			visit[first] = true;
			done.push_back(first + 1);
		}

		for (int i = graph[first].size() - 1; i > -1; --i)
		{
			if (i == first) continue;
			if (graph[first][i])
			{
				if (not visit[i])
				{
					DFSStack.push_back(i);

				}
			}
		}


	}
	for (int n : done)
	{
		cout << n << ' ';
	}
	cout << '\n';
}


void BFS(vector<vector<bool>> graph, int start)
{
	int startIdx = start - 1;

	vector<int> done;
	vector<bool>visit(graph[0].size(), false);
	queue<int>BFSQueue;
	BFSQueue.push(startIdx);


	while (not BFSQueue.empty())
	{
		int first = BFSQueue.front();
		BFSQueue.pop();
		if (not visit[first])
		{
			done.push_back(first + 1);
			visit[first] = true;
		}
		for (int i = 0; i < graph[first].size(); ++i) {
			if (not visit[i] && graph[first][i])
			{
				BFSQueue.push(i);
				visit[i] = true;
				done.push_back(i + 1);
			}
		}

	}
	for (int n : done)
	{
		cout << n << ' ';
	}
	cout << '\n';

}

int main()
{
	int vertex;
	int line;
	int start;

	cin >> vertex >> line >> start;

	vector<vector<bool>> graph;
	graph.resize(vertex, vector<bool>(vertex, false));

	for (int i = 0; i < line; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1 - 1][v2 - 1] = true;
		graph[v2 - 1][v1 - 1] = true;
	}

	DFS(graph, start);
	BFS(graph, start);

}

////////////////////////////////////////////////////////////////////////////
//백준 1697

#include<iostream>
#include<queue>
#include<array>

using namespace std;

const int MAX = 100'001;
array<int, MAX> dist;



int main()
{
	int n, k;
	cin >> n >> k;
	dist.fill(-1);
	int depth = 0;
	if (n == k)
	{
		cout << depth;
		return 0;
	}

	queue<int>BFSQueue;

	dist[n] = 0;
	BFSQueue.push(n);
	while (not BFSQueue.empty())
	{
		int first = BFSQueue.front();
		BFSQueue.pop();


		array<int, 3> p;
		p[0] = first - 1;
		p[1] = first + 1;
		p[2] = first * 2;

		for (int num : p)
		{
			if (num < 0 || num > MAX - 1) continue;
			if (dist[num] == -1)
			{
				dist[num] = dist[first] + 1;
				BFSQueue.push(num);
			}
			if (num == k) {
				cout << dist[num] << '\n';
				return 0;
				break;
			}

		}

	}

}

////////////////////////////////////////////////////////////////////////////
//tukorea 중요한 교차로

#include<iostream>
#include<vector>
#include<deque>

using namespace std;

bool DFS(int start, int ban, const vector<vector<bool>>& graph, vector<bool>& visited)
{
	deque<int> stack;
	stack.push_back(start);
	while (not stack.empty())
	{
		int first = stack.back();
		stack.pop_back();
		for (int i = graph[first].size() - 1; i >= 0; --i)
		{
			if (i == first)continue;
			if (i != ban && graph[first][i] && not visited[i])
			{
				visited[i] = true;
				stack.push_back(i);
			}
		}
	}
	for (int i = 0; i < visited.size(); ++i)
	{
		if (i == ban) continue;
		if (!visited[i]) return true;
	}
	return false;
}
int main()
{
	int cross, doro;
	cin >> cross >> doro;
	vector<vector<bool>> graph;
	vector<int>sol;
	graph.resize(cross, vector<bool>(cross));
	int x, y;
	for (int i = 0; i < doro; ++i)
	{
		cin >> x >> y;
		graph[x - 1][y - 1] = true;
		graph[y - 1][x - 1] = true;

	}

	for (int i = 0; i < cross; ++i)
	{
		int v;
		vector<bool>visited(cross, false);
		if (i == 0) v = 1;
		else v = 0;
		if (DFS(v, i, graph, visited))
		{
			sol.push_back(i + 1);
		}

	}
	cout << sol.size() << '\n';
	for (int n : sol)
	{
		cout << n << '\n';
	}


}

////////////////////////////////////////////////////////////////////////////
//프로그래머스 여행경로
//다음 행선지가 없는 순서대로 리스트에 넣고 뒤집기
#include <string>
#include <vector>
#include <map>
#include<algorithm>
#include<iostream>

using namespace std;

void dfs(string cur, map<string, vector<string>>& airports, vector<string>& answer)
{
	while (not airports[cur].empty())
	{
		string next = airports[cur][0];
		airports[cur].erase(airports[cur].begin());
		dfs(next, airports, answer);
	}
	answer.push_back(cur);
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	map<string, vector<string>> airports;
	for (int i = 0; i < tickets.size(); ++i)
	{
		airports[tickets[i][0]].push_back(tickets[i][1]);
	}

	for (auto& pair : airports)
	{
		sort(pair.second.begin(), pair.second.end());
	}

	dfs("ICN", airports, answer);

	reverse(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<vector<string>> tickets = { {"ICN", "JFK"},{"HND", "IAD"},{"JFK", "HND"} };
	vector<string> temp = solution(tickets);
	for (const string& s : temp)
	{
		cout << s << '\n';
	}
}

////////////////////////////////////////////////////////////////////////////
//백준 1987

#include<iostream>
#include<vector>

using namespace std;

int dir[4][2] =
{
	{1, 0},
	{-1, 0},
	{0, -1},
	{0, 1},
};

void dfs(const vector<vector<char>>& board, vector<bool>& visited,
	int curr, int curc, int dist, int& sol)
{
	int R = board.size();
	int C = board[0].size();
	if (dist > sol)
		sol = dist;
	for (int i = 0; i < 4; ++i)
	{
		int nr = curr + dir[i][0];
		int nc = curc + dir[i][1];
		if (0 <= nr && nr < R && 0 <= nc && nc < C
			&& not visited[board[nr][nc] - 'A']
			)
		{
			visited[board[nr][nc] - 'A'] = true;
			dfs(board, visited, nr, nc, dist + 1, sol);
			visited[board[nr][nc] - 'A'] = false;
		}

	}

}

int main()
{
	int r, c;
	cin >> r >> c;
	vector<vector<char>> board;
	vector<bool>visited(26, false);
	board.resize(r, vector<char>(c));

	string temp;
	for (int i = 0; i < r; ++i) {
		cin >> temp;
		for (int j = 0; j < c; ++j) {
			board[i][j] = temp[j];
		}
	}

	int sol = 0;
	visited[board[0][0] - 'A'] = true;
	dfs(board, visited, 0, 0, 1, sol);

	cout << sol;

}

////////////////////////////////////////////////////////////////////////////
//백준 4963

#include<iostream>
#include<vector>
#include<deque>
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
void bfs(
	int startx, int starty,
	vector<vector<int>>& board,
	vector<vector<int>>& visited,
	int w, int h)
{
	deque<pair<int, int>> q;
	q.push_back({ starty, startx });
	visited[starty][startx] = 1;

	while (not q.empty())
	{
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop_front();

		for (int i = 0; i < 8; ++i)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];

			if (ny >= 0 && ny < h && nx >= 0 && nx < w)
			{
				if (board[ny][nx] == 1 && visited[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					q.push_back({ ny, nx });
				}
			}

		}

	}


}

void dfs(int y, int x, int h, int w, vector<vector<int>>& board, vector<vector<int>>& visited) {
	visited[y][x] = 1; // 현재 위치 방문 처리

	// 8방향 탐색
	for (int i = 0; i < 8; ++i) {
		int ny = y + dir[i][0];
		int nx = x + dir[i][1];

		// 맵의 범위를 벗어나지 않고
		if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
			// 땅(1)이면서 아직 방문하지 않은 곳이라면 재귀적으로 파고듦
			if (board[ny][nx] == 1 && visited[ny][nx] == 0) {
				dfs(ny, nx, h, w, board, visited);
			}
		}
	}
}

int main()
{
	int w, h;


	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)return 0;

		vector<vector<int>> board(h, vector<int>(w, 0));
		vector<vector<int>> visited(h, vector<int>(w, 0));
		int temp1;
		int cnt{};

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				cin >> temp1;
				board[i][j] = temp1;
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == 1 && visited[i][j] == 0)
				{
					bfs(j, i, board, visited, w, h);
					++cnt;
				}
			}
		}

		cout << cnt << '\n';

	}
}

////////////////////////////////////////////////////////////////////////////
//백준 1991 트리순회

#include<iostream>
#include<vector>


using namespace std;


void pre(const vector<pair<char, char>>& tree, char root)
{
	cout << root;

	if (tree[root - 'A'].first != '.')pre(tree, tree[root - 'A'].first);
	if (tree[root - 'A'].second != '.')pre(tree, tree[root - 'A'].second);

}

void in(const vector<pair<char, char>>& tree, char root)
{
	if (tree[root - 'A'].first != '.')in(tree, tree[root - 'A'].first);
	cout << root;
	if (tree[root - 'A'].second != '.')in(tree, tree[root - 'A'].second);
}

void post(const vector<pair<char, char>>& tree, char root)
{
	if (tree[root - 'A'].first != '.')post(tree, tree[root - 'A'].first);
	if (tree[root - 'A'].second != '.')post(tree, tree[root - 'A'].second);
	cout << root;

}

int main()
{
	int cnt;

	cin >> cnt;

	vector<pair<char, char>> tree(26);

	char root, ln, rn;

	for (int i = 0; i < cnt; ++i)
	{
		cin >> root >> ln >> rn;

		tree[root - 'A'].first = ln;
		tree[root - 'A'].second = rn;

	}
	pre(tree, 'A');
	cout << '\n';
	in(tree, 'A');
	cout << '\n';
	post(tree, 'A');


}

////////////////////////////////////////////////////////////////////////////
//백준 13416 주식투자

#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int main()
{
	int CaseCnt, day;
	cin >> CaseCnt;

	for (int i = 0; i < CaseCnt; ++i)
	{
		cin >> day;
		int sol = 0;
		for (int j = 0; j < day; ++j)
		{
			int t;
			int max = INT_MIN;
			for (int k = 0; k < 3; ++k)
			{
				cin >> t;
				if (t > max)
				{
					if (t > 0) max = t;
					else max = 0;
				}
			}
			sol += max;

		}
		cout << sol << endl;
	}

}

////////////////////////////////////////////////////////////////////////////
//백준 1931 회의실 배정
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct meet {
	int beg;
	int end;
};

int main()
{
	int cnt;
	cin >> cnt;
	vector<meet> time;
	for (int i = 0; i < cnt; ++i)
	{
		int b, e;
		cin >> b >> e;
		time.push_back({ b,e });
	}
	sort(time.begin(), time.end(), [](const meet& a, const meet& b)
		{
			if (a.end == b.end) return a.beg < b.beg;
			return a.end < b.end;
		});

	int sol = 0;
	int last = 0;
	for (int i = 0; i < cnt; ++i) {
		if (time[i].beg >= last)
		{
			++sol;
			last = time[i].end;
		}
	}
	cout << sol;
}



////////////////////////////////////////////////////////////////////////////
//tukorea 행렬 게임

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int a, b;
	int t = 1;
	cin >> a >> b;
	vector<vector<int>> M(a, vector<int>(b));
	cout << "M\n";
	for (int i = 0; i < a; ++i)
	{
		for (int j = 0; j < b; ++j)
		{
			cout << t;
			M[i][j] = t;
			++t;
			if (j != b - 1)cout << ' ';
		}
		cout << endl;
	}
	cout << "R\n";
	vector<vector<int>> R(b, vector<int>(a));
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			R[i][j] = M[a - 1 - j][i];
			cout << R[i][j];
			if (j != a - 1)cout << ' ';
		}
		cout << endl;
	}
	cout << "L\n";
	vector<vector<int>> L(b, vector<int>(a));
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			L[i][j] = M[j][b - 1 - i];
			cout << L[i][j];
			if (j != a - 1)cout << ' ';
		}
		cout << endl;
	}
	cout << "T\n";
	vector<vector<int>> T(b, vector<int>(a));
	for (int i = 0; i < b; ++i)
	{
		for (int j = 0; j < a; ++j)
		{
			T[i][j] = M[j][i];
			cout << T[i][j];
			if (j != a - 1)cout << ' ';
		}
		cout << endl;
	}

}


////////////////////////////////////////////////////////////////////////////
//프로그래머스 실패율

#include <string>
#include <vector>
#include<algorithm>
#include<iostream>

using namespace std;

struct stage {
	int num;
	int player;
	int notclear;

};

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<stage> clearRatio(N);


	for (int i = 0; i < N; ++i)
	{
		clearRatio[i].num = i + 1;
		for (int n : stages)
		{
			if (n == clearRatio[i].num)
			{
				++clearRatio[i].notclear;
				++clearRatio[i].player;
			}

			if (n > clearRatio[i].num)
			{
				++clearRatio[i].player;
			}
		}
	}
	sort(clearRatio.begin(), clearRatio.end(),
		[](const stage& a, const stage& b) {
			float ratioa = 0;
			float ratiob = 0;
			if (a.player != 0)
				ratioa = (float)a.notclear / a.player;

			if (b.player != 0)
				ratiob = (float)b.notclear / b.player;
			if (ratioa == ratiob) {
				return a.num < b.num;
			}
			return ratioa > ratiob;
		});
	for (int i = 0; i < N; ++i) {
		answer.push_back(clearRatio[i].num);
	}
	return answer;
}

int main()
{
	int N = 5;
	vector<int> a = { 2, 1, 2, 6, 2, 4, 3, 3 };
	vector<int> sol = solution(N, a);

	for (int i : sol)
	{
		cout << i << ' ';
	}
}



////////////////////////////////////////////////////////////////////////////
// 2차시험 범위
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
//백준 14469 소가 건너간 이유

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main()
{
	int cnt, b, e;
	cin >> cnt;
	vector<pair<int, int>>cows(cnt);

	for (int i = 0; i < cnt; ++i)
	{
		cin >> b >> e;
		cows[i] = { b, e };
	}

	sort(cows.begin(), cows.end());

	int time = 0;
	for (int i = 0; i < cnt; ++i)
	{
		time = max(time, cows[i].first) + cows[i].second;
	}
	cout << time;
}

////////////////////////////////////////////////////////////////////////////
//백준 2805  나무자르기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt, m;
	cin >> cnt >> m;
	vector<int>trees(cnt);

	for (int i = 0; i < cnt; ++i)
	{
		cin >> trees[i];
	}
	int h = *max_element(trees.begin(), trees.end());

	long long start = 0;
	long long end = h;
	int result = 0;

	while (start <= end)
	{
		long long sum = 0;
		long long mid = (end + start) / 2;
		for (int i = 0; i < cnt; ++i)
		{
			if (trees[i] > mid)
				sum += trees[i] - mid;
		}
		if (sum >= m)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << result;
}


////////////////////////////////////////////////////////////////////////////
//백준 13420 사칙연산

#include<iostream>
#include<vector>
#include<string>

using namespace std;



int main()
{
	int cnt;
	cin >> cnt;

	for (int i = 0; i < cnt; ++i)
	{
		long long a, b, c;
		char op, t;
		bool correct = false;
		cin >> a >> op >> b >> t >> c;
		switch (op)
		{
		case '*':
			if (a * b == c)correct = true;
			break;
		case '+':
			if (a + b == c)correct = true;
			break;
		case'-':
			if (a - b == c)correct = true;
			break;
		case'/':
			if (a / b == c)correct = true;
			break;

		}
		if (correct)
		{
			cout << "correct\n";
		}
		else
		{
			cout << "wrong answer\n";
		}
	}

}

////////////////////////////////////////////////////////////////////////////
//tukorea postfix 

#include<iostream>
#include<deque>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string postfix;
	deque<string>answer;
	cin >> postfix;

	for (int i = 0; i < postfix.size(); ++i)
	{
		if (isalpha(postfix[i]))
		{
			answer.push_back(string(1, postfix[i]));
		}
		else {
			string a = answer.back();
			answer.pop_back();
			string b = answer.back();
			answer.pop_back();
			answer.push_back(string("(") + b + postfix[i] + a + ")");

		}
	}
	for (string s : answer)
	{
		for (char c : s)
		{
			cout << c;
		}
	}

}

////////////////////////////////////////////////////////////////////////////
//프로그래머스 비밀지도 

#include <string>
#include <vector>
#include<iostream>

using namespace std;

vector<string> solution1(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n, string(n, ' '));

	for (int i = 0; i < n; ++i)
	{
		int num = arr1[i];
		for (int j = 0; j < n; ++j)
		{
			if (num % 2 == 1)answer[i][n - j - 1] = '#';
			num /= 2;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int num = arr2[i];
		for (int j = 0; j < n; ++j)
		{
			if (num % 2 == 1)answer[i][n - j - 1] = '#';
			num /= 2;
		}
	}
	return answer;
}

int main()
{
	int n = 5;
	vector<int>arr1 = { 9, 20, 28, 18, 11 };
	vector<int>arr2 = { 30, 1, 21, 17, 28 };
	solution1(n, arr1, arr2);
}

////////////////////////////////////////////////////////////////////////////
//백준 어두운 굴다리

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int len, cnt;
	cin >> len >> cnt;
	vector<int>loc(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> loc[i];
	}

	int start = 0;
	int end = len;
	int sol = 0;
	while (start <= end)
	{
		int h = (start + end) / 2;
		int last = 0;
		bool blank = false;
		for (int i = 0; i < cnt; ++i)
		{
			if (loc[i] - h > last)
			{
				blank = true;
			}
			else
			{
				last = loc[i] + h;
			}
		}
		if (last < len)blank = true;
		if (blank)
		{
			start = h + 1;
		}
		else
		{
			end = h - 1;
			sol = h;
		}


	}

	cout << sol;


}


////////////////////////////////////////////////////////////////////////////
//tukorea  공유기 설치

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool check(int mid, vector<int> house, int cnt)
{
	int sol = 1;
	int last = house[0];
	for (int i = 1; i < house.size(); ++i) {
		if (house[i] - last >= mid)
		{
			last = house[i];
			++sol;
		}
	}
	return sol >= cnt;
}

int main()
{
	int h, cnt;
	cin >> h >> cnt;
	vector<int> house(h);
	for (int i = 0; i < h; ++i)
	{
		cin >> house[i];
	}

	sort(house.begin(), house.end());

	int start = 0;
	int end = house[house.size() - 1];
	int sol = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (check(mid, house, cnt))
		{
			sol = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

	}
	cout << sol;
}

////////////////////////////////////////////////////////////////////////////
//tukorea 예산 

#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>

using namespace std;

int main()
{
	int cnt, money;
	cin >> cnt;

	vector<int>budget(cnt);


	for (int i = 0; i < cnt; ++i)
	{
		cin >> budget[i];
	}
	cin >> money;

	if (accumulate(budget.begin(), budget.end(), 0) <= money)
	{
		cout << *max_element(budget.begin(), budget.end());
		return 0;
	}

	int start = 0;
	int end = *max_element(budget.begin(), budget.end());
	int sol = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		int a = accumulate(budget.begin(), budget.end(), 0,
			[mid](int a, int b)->int {
				if (mid >= b)
				{
					a += b;
				}
				else
				{
					a += mid;
				}
				return a;
			});
		if (a <= money)
		{
			start = mid + 1;
			sol = mid;
		}
		else
		{
			end = mid - 1;
		}

	}

	cout << sol;
}


////////////////////////////////////////////////////////////////////////////
//tukorea 설탕배달

#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int kg;
	cin >> kg;
	vector<int>dp(kg + 1, 1e9);
	dp[0] = 0;
	vector<int>t = { 3, 5 };
	for (int k : t)
	{
		for (int j = k; j < kg + 1; ++j)
		{
			if (dp[j - k] != 1e9)dp[j] = min(dp[j], dp[j - k] + 1);
		}
	}
	if (dp[kg] != 1e9)cout << dp[kg];
	else cout << "-1";

}

////////////////////////////////////////////////////////////////////////////
//tukorea 1만들기
#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n];
}

////////////////////////////////////////////////////////////////////////////
//tukorea 부분수열합

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;
	vector<int>su(cnt);
	vector<int>dp(cnt);
	for (int i = 0; i < cnt; ++i)
	{
		cin >> su[i];
		dp[i] = su[i];
	}

	for (int i = 1; i < cnt; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (su[j] < su[i])dp[i] = max(dp[i], dp[j] + su[i]);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}

////////////////////////////////////////////////////////////////////////////
//tukorea rbg거리


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int cnt;
	cin >> cnt;
	vector<vector<int>> house(cnt, vector<int>(3));
	vector<vector<int>> dp(cnt, vector<int>(3));


	for (int i = 0; i < cnt; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin >> house[i][j];
			dp[i][j] = house[i][j];
		}
	}
	for (int i = 1; i < cnt; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			dp[i][j] =
				min(dp[i - 1][(j + 1) % 3] + dp[i][j], dp[i - 1][(j + 2) % 3] + dp[i][j]);
		}
	}
	cout << *min_element(dp[cnt - 1].begin(), dp[cnt - 1].end());
}

////////////////////////////////////////////////////////////////////////////
//프로그래머스 베스트 앨범

#include <string>
#include <vector>
#include<map>
#include<iostream>
#include<algorithm>

using namespace std;

struct song {
	int num;
	int plays;
};

struct record {
	int total = 0;
	vector<song>s;
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, record> p;
	for (int i = 0; i < genres.size(); ++i)
	{
		p[genres[i]].total += plays[i];
		p[genres[i]].s.push_back({ i, plays[i] });
	}
	vector<pair<string, record>> temp(p.begin(), p.end());
	sort(temp.begin(), temp.end(), [](const pair<string, record>& a, const pair<string, record>& b) {
		return a.second.total > b.second.total;
		});
	for (auto& m : temp)
	{
		sort(m.second.s.begin(), m.second.s.end(), [](const song& a, const song& b) {
			if (a.plays == b.plays) return a.num < b.num;
			return a.plays > b.plays;
			});
	}
	for (const auto& m : temp)
	{
		for (int i = 0; i < 2 && i < m.second.s.size(); ++i)
		{
			answer.push_back(m.second.s[i].num);
		}
	}

	return answer;
}

int main()
{
	vector<string> g = { "classic", "pop", "classic", "classic", "pop" };
	vector<int>p = { 500, 600, 150, 800, 2500 };
	vector<int> a = solution(g, p);
	for (int n : a)
	{
		cout << n << endl;
	}

}

////////////////////////////////////////////////////////////////////////////
//tukorea rbg거리

////////////////////////////////////////////////////////////////////////////
//tukorea rbg거리

////////////////////////////////////////////////////////////////////////////
//tukorea rbg거리