/*
 * 917A. The Monster.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: Osama Hatem
 */
 
/*
Greedily try to always replace all '?' with ')', and swap them later as needed.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int) s.size(); i++) {
		int op = 0, w = 0;
		for (int j = i; j < (int) s.size(); j++) {
			if (s[j] == '(') {
				op++;
			} else if (s[j] == ')') {
				if (!op && !w) {
					op = -1;
					break;
				}
				if (op)
					op--;
				else
					w--, op++;
			} else {
				if (op)
					op--, w++;
				else
					op++;
			}
			if (op == 0)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
