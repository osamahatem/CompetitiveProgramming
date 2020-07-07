/*
 * 679B. Bear and Tower of Cubes.cpp
 *
 *  Created on: Jun 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

pair<int, long long> solve(long long m) {
	if (m < 8)
		return make_pair(m, m);
	int a = 1;
	while (1ll * a * a * a <= m)
		a++;
	a--;
	long long a3 = 1ll * a * a * a;
	a--;
	pair<int, long long> ans1 = solve(m - a3);
	ans1.first++;
	ans1.second += a3;
	pair<int, long long> ans2 = solve(a3 - 1 - 1ll * a * a * a);
	ans2.first++;
	ans2.second += 1ll * a * a * a;
	return max(ans1, ans2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long m;
	cin >> m;
	pair<int, long long> ans = solve(m);
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
