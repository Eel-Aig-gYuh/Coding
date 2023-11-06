#include<iostream>
#include<stack>
#include<string>
#include<cctype>
using namespace std;

int main() {
	stack<int>so;
	stack<char>dau;
	string s;
	int sum = 0;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			dau.push(s[i]);
		}
		else {
			so.push(s[i] - '0');
		}
		if (isdigit(s[i]) && !dau.empty()) {
			sum = so.top();
			so.pop();
			if (dau.top() == '+') {
				sum += so.top();
			}
			else {
				sum = so.top() - sum;
			}
			so.pop();
			so.push(sum);
			dau.pop();
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}