/*
	INPUT:
	5 10
	1 1 0 0 1 1 1 0 1 0
	0 0 1 1 0 0 0 1 0 1
	0 0 0 1 0 1 1 0 0 0
	0 1 1 0 0 0 1 0 1 0
	1 1 1 1 0 1 0 1 0 0
*/

#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int n, m;
vector<vector<int>> a;
vector<int> order, colors;

void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open())
		return;
	in >> n >> m;
	a.resize(n, vector<int>(m));
	order.resize(m, 0);
	colors.resize(m, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			in >> a[i][j];
	}
	in.close();
}
int color = 1;
bool canColoring(int i, int cl) {
	for (int j = 0; j < m; j++) {
		if (a[i][j] > 0 && colors[j] == cl) {
			return false;
		}
	}
	return true;
}

void coloring() {
	int maxIdx;
	do {
		color++;
		maxIdx = -1;
		// xac dinh bac cao nhat chua to
		int maxVal = INT16_MIN;
		for (int i = 0; i < n; i++) {
			if (colors[i] == 0 && order[i] > maxVal) {
				maxVal = order[i];
				maxIdx = i;
			}
		}
		// to mau cho bac cao nhat chua to va dinh khac neu co the
		colors[maxIdx] = color;
		for (int i = 0; i < n; i++) {
			if (colors[i] == 0 && canColoring(i, color))
				colors[i] = color;
		}
	} while (maxIdx > -1);
}
void output() {
	for (int i = 0; i < n; i++) {
		cout << colors[i] << "\t";
	}
	cout << endl;
}
int main() {
	readData();
	coloring();

	return 0;
}