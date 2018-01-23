/*
 * 3565 - Bit Compressor.cpp
 *
 *  Created on: Jan 22, 2018
 *      Author: Osama Hatem
 */
 
/*
Constraints are tight enough to make a simple recursive function trying all
possibilities pass in time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string msg;
int L, N;

int solve(int idx, int l, int n) {
	if (l > L || n > N)
		return 0;
	if (idx == (int) msg.size())
		return l == L && n == N;
	int ret = 0;
	if (msg[idx] == '0')
		ret += solve(idx + 1, l + 1, n);
	else {
		int ones = 0, x = 0;
		for (int i = idx; x <= L - l && ret < 2 && i < (int) msg.size(); i++) {
			x = x * 2 + msg[i] - '0';
			ones += msg[i] == '1';
			if (msg[i + 1] != '1') {
				if (x < 4 && msg[i] != '0')
					ret += solve(i + 1, i + 1 - idx + l, ones + n);
				if (x > 2 && x + l <= L && x + n <= N)
					ret += solve(i + 1, x + l, x + n);
			}
		}
	}
	return min(ret, 2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> L >> N, L || N) {
		cin >> msg;
		int ans = solve(0, 0, 0);
		cout << "Case #" << ++T << ": "
				<< (ans == 2 ? "NOT UNIQUE" : (ans ? "YES" : "NO")) << endl;
	}
	return 0;
}
