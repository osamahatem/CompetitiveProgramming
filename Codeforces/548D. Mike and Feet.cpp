/*
 * 548D. Mike and Feet.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: Osama Hatem
 */
 
/*
We start with an empty list of intervals, and as we work our way through the
values, sorted in decreasing order, we add them and update our active intervals.
The 'insert' functions performs this update in O(1) and returns the length of
the affected interval, post-update. For each value, the maximum length interval
is the longest contiguous sub-array this value can be the answer of.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, st[MAXN], en[MAXN];
int ans[MAXN];
vector<pair<int, int>> pos;

int insert(int p) {
	int ret = 0;
	if (st[p + 1] != -1 && en[p - 1] != -1) {
		int s = en[p - 1], e = st[p + 1];
		st[s] = e, en[e] = s;
		st[p + 1] = en[p - 1] = -1;
		ret = e - s + 1;
	} else if (st[p + 1] != -1) {
		int e = st[p + 1];
		st[p] = e, en[e] = p;
		st[p + 1] = -1;
		ret = e - p + 1;
	} else if (en[p - 1] != -1) {
		int s = en[p - 1];
		st[s] = p, en[p] = s;
		en[p - 1] = -1;
		ret = p - s + 1;
	} else {
		st[p] = en[p] = p;
		ret = 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		pos.push_back(make_pair(x, i + 1));
	}
	sort(pos.rbegin(), pos.rend());
	memset(st, -1, sizeof st);
	memset(en, -1, sizeof en);
	int last = 0;
	for (int i = 0; i < n; i++) {
		int idx = i, cur = last;
		while (idx < n && pos[idx].first == pos[i].first)
			cur = max(cur, insert(pos[idx++].second));
		for (int j = last + 1; j <= cur; j++)
			ans[j] = pos[i].first;
		last = cur;
		i = idx - 1;
	}
	for (int i = 1; i <= n; i++) {
		if (i > 1)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
