/*
	INPUT:
		7
		2 1 9 8 15 10 11
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int n;
vector<int>a;
vector<int>L; // mang tang dan
vector<int>T; // mang luu so lon nhat
void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open()) return;
	in >> n;
	a.resize(n + 2);
	L.resize(n + 2, 0);
	T.resize(n + 2, 0);
	a[0] = INT16_MIN;
	a[n + 1] = INT16_MAX;
	for (int i = 1; i < n; i++)
		in >> a[i];
	in.close();
}
void process() {
	L[n + 1] = 1;
	for (int i = n - 1; i >= 0; i--) {
		int jmax = L[n + 1];
		for (int j = i + 1; j <= n + 1; j++) {
			if (a[j] > a[i] && L[j] > L[jmax]) {
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}
void output() {
	int i = T[0];
	while (i != n - 1) {
		cout << a[i] << "\t";
		i = T[i];
	}
	cout << endl;
}

int main() {
	readData();
	process();
	output();
	return 0;
}