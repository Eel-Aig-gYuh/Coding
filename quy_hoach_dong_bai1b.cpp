#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
struct Meet {
	double start, end;
};
vector<Meet> w{
	{0, 0},
	{2, 3}, {5, 7}, {2, 4}, {11, 14}, {5, 6},
	{24, 24}
};
int n = w.size() - 2;
vector<int> L(n + 2, 0);
vector<int> T(n + 2, 0);

bool compe(Meet a, Meet b) {
	return (a.end < b.start);
}

void process() { // sap xep mang don tang theo gio ket thuc
	L[n + 1] = 1;
	sort(w.begin(), w.end(), [](Meet a, Meet b) {return b.end > a.end; });
	for (int i = n; i >= 0; i--) {
		int jmax = n + 1;
		for (int j = i + 1; j < n + 1; j++) {
			if (compe(w[i], w[j]) && L[j] > L[jmax]) {
				jmax = j;
			}
		}
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}

void output() {
	int i = 0; 
	while (i != n + 1) {
		if (i != 0) {
			cout << "{" << w[i].start << ", " << w[i].end << "}  ";
		}
		i = T[i];
	}
}

int main() {
	process();
	output();



	system("pause");
	return 0;
}