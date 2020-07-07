/*
 * Squares and Points.cpp
 *
 *  Created on: Sep 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct event {
	int x, y;

	const bool operator <(const event &E) const {
		if (x != E.x)
			return x < E.x;
		return y < E.y;
	}
};

vector<int> rnk;

int tree[(int) 12e5 + 5], lazy[(int) 12e5 + 5];

void relax(int n, int s, int e) {
	tree[n] += lazy[n] * (e - s + 1);
	if (s != e)
		lazy[n * 2] += lazy[n], lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void update(int qs, int qe, int v, int n = 1, int s = 0,
		int e = (int) rnk.size() - 1) {
	relax(n, s, e);
	if (qs > e || qe < s)
		return;
	if (s >= qs && e <= qe) {
		lazy[n] += v;
		relax(n, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, v, n * 2, s, mid), update(qs, qe, v, n * 2 + 1, mid + 1, e);
	tree[n] = tree[n * 2] + tree[n * 2 + 1];
}

int query(int q, int n = 1, int s = 0, int e = (int) rnk.size() - 1) {
	relax(n, s, e);
	if (q > e || q < s)
		return 0;
	if (s == e)
		return tree[n];
	int mid = (s + e) / 2;
	return query(q, n * 2, s, mid) + query(q, n * 2 + 1, mid + 1, e);
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int n, m, l;
	scanf("%d%d%d", &n, &m, &l);
	vector<event> squares(n), points(m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &squares[i].x, &squares[i].y);
		rnk.push_back(squares[i].y), rnk.push_back(squares[i].y + l);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &points[i].x, &points[i].y);
		rnk.push_back(points[i].y);
	}
	sort(squares.begin(), squares.end());
	sort(points.begin(), points.end());
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	memset(tree, 0, sizeof tree), memset(lazy, 0, sizeof lazy);
	int s = 0, e = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		while (e < n && squares[e].x <= points[i].x) {
			int qs = lower_bound(rnk.begin(), rnk.end(), squares[e].y)
					- rnk.begin();
			int qe = lower_bound(rnk.begin(), rnk.end(), squares[e].y + l)
					- rnk.begin();
			update(qs, qe, 1);
			e++;
		}
		while (s < n && squares[s].x + l < points[i].x) {
			int qs = lower_bound(rnk.begin(), rnk.end(), squares[s].y)
					- rnk.begin();
			int qe = lower_bound(rnk.begin(), rnk.end(), squares[s].y + l)
					- rnk.begin();
			update(qs, qe, -1);
			s++;
		}
		int q = lower_bound(rnk.begin(), rnk.end(), points[i].y) - rnk.begin();
		ans = max(ans, query(q));
	}
	printf("%d\n", ans);
	return 0;
}
