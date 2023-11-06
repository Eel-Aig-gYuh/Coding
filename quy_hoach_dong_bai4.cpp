#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> w = { 3, 1, 5, 6, 8, 2 };
int m = w.size();
vector<int> v = { 1, 2, 4, 3, 6, 8 };
int n = v.size();

vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));
vector<int> T(L.size(), 0);

void process() {
	for (int i = 1; i < m+1; i++) {
		for (int j = 1; j < n+1; j++) {
			L[i][j] = 1;
			if (w[i - 1] == v[j - 1]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else {
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
	}
}
void output() {
	/*for (int i = 0; i < m + 1; i++) {
		for (int j = 0; j < n + 1; j++) {
			cout << L[i][j] << "   ";
		}
		cout << endl;
	}*/
	int i = m, j = n;
	while (i > 0 && j > 0) {
		if (w[i - 1] == v[j - 1]) {
			cout << w[i - 1] << "     ";
			i--;
			j--;
		}
		else if (L[i - 1][j] > L[i][j - 1]) {
			i--;
		}
		else 
			j--;
	}
}

int main() {
	process();
	output();
	getchar();
	return 0;
}