#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Item {
	int w;
	int v;
};
vector<Item> a = {
	{3, 30},
	{4, 50},
	{5, 60}
};
long long n = a.size();
int capacity = 8;
vector<vector<long long>> L(n + 1, vector<long long>(capacity + 1, 0));

int process() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= capacity; j++) {
			L[i][j] = L[i - 1][j];
			
			if (a[i].w <= capacity) {
				L[i][j] = max(L[i][j], L[i - 1][j - a[i - 1].w + a[i - 1].v]);
			}
		}
	}
	return L[n][capacity];
}

int main() {
	cout << process() << endl;


	system("pause");
	return 0;
}