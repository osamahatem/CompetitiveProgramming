/*
 * WILD - set.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: Osama Hatem
 */
 
/*
Assume the hero has scores x and y of the first and second type, respectively.
All enemies whose respective scores are lower are beaten and we are left with
a group that we can only beat with a third type score higher than all of them,
in other words, higher than their max. The number of such scores is m - max. The
answer is the sum of that number over all pairs of x and y.
We create a set of tuples; each tuple is a value and a range, which is the
number of scores of third type that can beat remaining enemies, describe above,
if the second type score is within that range.
We iterate over values of score of the first type in descending order, and
maintain a list of enemies we still have to beat, which is initially empty. For
each element added to this list as we iterate, let's name its score of the
second and third types y and z respectively, we update our set by removing all
ranges starting before y and having a higher number of valid options for their
third score (lower z).
Complexity: O(M + N log M) because each update operation adds at most one
element to the set, so at most N elements are added and/or deleted.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m;
long long sum;
tuple<int, int, int> skills[MAXN];
set<tuple<int, int, int>> S;

void update(int val, int idx) {
	auto it = S.upper_bound(make_tuple(val, m, m));
	int v = val, s = m + 1, e = 0;
	for (; it != S.end() && get<1>(*it) <= idx;) {
		int ss = get<1>(*it), ee = get<2>(*it);
		v = get<0>(*it), s = min(s, ss), e = max(e, ee);
		auto it2 = it++;
		S.erase(it2), sum -= 1ll * v * (ee - ss + 1);
	}
	if (s == m + 1)
		return;
	S.insert(make_tuple(val, s, idx)), sum += 1ll * val * (idx - s + 1);
	if (idx < e)
		S.insert(make_tuple(v, idx + 1, e)), sum += 1ll * v * (e - idx);
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
		S.clear();
		S.insert(make_tuple(m, 1, m)), sum = 1ll * m * m;

		int idx = n - 1;
		long long ans = 0;
		for (int i = m; i > 0; i--) {
			while (~idx && get<0>(skills[idx]) >= i) {
				update(m - get<2>(skills[idx]), get<1>(skills[idx]));
				idx--;
			}
			ans += sum;
		}
		cout << ans << endl;
	}
	return 0;
}
