#include<iostream>
using namespace std;
int const n = 8;
int queens[n];

void inkq() {
	for (int i = 0; i < n; i++) {
		int k = queens[i];
		for (int j = 0; j < n; j++) {
			if (k == j)
				cout << "Q";
			else
				cout << "0";
		}
		cout << endl;
	}
	system("pause");
}
int canPut(int k, int j) {
	for (int i = 0; i < k; i++) {
		if (queens[i] == j || abs(i-k) == abs(queens[i] - j))
			return 0;
	}
	return 1;
}

void Try(int idx) {
	for (int i = 0; i < n; i++) {
		if (canPut(idx, i) == 1) {
			queens[idx] = i;

			if (idx < n - 1) {
				Try(idx + 1);
			}
			else {
				inkq();
			}
		}
	}
}


int main() {
	Try(0);

	system("pause");
	return 0;
}