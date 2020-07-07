/*
 * 334 - Identifying Concurrent Events.cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<string, int> rnk;
vector<string> inv_rnk;
int n, r, t;
char last[10], temp[10];
bool seq[200][200];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &n), n) {
		memset(seq, 0, sizeof seq);
		rnk.clear(), inv_rnk.clear(), r = 0;
		while (n--) {
			int ne;
			scanf("%d", &ne);
			for (int i = 0; i < ne; i++) {
				scanf("%s", temp);
				if (!rnk.count(temp)) {
					inv_rnk.push_back(temp);
					rnk[temp] = r++;
				}
				if (i)
					seq[rnk[last]][rnk[temp]] = 1;
				memcpy(last, temp, sizeof temp);
			}
		}
		int nm;
		scanf("%d", &nm);
		while (nm--) {
			scanf("%s%s", last, temp);
			seq[rnk[last]][rnk[temp]] = 1;
		}
		for (int k = 0; k < r; k++)
			for (int i = 0; i < r; i++)
				for (int j = 0; j < r; j++)
					seq[i][j] |= seq[i][k] & seq[k][j];
		vector<pair<string, string>> out;
		int ans = 0;
		for (int i = 0; i < r; i++)
			for (int j = i + 1; j < r; j++)
				if (!seq[i][j] && !seq[j][i]) {
					ans++;
					if (ans < 3)
						out.push_back( { inv_rnk[i], inv_rnk[j] });
				}
		printf("Case %d, ", ++t);
		if (!ans)
			printf("no concurrent events.\n");
		else {
			printf("%d concurrent events:\n", ans);
			for (int i = 0; i < min(ans, 2); i++)
				printf("(%s,%s) ", out[i].first.c_str(), out[i].second.c_str());
			printf("\n");
		}
	}
	return 0;
}
