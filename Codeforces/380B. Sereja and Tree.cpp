/*
 * 380B. Sereja and Tree.cpp
 *
 *  Created on: Mar 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 7e3 + 5;

struct query {
	int l, r, x;
};

int N, Q;
vector<query> qPerLvl[MAXN];

int getLog(int x) {
	int ret = 0;
	for (int i = 1; i < x; i <<= 1)
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &Q);
	while (Q--) {
		int t, lvl, l, r, x;
		scanf("%d%d%d", &t, &lvl, &l);
		if (t == 1) {
			scanf("%d%d", &r, &x);
			qPerLvl[lvl].push_back(query { l, r, x });
		} else {
			set<int> ans;
			int s = l, e = l;
			for (int i = lvl; i <= N; i++) {
				for (int j = 0; j < (int) qPerLvl[i].size(); j++)
					if (qPerLvl[i][j].l <= e && qPerLvl[i][j].r >= s)
						ans.insert(qPerLvl[i][j].x);
				s += getLog(s), e += getLog(e) + !(e & (e - 1));
			}
			printf("%d\n", ans.size());
		}
	}
	return 0;
}
