/*
	input
		10 8
		1 2
		2 3
		2 4
		3 6
		3 7
		6 7
		5 8
		8 9
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
int n, m;
vector<vector<int>> a;
bool visited[1001];
void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open())
		return;
	in >> n >> m;
	a.resize(n+1, vector<int>(m+1));
	for (int i = 0; i < m; i++) {
		int x, y;
		in >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	in.close();
}
void dfs(int u) {
	visited[u] = true;
	cout << u << " ";
	for (int i : a[u]) {
		if (!visited[i])
			dfs(i);
	}
}
void connect() {
	int cnt = 0;
	visited[0] = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			++cnt;
			cout << "Cac dinh thuoc thanh phan lien thong thu " << cnt << ": ";
			dfs(i);
			cout << endl;
		}
	}
	cout << endl << cnt << endl;
}

int main() {
	readData();
	connect();

	system("pause");
	return 0;
}