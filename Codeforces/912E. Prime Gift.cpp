/*
 * 912E. Prime Gift.cpp
 *
 *  Created on: Jan 27, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56920
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long LIM = 1e18;

int n, p[16];
long long k;
vector<long long> A, B;

void gen(int idx, long long cur, vector<long long> &vec) {
	if (idx >= n) {
		vec.push_back(cur);
		return;
	}
	gen(idx + 2, cur, vec);
	if (cur <= LIM / p[idx])
		gen(idx, cur * p[idx], vec);
}

long long check(long long x) {
	long long ret = 0;
	int idx = (int) B.size() - 1;
	for (int i = 0; i < (int) A.size(); i++) {
		while (~idx && A[i] > x / B[idx])
			idx--;
		ret += idx + 1;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	cin >> k;

	gen(0, 1, A), gen(1, 1, B);
	sort(A.begin(), A.end()), sort(B.begin(), B.end());

	long long s = 1, e = 1e18;
	while (s < e) {
		long long mid = (s + e) / 2;
		if (check(mid) >= k)
			e = mid;
		else
			s = mid + 1;
	}
	cout << s << endl;
	return 0;
}
