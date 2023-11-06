/*
	INPUT:
		3 5
		1 1 2 2 2
		1 2 2 1 2
		3 1 1 1 2
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
int n, m;
vector<int> a;
vector<bool> visited;
vector<int> pre;
stack <int> st;
void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open()) return;
	in >> n >> m;
	a.resize(n*m);
	visited.resize(n*m, false);
	pre.resize(n*m, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			in >> a[i * n + j];
	in.close();
}
bool checkPath(int xi, int xj, int i, int j) {
	if (a[xi * n + xj] == a[i * n + j]) {
		bool v1 = (xi == i) && ((xj < n - 1 && xj + 1 == j) || (xj > 0 && xj - 1 == j));
		bool v2 = (xj == j) && ((xi < n - 1 && xi + 1 == i) || (xi > 0 && xi - 1 == i));
		return v1 || v2;
	}
	return false;
}

void dfs(int idx) {
	st.push(idx);
	pre[idx] = 1;
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		visited[x] = true;
		pre[idx]++;
		int xi = x / n;
		int xj = x % n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i * n + j] == false && checkPath(xi, xj, i, j)) {
					st.push(i * n + j);
					visited[i * n + j] = true;
				}

			}
		}
	}
}
void ex() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i * n + j] == false) {
				dfs(i * n + j);
			}
		}
	}
}
void output() {
	for (int i=0; i<n*m; i++){
		if (pre[i] > 0) {
			cout << i / n << " , " << i % n << " " << pre[i] << endl;
		}
	}
}
int main() {
	readData();
	ex();
	output();

	return 0;
}