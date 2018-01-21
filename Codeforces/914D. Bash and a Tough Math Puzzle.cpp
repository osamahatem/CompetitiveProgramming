/*
 * 914D. Bash and a Tough Math Puzzle.cpp
 *
 *  Created on: Jan 20, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/57250
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int N, Q, arr[MAXN], tree[4 * MAXN];

int build(int n = 1, int s = 1, int e = N) {
	if (s == e)
		return tree[n] = arr[s];
	int mid = (s + e) / 2;
	return tree[n] = __gcd(build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e));
}

int update(int &t, int &v, int n = 1, int s = 1, int e = N) {
	if (s > t || e < t)
		return tree[n];
	if (s == e)
		return tree[n] = v;
	int mid = (s + e) / 2;
	return tree[n] = __gcd(update(t, v, n * 2, s, mid),
			update(t, v, n * 2 + 1, mid + 1, e));
}

int query(int &qs, int &qe, int &v, int n = 1, int s = 1, int e = N) {
	if (s > qe || e < qs || tree[n] % v == 0)
		return 0;
	if (s == e)
		return tree[n] % v ? 1 : 0;
	if (s >= qs && e <= qe && tree[n * 2] % v != 0 && tree[n * 2 + 1] % v != 0)
		return 2;
	int mid = (s + e) / 2;
	return query(qs, qe, v, n * 2, s, mid)
			+ query(qs, qe, v, n * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	build();

	cin >> Q;
	while (Q--) {
		int t, l, r, x;
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			cout << (query(l, r, x) < 2 ? "YES" : "NO") << endl;
		} else {
			update(l, r);
		}
	}
	return 0;
}
