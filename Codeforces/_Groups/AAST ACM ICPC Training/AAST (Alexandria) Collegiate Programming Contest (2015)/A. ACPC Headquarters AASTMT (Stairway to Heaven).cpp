/*
 *  A. ACPC Headquarters AASTMT (Stairway to Heaven).cpp
 *
 *  Created on: Oct 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char buff[15];
int cnt[10000][366], r;
map<string, int> rnk;
string in;
vector<string> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("aastmt.in", "r", stdin);
	int T, n, s, e, v;
	scanf("%d", &T);
	while (T--) {
		rnk.clear(), r = 0, ans.clear();
		scanf("%d", &n);
		while (n--) {
			scanf("%*s%d%d%d", &s, &e, &v);
			while (v--) {
				scanf("%s", buff);
				in = buff;
				if (!rnk.count(in)) {
					rnk[in] = r;
					memset(cnt[r], 0, sizeof cnt[r]);
					r++;
				}
				int rr = rnk[in];
				for (int i = s; i <= e; i++)
					cnt[rr][i]++;
			}
		}
		for (auto it = rnk.begin(); it != rnk.end(); it++)
			for (int i = 1; i < 366; i++)
				if (cnt[it->second][i] > 1) {
					ans.push_back(it->first);
					break;
				}
		printf("%d\n", ans.size());
		for (int i = 0; i < (int) ans.size(); i++)
			printf("%s\n", ans[i].c_str());
	}
	return 0;
}
