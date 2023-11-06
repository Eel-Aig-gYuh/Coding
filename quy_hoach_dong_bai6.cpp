#include<iostream>
#include<vector>
using namespace std;
vector<int> a = { 4, 2, 3, 1, 6, 9, 89 };
int n = a.size();
int s = 12;

vector<vector<int>> L(n + 1, vector<int>(s + 1, 0));


void process() {
	// khoi tao mang L[i][0] la true
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < s + 1; j++) {
			
		}
	}
}
void output() {
	cout << L[n][s] << endl;
}
int main() {
	process();
	output();

	getchar();
	return 0;
}