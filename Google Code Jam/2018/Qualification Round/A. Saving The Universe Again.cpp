/*
 * A. Saving The Universe Again.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int T, D;
string S;

bool change() {
	for (int i = (int) S.size() - 2; ~i; i--)
		if (S[i] == 'C' && S[i + 1] == 'S') {
			swap(S[i], S[i + 1]);
			return true;
		}
	return false;
}

int evaluate() {
	int p = 1, ret = 0;
	for (int i = 0; S[i]; i++)
		if (S[i] == 'C')
			p <<= 1;
		else
			ret += p;
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> D >> S;
		int ans = 0;
		while (evaluate() > D && change())
			ans++;
		cout << "Case #" << t << ": ";
		if (evaluate() <= D)
			cout << ans << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
