/*
 * J. Delete the Letters.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char a[1000005], b[1000005];
vector<int> nxt[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("delete.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;
		scanf("%s%d", a, &n);
		int len = strlen(a);
		for (int i = 0; i < 26; i++)
			nxt[i].clear();
		for (int i = 0; a[i]; i++)
			nxt[a[i] - 'a'].push_back(i);
		for (int i = 0; i < 26; i++)
			nxt[i].push_back(len);
		while (n--) {
			scanf("%s", b);
			int i = 0, j = 0;
			for (; b[j]; j++) {
				int idx = lower_bound(nxt[b[j] - 'a'].begin(),
						nxt[b[j] - 'a'].end(), i) - nxt[b[j] - 'a'].begin();
				i = nxt[b[j] - 'a'][idx];
				if (i == len)
					break;
				i++;
			}
			if (!b[j])
				ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}
