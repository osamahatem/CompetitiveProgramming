/*
 * 182C. Optimal Sum.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN], n, k, len;
long long ans = 0;

struct max_k_set {
	multiset<int, greater<int>> maxi, mini;
	long long maxSum = 0, minSum = 0, k = 0;

	max_k_set() {
	}

	max_k_set(int k) {
		this->k = k;
	}

	void fix() {
		if (mini.size() && (int) maxi.size() < k) {
			int x = *(mini.begin());
			maxSum += x, minSum -= x;
			maxi.insert(x), mini.erase(mini.begin());
		}
		if (mini.size() && maxi.size() && *(--maxi.end()) < *(mini.begin())) {
			int mx = *(mini.begin()), mn = *(--maxi.end());
			maxSum += mx - mn, minSum -= mx - mn;
			maxi.erase(--maxi.end()), maxi.insert(mx);
			mini.erase(mini.begin()), mini.insert(mn);
		}
	}

	void add(int x) {
		mini.insert(x), minSum += x;
		fix();
	}

	void remove(int x) {
		if (mini.count(x))
			mini.erase(mini.find(x)), minSum -= x;
		else
			maxi.erase(maxi.find(x)), maxSum -= x;
		fix();
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> len;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> k;
	max_k_set pos(k), neg(k);
	for (int i = 0; i < len; i++)
		arr[i] < 0 ? neg.add(-arr[i]) : pos.add(arr[i]);
	for (int i = len; i <= n; i++) {
		ans = max(ans, pos.maxSum + neg.maxSum + abs(pos.minSum - neg.minSum));
		arr[i] < 0 ? neg.add(-arr[i]) : pos.add(arr[i]);
		arr[i - len] < 0 ? neg.remove(-arr[i - len]) : pos.remove(arr[i - len]);
	}
	cout << ans << endl;
	return 0;
}
