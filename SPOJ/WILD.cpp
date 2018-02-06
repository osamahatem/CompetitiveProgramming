/*
 * WILD.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: Osama Hatem
 */
 
/*
Assume the hero has scores x and y of the first and second type, respectively.
All enemies whose respective scores are lower are beaten and we are left with
a group that we can only beat with a third type score higher than all of them,
in other words, higher than their max. The number of such scores is m - max. The
answer is the sum of that number over all pairs of x and y.
To calculate this, we use a segment tree: an index and a value represent a score
of the second type and the count of valid scores of the third type described
above, respectively. We iterate over values of score of the first type in
descending order, and maintain a list of enemies we still have to beat, which is
initially empty. For each element added to this list as we iterate, let's name
its score of the second and third types y and z respectively, we minimize all
indices <= y with the value of m - z, and then we add the sum of all elements in
the segment tree to the total answer.
Complexity: O(M + N log M).
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
tuple<int, int, int> skills[MAXN];
int mini[4 * MAXN], maxi[4 * MAXN], lazy[4 * MAXN];
long long sum[4 * MAXN];

void build(int idx = 1, int s = 1, int e = m) {
	if (s == e) {
		mini[idx] = m, maxi[idx] = m, sum[idx] = m, lazy[idx] = m + 1;
		return;
	}
	int mid = (s + e) / 2;
	build(idx * 2, s, mid), build(idx * 2 + 1, mid + 1, e);
	maxi[idx] = max(maxi[idx * 2], maxi[idx * 2 + 1]);
	mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
	sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
	lazy[idx] = m + 1;
}


void relax(int idx, int s, int e) {
	if (lazy[idx] > m)
		return;
	mini[idx] = maxi[idx] = lazy[idx];
	sum[idx] = 1ll * (e - s + 1) * mini[idx];
	if (s != e) {
		lazy[idx * 2] = min(lazy[idx * 2], lazy[idx]);
		lazy[idx * 2 + 1] = min(lazy[idx * 2 + 1], lazy[idx]);
	}
	lazy[idx] = m + 1;
}

void update(int qs, int qe, int v, int idx = 1, int s = 1, int e = m) {
	relax(idx, s, e);
	if (s > qe || e < qs || maxi[idx] <= v)
		return;
	if (s >= qs && e <= qe && mini[idx] > v) {
		lazy[idx] = v;
		relax(idx, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(qs, qe, v, idx * 2, s, mid);
	update(qs, qe, v, idx * 2 + 1, mid + 1, e);
	maxi[idx] = max(maxi[idx * 2], maxi[idx * 2 + 1]);
	mini[idx] = min(mini[idx * 2], mini[idx * 2 + 1]);
	sum[idx] = sum[idx * 2] + sum[idx * 2 + 1];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> n >> m, n || m) {
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			skills[i] = make_tuple(a, b, c);
		}

		sort(skills, skills + n);
		build();

		int idx = n - 1;
		long long ans = 0;
		for (int i = m; i > 0; i--) {
			while (idx >= 0 && get<0>(skills[idx]) >= i) {
				update(1, get<1>(skills[idx]), m - get<2>(skills[idx]));
				idx--;
			}
			ans += sum[1];
		}
		cout << ans << endl;
	}
	return 0;
}
