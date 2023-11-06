#include<iostream>
#include<vector>
#include<algorithm>

#define M 100
using namespace std;
long n = 3;
vector<long long> nums(n + 2);

long long process() {
	nums[0] = 0; nums[1] = 1;
	long long max_nums = nums[0];
	for (int i = 1; 2 * i <= n; i++) {
		nums[2 * i] = nums[i];
		nums[2 * i + 1] = nums[i] + nums[i + 1];
		max_nums = max(max_nums, nums[2 * i + 1]);
	}
	
	return max_nums;
}

int main() {
	cout << process() << endl;
	system("pause");
	return 0;
}