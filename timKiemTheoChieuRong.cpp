/*
	input
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
#include<vector>
#include<fstream>
#include<queue>
using namespace std;
int n;
vector<vector<int>> a;
vector<bool> visited; // visited[i] = true; -> da tham
vector<int> previous; // previous[i] = j; -> mang luu vet dinh truoc i la j
queue<int> q;
int start, goal;

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
void printData() {
	cout << goal + 1;
	int i = previous[goal];
	while (i != start) {
		cout << " <-- " << i + 1;
		i = previous[i];
	}
	cout << " <-- " << start + 1 << endl;
}
void bfs() {
	q.push(start);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		visited[x] = true;

		if (x == goal) {
			printData();
			break;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (visited[i] == false && a[x][i] > 0) {
					q.push(i);
					visited[i] = true;
					previous[i] = x;
				}
			}
		}
	}
}

int main() {
	readData();
	bfs();

	system("pause");
	return 0;
}