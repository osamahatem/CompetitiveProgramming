/*
 * 555C. Case of Chocolate - Segment Tree.cpp
 *
 *  Created on: Jun 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXQ = 2e5 + 5;
const int MAXN = 2 * MAXQ;

struct qu {
	int x, y;
	char t;
};

qu Q[MAXQ];
set<int> used;
map<int, int> rnk;
int ver[4 * MAXN][2], hor[4 * MAXN][2], inv_rnk[MAXN], r = 1;

void relax(int n, int s, int e, int arr[][2]) {
	arr[n][0] = max(arr[n][0], arr[n][1]);
	if (s != e) {
		arr[n * 2][1] = max(arr[n * 2][1], arr[n][1]);
		arr[n * 2 + 1][1] = max(arr[n * 2 + 1][1], arr[n][1]);
	}
	arr[n][1] = 0;
}

int query(int arr[][2], int q, int n = 1, int s = 0, int e = MAXN - 1) {
	relax(n, s, e, arr);
	if (s > q || e < q)
		return 0;
	if (s == e)
		return arr[n][0];
	int mid = (s + e) / 2;
	return max(query(arr, q, n * 2, s, mid),
			query(arr, q, n * 2 + 1, mid + 1, e));
}

void update(int arr[][2], int qs, int qe, int v, int n = 1, int s = 0,
		int e = MAXN - 1) {
	relax(n, s, e, arr);
	if (s > qe || e < qs)
		return;
	if (s >= qs && e <= qe) {
		arr[n][1] = max(arr[n][1], v);
		relax(n, s, e, arr);
		return;
	}
	int mid = (s + e) / 2;
	update(arr, qs, qe, v, n * 2, s, mid);
	update(arr, qs, qe, v, n * 2 + 1, mid + 1, e);
	arr[n][0] = max(arr[n * 2][0], arr[n * 2 + 1][0]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(ver, 0, sizeof ver);
	memset(hor, 0, sizeof hor);
	rnk[0] = inv_rnk[0] = 0;
	int n, q, temp;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%*c%c", &Q[i].x, &Q[i].y, &Q[i].t);
		used.insert(Q[i].x), used.insert(Q[i].y);
	}
	for (set<int>::iterator it = used.begin(); it != used.end(); it++) {
		rnk[*it] = ++r;
		inv_rnk[r] = *it;
	}
	for (int i = 0; i < q; i++) {
		Q[i].x = rnk[Q[i].x], Q[i].y = rnk[Q[i].y];
		if (Q[i].t == 'U') {
			temp = query(hor, Q[i].x);
			cout << inv_rnk[Q[i].y] - inv_rnk[temp] << "\n";
			update(ver, temp, Q[i].y, Q[i].x);
			update(hor, Q[i].x, Q[i].x, Q[i].y);
		} else {
			temp = query(ver, Q[i].y);
			cout << inv_rnk[Q[i].x] - inv_rnk[temp] << "\n";
			update(hor, temp, Q[i].x, Q[i].y);
			update(ver, Q[i].y, Q[i].y, Q[i].x);
		}
	}
	return 0;
}
