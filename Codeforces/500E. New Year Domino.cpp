/*
 * 500E. New Year Domino.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

struct node {
	int s, e, sum, id;

	static const bool byS(const node &a, const node &b) {
		return a.s > b.s;
	}

	static const bool byID(const node &a, const node &b) {
		return a.id < b.id;
	}
};

int n, q, p[MAXN], l[MAXN];
node Q[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i], &l[i]);
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d%d", &Q[i].s, &Q[i].e);
		Q[i].s--, Q[i].e--, Q[i].id = i;
	}
	sort(Q, Q + q, node::byS);
	int idx = n - 1;
	deque<node> S;
	for (int i = 0; i < q; i++) {
		while (idx >= Q[i].s) {
			if (S.empty())
				S.push_front(node { p[idx], p[idx] + l[idx], 0, 0 });
			else {
				node cur = node { p[idx], p[idx] + l[idx], 0, 0 };
				while (S.size() && S.front().s <= cur.e) {
					cur.e = max(cur.e, S.front().e);
					S.pop_front();
				}
				if (S.size())
					cur.sum = S.front().sum + S.front().s - cur.e;
				S.push_front(cur);
			}
			idx--;
		}
		int qe = p[Q[i].e] + l[Q[i].e];
		int s = 0, e = S.size();
		while (s < e) {
			int mid = (s + e) / 2;
			if (S[mid].s <= qe)
				s = mid + 1;
			else
				e = mid;
		}
		Q[i].sum = S[0].sum;
		if (s < (int) S.size())
			Q[i].sum -= S[s].sum + S[s].s - S[s - 1].e;
	}
	sort(Q, Q + q, node::byID);
	for (int i = 0; i < q; i++)
		printf("%d\n", Q[i].sum);
	return 0;
}
