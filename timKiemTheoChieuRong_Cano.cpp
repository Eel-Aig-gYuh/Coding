/*
	input:
		1.5 10 1 3
		1 1
		3 1
		4 1
		1 2
		2 2
		4 2
		1 3
		2 3
		3 3
		1 5
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
struct Edge {
	int x, y;
};
double M;
int n, start, goal;
vector<Edge> e;
queue<int> q;
vector<bool> visited;
vector<int> previous;

void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open()) return;
	in >> M >> n >> start >> goal;
	start--; goal--;
	e.resize(n);
	visited.resize(n, false);
	previous.resize(n, 0);
	for (int i = 0; i < n; i++) {
		in >> e[i].x >> e[i].y;
	}
	in.close();
}
void output(){
	cout << goal + 1;
	int i = previous[goal];
	while (i != start) {
		cout << " <-- " << i + 1;
		i = previous[i];
	}
	cout << " <-- " << start + 1 << endl;
}
bool canGo(int i, int j) {
	return sqrt(pow(e[i].x - e[j].x, 2) + pow(e[i].y - e[j].y, 2)) <= M;
}
void dfs() {
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		visited[x] = true;
		q.pop();

		if (x == goal) {
			output();
			break;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (visited[i] == false && canGo(x, i)) {
					visited[i] = true;
					previous[i] = x;
					q.push(i);
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
/*
struct Edge {
	int u, v;
};


double M;
int n, start, goal; // M: so xang toi da; n: so dao; start: dinh bat dau; goal: dinh ket thuc
vector<Edge> e;
vector<bool>visited;
vector<int> previous;
queue<int> q;

void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open())
		return;

	in >> M >> n >> start >> goal;
	e.resize(n);
	visited.resize(n, false);
	previous.resize(n);

	for (int i = 0; i < n; i++) {
		in >> e[i].u >> e[i].v;
	}
	start--; goal--;

	in.close();
}
bool canGo(int i, int j) {
	double d = sqrt(pow(e[i].u - e[j].u, 2) + pow(e[i].v - e[j].v, 2));
	return d <= M;
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
		int i = q.front(); q.pop();
		visited[i] = true;

		if (i == goal) {
			printData();
			break;
		}
		else {
			for (int j = 0; j < n; j++) {
				if (visited[j] == false && kiem tra co duong di tu dinh u toi v khong canGo(i, j) == true) {
				q.push(j);
				visited[j] = true;
				previous[j] = i;
				}
			}
		}
	}
}
*/