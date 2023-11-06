#include<iostream>
#include<vector>
#include<queue>


using namespace std;
struct Edge {
	int u, v;
	int w;
};
struct Node { // dua vo de lay uu tien
	int u;
	int minTotal; // tong trong luong nho nhat tu dinh u
};

vector<vector<Edge>> e; // e[1] -> c1, c2;
int n, m;
int start, goal;
vector<int> parent;
vector<bool> visited;
vector<int> d;

void readData() {
	visited.resize(n + 1, false);
	parent.resize(n + 1, -1);
	d.resize(n + 1, INT16_MAX);
	d[start] = 0;
}

void output() {
	cout << goal;
	int u = parent[goal];
	while (u != -1 && u != start) {
		cout << " <--- " << u;
		u = parent[u];
	}
	cout << start << endl;
}

void djikstra() {
	// lay tong duong di ngan nhat
	auto cmp = [](Node n1, Node n2) {return n1.minTotal > n2.minTotal; };
	priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp); // hang doi uu tien
	// *******************************************************************

	q.push({ start, d[start] });

	while (!q.empty()) {
		Node x = q.top(); q.pop();
		
		int u = x.u;
		if (visited[u] == false) {
			visited[u] = true;

			for (auto a : e[u]) { // duyet qua cac dinh e
				int y = a.v; // lay cac canh
				if (d[y] > d[u] + a.w) {
					d[y] = d[u] + a.w;
					// luu lai parent;
					parent[y] = u;
					q.push({ y, d[y] });
				}
			}
		}
	}
}


int main() {

	return 0;
}