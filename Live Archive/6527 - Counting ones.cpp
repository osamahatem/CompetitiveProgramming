#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long memo[54][2];

long long solve(int bit, bool less, long long &N) {
	if (bit < 0)
		return 0;
	long long &ret = memo[bit][less];
	if (ret != -1)
		return ret;
	if (less)
		ret = (1ll << bit) + 2ll * solve(bit - 1, less, N);
	else if (N & (1ll << bit)) {
		long long n = N ^ (1ll << bit);
		ret = solve(bit - 1, 0, n) + solve(bit - 1, 1, N);
		ret += N - (1ll << bit) + 1;
	} else
		ret = solve(bit - 1, 0, N);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	long long a , b, ans;
	while (scanf("%lld%lld", &a, &b) != EOF) {
		memset(memo, -1, sizeof memo);
		ans = solve(53, 0, b);
		memset(memo, -1, sizeof memo);
		ans -= solve(53, 0, --a);
		printf("%lld\n", ans);
	}
	return 0;
}
