/*
 * 81C. Average Score.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int val, idx;

	static const bool byVal1(const node &a, const node &b) {
		if (a.val != b.val)
			return a.val > b.val;
		return a.idx < b.idx;
	}

	static const bool byVal2(const node &a, const node &b) {
		if (a.val != b.val)
			return a.val > b.val;
		return a.idx > b.idx;
	}

	static const bool byIdx(const node &a, const node &b) {
		return a.idx < b.idx;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	vector<node> all(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &all[i].val);
		all[i].idx = i;
	}
	int cur = 1, idx = 0;
	if (b < a) {
		swap(a, b), cur = 2;
		sort(all.begin(), all.end(), node::byVal2);
	} else if (a < b)
		sort(all.begin(), all.end(), node::byVal1);
	while (a--)
		all[idx++].val = cur;
	cur = 3 - cur;
	while (b--)
		all[idx++].val = cur;
	sort(all.begin(), all.end(), node::byIdx);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", all[i].val);
	}
	printf("\n");
	return 0;
}
