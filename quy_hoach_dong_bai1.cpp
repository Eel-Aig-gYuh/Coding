/*
	sap phong hop{
	b1: sx cac phan tu tang dan theo gio ket thuc
	b2: tim doan con tang dan trong danh sach nay
	x < y --> x.end < y.start
	}

	tim doan con don tang dai nhat (khong can lien tiep);
	b1: xay dung bang ket qua L: L[i] la do dai doan con tang dai nhat
	duyet nguoc tim gia tri lon hon va co L lon nhat thi cong 1
	
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>w = { INT16_MIN, 11, 2, 7, 9, 10, 6, 15, 8, INT16_MAX };
int n = w.size() - 2;
vector<int>L(n+2, 0);
vector<int>T(n+2, 0);

void process() {
	L[n + 1] = 1;
	for (int i = n; i >= 0; i--) {
		int jmax = n+1;
		for (int j = i + 1; j <= n+1; j++) {
			if (w[j] > w[i] && L[j] > L[jmax]) {
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}
void output() {
	for (int i = 0; i < L.size(); i++) {
		cout << L[i] << "  ";
	}
	cout << endl;

	int i = 0;
	while (i != n - 1) {
		cout << w[i] << "  ";
		i = T[i];
	}
	cout << endl;
}

int main() {
	process();
	output();

	getchar();
	return 0;
}