/*
 * 546C. Soldier and Cards.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

pair<long long, long long> getState(deque<int> &a, deque<int> &b) {
	long long ra = 0, rb = 0;
	for (int i = 0; i < (int) a.size(); i++)
		ra = ra * 11 + a[i];
	for (int i = 0; i < (int) b.size(); i++)
		rb = rb * 11 + b[i];
	return make_pair(ra, rb);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, x, ans = 0;
	deque<int> a, b;
	set<pair<long long, long long> > vis;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		a.push_back(x);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> x;
		b.push_back(x);
	}
	while (a.size() && b.size()) {
		ans++;
		pair<long long, long long> st = getState(a, b);
		if (!vis.count(st))
			vis.insert(st);
		else {
			cout << "-1" << endl;
			return 0;
		}
		int ca = a.front(), cb = b.front();
		a.pop_front(), b.pop_front();
		if (ca > cb) {
			a.push_back(cb);
			a.push_back(ca);
		} else {
			b.push_back(ca);
			b.push_back(cb);
		}
	}
	cout << ans << " " << (a.empty() ? 2 : 1) << endl;
	return 0;
}
