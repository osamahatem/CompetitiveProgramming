/*
 * 12317 - Document Compression.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXK = 1 << 17;
int m, dp[MAXK], doc[105], tar;

int solve(int curDoc) {
	if (curDoc == tar)
		return 0;
	int &ret = dp[curDoc];
	if (ret != -1)
		return ret;
	ret = MAXK;
	for (int i = 0; i < m; i++) {
		if ((tar & doc[i]) != doc[i])
			continue;
		int newDoc = curDoc | doc[i];
		if (newDoc != curDoc)
			ret = min(ret, 1 + solve(newDoc));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	while (cin >> m >> n, m) {
		for (int i = 0; i < m; i++) {
			int curDoc = 0, k, b;
			cin >> k;
			while (k--) {
				cin >> b, b--;
				curDoc |= 1 << b;
			}
			doc[i] = curDoc;
//			cout << "$$ " << curDoc << "\n";
		}
		while (n--) {
			int curDoc = 0, k, b;
			cin >> k;
			while (k--) {
				cin >> b, b--;
				curDoc |= 1 << b;
			}
//			cout << "## " << curDoc << "\n";
			tar = curDoc;
			memset(dp, -1, sizeof dp);
			int temp = solve(0);
			if (temp >= MAXK)
				temp = 0;
			cout << temp;
			if (n)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
