/*
 * CTRICK.cpp
 *
 *  Created on: Dec 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1 << 15;

int N, tree[MAXN], ans[MAXN];

void update(int idx, int val) {
	while (idx < MAXN) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int goRight(int idx) {
	if (idx & 1)
		return 0;
	return idx + ((idx & -idx) >> 1);
}

int goLeft(int idx) {
	if (idx & 1)
		return 0;
	return idx - ((idx & -idx) >> 1);
}

int findKth(int K) {
	int idx = MAXN / 2, ret = idx;
	while (idx) {
		if (tree[idx] < K) {
			K -= tree[idx];
			idx = goRight(idx);
		} else {
			ret = idx;
			idx = goLeft(idx);
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		memset(tree, 0, sizeof tree);
		for (int i = 1; i <= N; i++)
			update(i, 1);
		int last = 0;
		for (int i = 1; i <= N; i++) {
			int mod = N - i + 1;
			int K = query(last) + i + 1;
			K = ((K - 1) % mod) + 1;
			int pos = findKth(K);
			ans[pos] = i;
			last = pos;
			update(pos, -1);
		}
		for (int i = 1; i <= N; i++) {
			if (i > 1)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
