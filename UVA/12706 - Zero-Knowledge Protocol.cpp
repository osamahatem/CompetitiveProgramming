/*
 * 12706 - Zero-Knowledge Protocol.cpp
 *
 *  Created on: Aug 9, 2014
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

	int t, arr[20005];
	scanf("%d", &t);
	while (t--) {
		int n, m, x;
		multiset<int> all;
		multiset<int>::iterator it;
		queue<int> cur;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			all.insert(x);
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			it = all.find(arr[i]);
			if (it == all.end()) {
				if (cur.size()) {
					all.insert(cur.front());
					cur.pop();
					i--;
				}
			} else {
				cur.push(*it);
				all.erase(it);
				if ((int) cur.size() == m) {
					ans += (i - m + 2) * (i - m + 2);
					if (cur.size()) {
						all.insert(cur.front());
						cur.pop();
					}
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
