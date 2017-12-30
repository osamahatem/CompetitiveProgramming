/*
 * 776C. Molly's Chemicals.cpp
 *
 *  Created on: Dec 30, 2017
 *      Author: Osama Hatem
 */
 
/*
Generate all applicable powers of k. Iterate over the array and at each index,
for every power p, add to the answer the number of times sum - p appeared as an
accumulative sum at previous indices, where sum is the accumulative sum at the
current index. Used a map to keep count for simplicity.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const long long LIM = 1e15;

int n, k, arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<long long> ps;
	for (long long p = 1, i = 0; p < LIM && i < 60; p *= k, i++)
		ps.push_back(p);
	sort(ps.begin(), ps.end());
	ps.erase(unique(ps.begin(), ps.end()), ps.end());

	map<long long, int> cnt;
	cnt[0] = 1;
	long long sum = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		for (auto p : ps)
			if (cnt.count(sum - p))
				ans += cnt[sum - p];
		cnt[sum]++;
	}
	cout << ans << endl;
	return 0;
}
