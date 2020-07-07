#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long memo[70];

long long solve(int n) {
	if (n < 2)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	long long &ret = memo[n];
	if (ret != -1)
		return ret;
	return ret = solve(n - 1) + solve(n - 2) + solve(n - 3) + solve(n - 4);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	memset(memo, -1, sizeof memo);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", solve(n));
	}
	return 0;
}
