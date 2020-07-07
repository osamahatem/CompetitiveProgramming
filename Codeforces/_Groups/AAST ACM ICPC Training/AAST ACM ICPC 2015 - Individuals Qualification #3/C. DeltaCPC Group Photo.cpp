/*
 * C. DeltaCPC Group Photo.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("delta.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		memset(cnt, 0, sizeof cnt);
		string S;
		cin >> S;
		for (int i = 0; i < (int) S.size(); i++)
			cnt[S[i] - 'a']++;
		int ev = 0, od = 0;
		for (int i = 0; i < 26; i++)
			cnt[i] % 2 ? od++ : ev++;
		bool ans = 1;
		if (od > 1 || (S.size() % 2 == 0 && od))
			ans = 0;
		cout << "Case " << t << ": " << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
