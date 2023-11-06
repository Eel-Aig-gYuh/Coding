#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
int n;
vector<vector<int>> a;
vector<vector<bool>> b;
vector<bool>visited;
vector<int>previous;
stack<int> q;

void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open())
		return;
	in >> n;
	a.resize(n, vector<int>(n));
	b.resize(n, vector<bool>(n, false));
	visited.resize(n, false);
	previous.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	}
	in.close();
}
int bfs(int x) {
	int sizeSlicks = 1;
	q.push(x);
	
	while (!q.empty()) {
		int i = q.top();
		q.pop();
		b[x][i] = true;
		for (int j = 0; j < n; j++) {
			if (b[x][j] == false && a[i][j] == 1) {
				q.push(j);
				//visited[j] = true;
				b[x][j] = true;
				previous[j] = i;
				sizeSlicks++;
			}
		}
	}
	
	return sizeSlicks;
}


int main() {
	readData();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && !b[i][j]) {
				cout << bfs(i) << "\t";
			}
		}
	}


	return 0;
}