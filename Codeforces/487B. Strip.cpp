/*
 * 487B. Strip.cpp
 *
 *  Created on: Jul 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

class monotonic_queue {
	deque<pair<int, int>> Q;
	function<bool(int, int)> cmp;

public:
	monotonic_queue(function<bool(int, int)> _cmp) {
		cmp = _cmp;
	}

	int front() {
		return Q.front().first;
	}

	void popToIdx(int idx) {
		while (Q.size() && Q.front().second < idx)
			Q.pop_front();
	}

	void push(int val, int idx) {
		while (Q.size() && cmp(val, Q.back().first))
			Q.pop_back();
		Q.push_back(make_pair(val, idx));
	}

	bool empty() {
		return Q.size() == 0;
	}
};

bool lessThan(int a, int b) {
	return a < b;
}

bool greaterThan(int a, int b) {
	return a > b;
}

int dpArr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, s, l, x, curS = -1;
	monotonic_queue mini(lessThan), maxi(greaterThan), dp(lessThan);
	cin >> n >> s >> l;
	if (l > n) {
		cout << "-1" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		mini.push(x, i), maxi.push(x, i);
		int curMin = mini.front(), curMax = maxi.front();
		while (curMax - curMin > s) {
			curS++;
			mini.popToIdx(curS), maxi.popToIdx(curS);
			curMin = mini.front(), curMax = maxi.front();
		}
		if (i == l - 1)
			dp.push(0, -1);
		if (i >= l && dpArr[i - l])
			dp.push(dpArr[i - l], i - l);
		dp.popToIdx(curS - 1);
		if (dp.empty())
			dpArr[i] = 0;
		else
			dpArr[i] = dp.front() + 1;
	}
	cout << (!dpArr[n - 1] ? -1 : dpArr[n - 1]) << endl;
	return 0;
}
