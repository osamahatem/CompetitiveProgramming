/*
 * GSS3.cpp
 *
 *  Created on: Nov 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;
const int INF = 1 << 28;

struct node {
	int sum, bestSum, bestLeftSum, bestRightSum;

	const node operator +(const node &rightNode) const {
		node ret;
		ret.sum = sum + rightNode.sum;
		ret.bestLeftSum = max(bestLeftSum, sum + rightNode.bestLeftSum);
		ret.bestRightSum = max(rightNode.bestRightSum,
				rightNode.sum + bestRightSum);
		ret.bestSum = max(bestSum, rightNode.bestSum);
		ret.bestSum = max(ret.bestSum, bestRightSum + rightNode.bestLeftSum);
		return ret;
	}
};

int arr[MAXN], N, M;
node tree[4 * MAXN];

void build(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		tree[n] = node { arr[s], arr[s], arr[s], arr[s] };
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];

}

node query(int &qs, int &qe, int n = 1, int s = 1, int e = N) {
	if (qs > e || qe < s)
		return node { 0, -INF, -INF, -INF };
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

void update(int &tar, int &val, int n = 1, int s = 1, int e = N) {
	if (s > tar || e < tar)
		return;
	if (s == e) {
		tree[n] = node { val, val, val, val };
		return;
	}
	int mid = (s + e) / 2;
	update(tar, val, n * 2, s, mid), update(tar, val, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, a, b;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);
	build();
	scanf("%d", &M);
	while (M--) {
		scanf("%d%d%d", &t, &a, &b);
		if (t)
			printf("%d\n", query(a, b).bestSum);
		else
			update(a, b);
	}
	return 0;
}
