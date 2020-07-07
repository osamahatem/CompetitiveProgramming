/*
 * 573B. Bear and Blocks.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int h[MAXN], ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		ans[i] = min(h[i], ans[i - 1] + 1);
	for (int i = n; i; i--)
		ans[i] = min(ans[i], ans[i + 1] + 1);
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, ans[i]);
	cout << ret << endl;
	return 0;
}
