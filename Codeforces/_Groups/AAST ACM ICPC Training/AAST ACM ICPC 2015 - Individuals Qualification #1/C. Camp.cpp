/*
 * C. Camp.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int tar[26], cnt[26];
const string hayfa = "HAYFA";

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("camp.in", "r", stdin);
	tar[0] = 2, tar['H' - 'A'] = tar['Y' - 'A'] = tar['F' - 'A'] = 1;
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, k, ans = 0;
		char name[22];
		vector<int> scores;
		scanf("%d%d", &n, &k);
		while (n--) {
			int x;
			bool f1 = 0, f2 = 1;
			memset(cnt, 0, sizeof cnt);
			scanf("%s", name);
			if (count(hayfa.begin(), hayfa.end(), name[0]))
				f1 = 1;
			int sz = strlen(name);
			for (int i = 0; i < sz; i++)
				cnt[name[i] - 'A']++;
			scanf("%s%d", name, &x);
			if (count(hayfa.begin(), hayfa.end(), name[0]))
				f1 = 1;
			sz = strlen(name);
			for (int i = 0; i < sz; i++)
				cnt[name[i] - 'A']++;
			for (int i = 0; i < 26; i++)
				if (cnt[i] < tar[i])
					f2 = 0;
			if (f1 && f2)
				scores.push_back(x);
		}
		sort(scores.begin(), scores.end(), greater<int>());
		for (int i = 0; i < min((int) scores.size(), k); i++)
			ans += scores[i];
		printf("Case %d: %d\n", t, ans);
	}
	return 0;
}
