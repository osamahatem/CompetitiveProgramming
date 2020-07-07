/*
 * 690D3. The Wall (hard).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1000003;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int c, w, h, hw = 1;
	cin >> c >> w >> h;
	for (int i = 0; i <= w; i++)
		hw = hw * h % MOD;
	queue<int> Q;
	Q.push(1);
	int ans = 1, sum = 1;
	for (int i = 0; i <= c; i++) {
		if ((int) Q.size() > w + 1) {
			sum = (sum - 1ll * hw * Q.front() % MOD);
			if (sum < 0)
				sum += MOD;
			Q.pop();
		}
		ans = sum;
		sum = sum * h % MOD;
		sum = (sum + ans) % MOD;
		Q.push(ans);
	}
	cout << ans << endl;
	return 0;
}
