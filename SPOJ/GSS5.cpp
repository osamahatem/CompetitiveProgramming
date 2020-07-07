/*
 * GSS5.cpp
 *
 *  Created on: Dec 1, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e4 + 5;
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

node query(int qs, int qe, int n = 1, int s = 1, int e = N) {
	if (qs > qe)
		return node { 0, 0, 0, 0 };
	if (qs > e || qe < s)
		return node { 0, -INF, -INF, -INF };
	if (s >= qs && e <= qe)
		return tree[n];
	int mid = (s + e) / 2;
	return query(qs, qe, n * 2, s, mid) + query(qs, qe, n * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, x1, y1, x2, y2;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d", &arr[i]);
		build();
		scanf("%d", &M);
		while (M--) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			int res = 0;
			if (x2 > y1)
				res = query(x1, y1).bestRightSum + query(x2, y2).bestLeftSum
						+ query(y1 + 1, x2 - 1).sum;
			else if (x2 == y1) {
				res = max(query(x1, y1).bestRightSum,
						query(x2, y2).bestLeftSum);
				res = max(res,
						query(x1, y1).bestRightSum
								+ query(x2 + 1, y2).bestLeftSum);
			} else {
				res = max(query(x2, y1).bestSum,
						query(x1, x2).bestRightSum + query(y1, y2).bestLeftSum
								+ query(x2 + 1, y1 - 1).sum);
				res = max(res,
						query(x2, y1).bestRightSum
								+ query(y1 + 1, y2).bestLeftSum);
				res = max(res,
						query(x1, x2 - 1).bestRightSum
								+ query(x2, y1).bestLeftSum);
			}
			printf("%d\n", res);
		}
	}
	return 0;
}
