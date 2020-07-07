/*
 * IEEE Electronic Devices Society.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int arr[2 * MAXN], n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]), arr[n + i] = arr[i];
	multiset<int> s;
	multiset<int>::iterator it;
	for (int i = 0; i < m; i++)
		s.insert(arr[i]);
	while ((int) s.size() > k)
		s.erase(--s.end());
	int ans = *(--s.end());
	for (int i = 1; i < n; i++) {
		it = s.lower_bound(arr[i - 1]);
		if (it != s.end() && *it == arr[i - 1])
			s.erase(it);
		s.insert(arr[i + m - 1]);
		if ((int) s.size() > k)
			s.erase(--s.end());
		ans = min(ans, *(--s.end()));
	}
	printf("%d\n", ans);
	return 0;
}
