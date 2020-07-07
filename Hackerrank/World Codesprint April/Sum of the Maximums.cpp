/*
 * Sum of the Maximums.cpp
 *
 *  Created on: Jul 6, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 135005;

struct node {
	long long val, sum, pos, offset;
};

struct query {
	int l, r, id;
	long long ans;

	static const bool byL(const query &a, const query &b) {
		return a.l > b.l;
	}

	static const bool byID(const query &a, const query &b) {
		return a.id < b.id;
	}
};

int N, M, arr[MAXN];
long long tree1[MAXN], tree2[MAXN];
query Q[MAXN];
deque<node> S;

void _update(long long tree[], long long val, int idx) {
	while (idx <= N) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

long long _query(long long tree[], int idx) {
	long long ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void update(int l, int r, long long val) {
	l++, r++;
	_update(tree1, val, l), _update(tree1, -val, r + 1);
	_update(tree2, -val * (l - 1), l), _update(tree2, val * r, r + 1);
}

int binarySearch(int lim) {
	int s = 0, e = (int) S.size() - 1;
	while (s < e) {
		int mid = (s + e) / 2;
		if (S[mid].pos <= lim)
			s = mid + 1;
		else
			e = mid;
	}
	return s;
}

long long qquery(int l, int r) {
	l++, r++;
	long long ret = _query(tree1, r) * r + _query(tree2, r);
	ret -= _query(tree1, l - 1) * (l - 1) + _query(tree2, l - 1);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &Q[i].l, &Q[i].r);
		Q[i].l--, Q[i].r--;
		Q[i].id = i;
	}
	sort(Q, Q + M, query::byL);
	int idx = N - 1;
	S.push_front(node { 1 << 30, 0, N, 0 });
	for (int i = 0; i < M; i++) {
		while (idx >= Q[i].l) {
			while (arr[idx] >= S.front().val) {
				update(S[0].pos, S[1].pos - 1, S[0].val * (S[0].pos - idx));
				S.pop_front();
			}
			node temp = S[0];
			temp.val = arr[idx];
			temp.sum += temp.val * (S[0].pos - idx);
			temp.pos = idx;
			temp.offset -= temp.val * (S[0].pos - idx) * (N - 1 - idx);
			S.push_front(temp);
			idx--;
		}
		Q[i].ans = S[0].sum * (N - Q[i].l) + S[0].offset
				+ qquery(Q[i].l, Q[i].r);
		int rr = binarySearch(Q[i].r);
		Q[i].ans -= S[rr].sum * (N - Q[i].l) + S[rr].offset;
		Q[i].ans -= S[rr - 1].val * (S[rr].pos - Q[i].r - 1)
				* (S[rr - 1].pos - Q[i].l + 1);
	}
	sort(Q, Q + M, query::byID);
	for (int i = 0; i < M; i++)
		printf("%lld\n", Q[i].ans);
	return 0;
}
