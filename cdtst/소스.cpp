#include<iostream>
#include<vector>


using namespace std;


void pre(const vector<pair<char, char>>& tree, char root)
{
	cout << root;

	if(tree[root - 'A'].first!= '.')pre(tree, tree[root - 'A'].first);
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