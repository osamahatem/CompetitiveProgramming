/*
 * 555A. Case of Matryoshkas.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, m, x, ans = 0, left = 0;
	cin >> n >> k;
	vector<vector<int>> chains(k);
	for (int i = 0; i < k; i++) {
		cin >> m;
		while (m--) {
			cin >> x;
			chains[i].push_back(x);
		}
	}
	sort(chains.begin(), chains.end());
	for (int i = 0; i < k; i++)
		ans += (int) chains[i].size() - 1, left += chains[i].size();
	for (int i = 1; i < (int) chains[0].size() && chains[0][i] == i + 1; i++)
		ans--, left--;
	ans += left - 1;
	cout << ans << endl;
	return 0;
}
