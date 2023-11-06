// robot quet voi
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<string>w = {
	"159",
	"123",
	"357",
	"147",
	"5",
	"369",
	"456",
	"789",
	"258"
};
string s = "XVXVXVTXT";
string target = "TTTTTTTTT";

vector<int>x(w.size(), 0); // x[i] la so lan goi robot (x[i] <= 2)
int total = 0; // tong so lan goi robot

vector<int>best(w.size(), 0);
int totalBest = INT16_MAX; // so lan goi it nhat

void update() {
	if (total < totalBest) {
		totalBest = total;
		best = x;
	}
}

void fillColor(string &s, int i) {
	string rooms = w[i]; // phong robot thu i chiu trach nhiem
	for (int i = 0; i < rooms.size(); i++) {
		int idx = (rooms[i] - '0') - 1; // idx: so thu tu trong phong
		switch (s[idx]) {
		case 'T':
			s[idx] = 'X';
			break;
		case 'X':
			s[idx] = 'V';
			break;
		case 'V':
			s[idx] = 'T';
			break;
		}
	}
}

int selectedRobot() {
	int max = INT16_MIN;
	int selected = -1;
	for (int i = 0; i < w.size(); i++) { // duyet qua cac phong
		if (x[i] < 2) { // so lan duyet it hon 2
			string t = s;
			fillColor(t, i);

			int count = (int)count_if(t.begin(), t.end(), [](char c) {return c == 'T'; }); // dem mau trang
			if (count > max) {
				max = count;
				selected = i;
			}
		}
	} 

	return selected;
}

void process(int idx) {
	int i = selectedRobot();
	if (i>=0){
		x[i]++;
		total++;
		fillColor(s, i);
		if (s == target) {
			update();
		}
		else {
			process(idx + 1);
		}
		x[i]--;
		total--;
	}
}
void output() {
	for (int i = 0; i < best.size(); i++) {
		for (int j = 0; j < best[i]; j++) {
			cout << i + 1;
		}
		cout << endl;
	}
}

int main() {
	process(0);
	output();

	getchar();
	return 0;
}