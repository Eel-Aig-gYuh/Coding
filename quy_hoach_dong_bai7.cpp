#include<iostream>
#include<vector>

using namespace std;
int n = 8;
vector<long long> a (n+1);

long long process()
{
	a[0] = 2; a[1] = 3; a[2] = 4;
	for (long long i = 3; i <= n; i++) {
		a[i] = 3*a[i - 1] + 2*a[i - 2] + 4*a[i-3]; // cong thuc truy hoi
	}
	return a[n];
}

long long F(int n) {
	if (n == 0)
		return 2;
	else if (n == 1)
		return 3;
	else if (n == 2) {
		return 4;
	}
	else {
		return 3 * F(n - 1) + 2 * F(n - 2) + 4 * F(n - 3);
	}
}


int main() {
	cout << process() << endl;
	cout << F(8) << endl;
	system("pause");
	return 0;
}