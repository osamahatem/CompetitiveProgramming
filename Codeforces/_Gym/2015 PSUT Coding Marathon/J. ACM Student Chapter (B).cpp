/*
 * J. ACM Student Chapter (B).cpp
 *
 *  Created on: Sep 3, 2015
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

	int n, h, m, s, ans = 0;
	scanf("%d", &n);
	vector<int> times;
	for (int i = 0; i < n; i++) {
		scanf("%d%*c%d%*c%d", &h, &m, &s);
		times.push_back(h * 3600 + m * 60 + s);
	}
	sort(times.begin(), times.end());
	multiset<int> av;
	for (int i = 0; i < n; i++) {
		int t = times[i] + 15 * 60;
		if (av.size() && *(av.begin()) + 15 * 60 <= times[i] + 3 * 3600) {
			t = max(times[i], *(av.begin())) + 15 * 60;
			av.erase(av.begin());
		} else
			ans++;
		av.insert(t);
		cout << ans << " " << av.size() << endl;
	}
	printf("%d\n", ans);
	return 0;
}
