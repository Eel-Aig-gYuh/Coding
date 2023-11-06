#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Item {
	long w, v;
};
vector<Item> a = {
	{15, 7},
	{8, 20},
	{5, 10},
	{25, 25},
	{18, 11}
};
long n = a.size();
int k = 36;
vector<vector<int>> L(n + 1, vector<int>(k + 1, 0));

void process() {
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			L[i][j] = L[i - 1][j];

			if (j >= a[i - 1].w /* kiem tra khoi luong phu hop voi ba lo */ && L[i - 1][j - a[i - 1].w + a[i - 1].v] > L[i - 1][j]) {
				L[i][j] = L[i - 1][j - a[i - 1].w + a[i - 1].v];
			}
		}
	}
}
void output() {
	cout << L[n][k] << endl;
	int i = n, j = k;
	while (i > 0 && j > 0) {
		if (j >= a[i - 1].w /* kiem tra khoi luong phu hop voi ba lo */ && L[i - 1][j - a[i - 1].w + a[i - 1].v] > L[i - 1][j]) {
			cout << "khoi luong: " << a[i].w << " ; " << "gia tri: " << a[i].v << endl;
			j -= a[i].w;
		}
		i--;
	}
}

int main() {
	process();
	output();
	getchar();
	return 0;
}