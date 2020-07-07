/*
 * NEO01.cpp
 *
 *  Created on: Jun 3, 2017
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

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, x, cnt = 0;
		long long sum = 0, ans = 0;
		vector<int> neg;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &x);
			if (x < 0)
				ans += x, neg.push_back(x);
			else
				cnt++, sum += x;
		}
		sort(neg.begin(), neg.end(), greater<int>());
		for (int i = 0; i < (int) neg.size(); i++) {
			if ((sum + neg[i]) * (cnt + 1) > sum * cnt)
				ans -= neg[i], sum += neg[i], cnt++;
		}
		ans += sum * cnt;
		printf("%lld\n", ans);
	}
	return 0;
}
