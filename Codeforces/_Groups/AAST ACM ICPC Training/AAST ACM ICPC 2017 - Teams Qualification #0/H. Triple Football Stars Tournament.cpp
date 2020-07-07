#include <bits/stdc++.h>

using namespace std;

int n;
long long dp[100005][4];
map<pair<int, int>, int> cnt;
vector<int> cnts;

long long solve(int idx, int lft) {
	if (idx == (int)cnts.size())
		return lft ? 0 : 1;
	long long &ret = dp[idx][lft];
	if (~ret)
		return ret;
	ret = solve(idx + 1, lft);
	if (lft)
		ret += cnts[idx] * solve(idx + 1, lft - 1);
	return ret;
}

pair<int, int> slope(int x1, int y1, int x2, int y2) {
	int dy = y2 - y1, dx = x1 - x2;
	if (dx == 0)
		return make_pair(1, 0);
	if (dy == 0)
		return make_pair(0, 1);
	if (dx < 0)
		dx *= -1, dy *= -1;
	int g = __gcd(abs(dx), abs(dy));
	return make_pair(dy / g, dx / g);
}

int main () {
	freopen("tournament.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		cnt.clear();
		cnts.clear();
		memset(dp, -1, sizeof dp);
		scanf("%d", &n);
		while (n--) {
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			cnt[slope(x1, y1, x2, y2)]++;
		}
		for (auto it : cnt)
			cnts.push_back(it.second);
		printf("%lld\n", solve(0, 3));
	}
	return 0;
}
