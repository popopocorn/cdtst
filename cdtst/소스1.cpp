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
//백준 1260



////////////////////////////////////////////////////////////////////////////
//백준 1260


