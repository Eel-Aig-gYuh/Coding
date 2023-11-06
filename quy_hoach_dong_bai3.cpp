// tim xau con doi xung
#include<iostream>
#include<vector>

using namespace std;
string s = "yx";
vector<vector<bool>> F(1000, vector<bool>(1000, false));


void process() {
	for (int i = 0; i < s.size(); i++) {
		F[i][i] = true;
	}

	for (int k = 1; k < s.size(); k++) {
		for (int i = 0; i < s.size() - k; i++) {
			int j = i + k;
			F[i][j] = (i + 1 > j - 1 || F[i + 1][j - 1]) && s[i] == s[j];
		}
	}

	int start = 0, end = 0;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (F[i][j] && j - i > end - start) {
				start = i;
				end = j;
			}
		}
	}
	cout << "Doan con doi xung dai nhat: " << s.substr(start, end - start + 1) << endl;
}

int main() {
	process();

	system("pause");
	return 0;
}