
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Edge {
	int u, v;
	int w;
};
vector<Edge> e;
vector<int> parent;
vector<int> r; // dem chi so de chon cha

bool join(int u, int v) { // kiem tra chu trinh
	u = getRoot(u);
	v = getRoot(v);
	if (u != v) { // khac goc thi nhan
		// hop nhat cay
		if (r[u] == r[v]) {
			r[u]++;
		}
		if (r[u] > r[v]) {
			parent[v] = u;
		}
		else {
			parent[u] = v;
		}

		return true;
	}
	return false;
}

int getRoot(int u) {
	while (u != parent[u]) {
		u = parent[u];
	}
	return u;
}
vector<Edge> Kruskal() {
	// sap xep canh tang dan theo trong so
	sort(e.begin(), e.end(), [](Edge a, Edge b) {return a.w < b.w; });

	// tim cay khung
	vector<Edge> re;
	for (Edge a : e) {
		if (join(a.u, a.v)) {
			re.push_back(a);
		}
	}
	return re;
}


int main() {
	return 0;
}