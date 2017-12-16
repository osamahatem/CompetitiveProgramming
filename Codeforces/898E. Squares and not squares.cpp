/*
 * 898E. Squares and not squares.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: Osama Hatem
 */
 
/*
Greedily convert piles until you reach n / 2 piles of each type.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int LIM = 2e9 + 5;

vector<int> sqs;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i <= LIM / i; i++)
		sqs.push_back(i * i);

	int n;
	cin >> n;
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int idx = lower_bound(sqs.begin(), sqs.end(), x) - sqs.begin();
		if (x == sqs[idx])
			a.push_back(1 + (x == 0));
		else
			b.push_back(min(sqs[idx] - x, x - sqs[idx - 1]));
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int aa = a.size(), bb = b.size(), idx = 0;
	long long ans = 0;
	while (aa < n / 2)
		ans += b[idx++], aa++;
	while (bb < n / 2)
		ans += a[idx++], bb++;
	cout << ans << endl;
	return 0;
}
