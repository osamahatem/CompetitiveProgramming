/*
 * 1928. Another Ecology Problem.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int m, k;
bool vis[10005];
pair<int, int> memo[10005];

pair<int, int> best(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first)
		return (a.first > b.first ? a : b);
	return (a.second < b.second ? a : b);
}

pair<int, int> solve(int left) {
	if (left == 0)
		return make_pair(0, 0);
	if (k > left)
		return make_pair(max(left, m), 0);
	if (vis[left])
		return memo[left];
	vis[left] = 1;
	pair<int, int> ret = make_pair(0, 0), temp;
	for (int i = 1; i <= k; i++) {
		temp = solve(left - i);
		swap(temp.first, temp.second);
		temp.first += i;
		ret = best(ret, temp);
	}
	return memo[left] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d%d%d", &n, &m, &k);
	pair<int, int> ans = solve(n);
	printf("%d %d\n", ans.first, ans.second);
	return 0;
}
