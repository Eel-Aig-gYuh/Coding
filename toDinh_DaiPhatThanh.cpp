#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n;
vector<vector<int>> a;

void readData() {
	ifstream in;
	in.open("INPUT.txt", ios::in);
	if (!in.is_open()) return;
	in >> n;
	a.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			in >> a[i][j];
	in.close();
}

int main() {
	readData();

	return 0;
}