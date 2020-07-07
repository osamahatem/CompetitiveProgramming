/*
 * HORRIBLE - BIT.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, Q;
long long bit1[MAXN], bit2[MAXN];

void _update(long long bit[], int idx, long long val) {
	for (; idx <= N; idx += idx & -idx)
		bit[idx] += val;
}

long long _query(long long bit[], int idx) {
	long long ret = 0;
	for (; idx > 0; idx -= idx & -idx)
		ret += bit[idx];
	return ret;
}

void update(int s, int e, long long val) {
	_update(bit1, s, val);
	_update(bit1, e + 1, -val);
	_update(bit2, s, -val * (s - 1));
	_update(bit2, e + 1, val * e);
}

long long query(int s, int e) {
	long long ret = _query(bit1, e) * e + _query(bit2, e);
	ret -= _query(bit1, s - 1) * (s - 1) + _query(bit2, s - 1);
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
		scanf("%d%d", &N, &Q);
		memset(bit1, 0, N * sizeof(long long));
		memset(bit2, 0, N * sizeof(long long));
		while (Q--) {
			int qt, a, b, v;
			scanf("%d%d%d", &qt, &a, &b);
			if (qt)
				printf("%lld\n", query(a, b));
			else {
				scanf("%d", &v);
				update(a, b, v);
			}
		}
	}
	return 0;
}
