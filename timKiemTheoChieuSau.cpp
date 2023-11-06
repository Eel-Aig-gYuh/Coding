/*
	INPUT
	12
	0 0 0 0 1 1 0 0 1 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0
	0 1 0 0 0 0 0 0 0 0 0 0
	0 1 0 0 0 0 0 0 0 0 0 0
	0 0 1 1 0 1 0 0 0 0 0 0
	0 0 0 0 0 0 0 1 0 0 1 0
	0 0 0 0 0 0 0 0 0 0 0 1
	0 0 0 0 0 0 0 0 1 1 0 0
	0 0 0 0 0 0 0 0 0 1 0 0
	0 0 0 0 0 0 0 0 0 0 0 0
	0 0 0 0 0 0 1 0 0 0 0 0
	0 0 0 0 0 0 0 0 0 0 0 0
	1 12
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
int n, start, goal;
vector<vector<int>> a;
stack<int> st;
vector<bool> visited;
vector<int> previous;


void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open())
		return;
	in >> n;
	a.resize(n, vector<int>(n));
	visited.resize(n, false);
	previous.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	}
	in >> start >> goal;
	start--; goal--;
	in.close();
}

void printData(){
	cout << goal + 1;
	int i = previous[goal];
	while (i != start) {
		cout << " <-- " << i + 1;
		i = previous[i];
	}
	cout << " <-- " << start + 1 << endl;
}
void dfs() {
	st.push(start);
	while (!st.empty()) {
		int x = st.top();
		st.pop();
		visited[x] = true;
		if (x == goal) {
			printData();
			break;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (!visited[i] && a[x][i] > 0) {
					st.push(i);
					previous[i] = x;
					visited[i] = true;
				}
			}
		}
	}
}


int main() {
	readData();
	dfs();

	return 0;
}