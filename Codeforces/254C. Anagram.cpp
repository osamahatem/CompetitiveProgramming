/*
 * 254C. Anagram.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[26], extra[26];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif

	string s, t;
	int steps = 0;
	cin >> s >> t;
	for (int i = 0; i < (int) s.size(); i++)
		cnt[t[i] - 'A']++, extra[s[i] - 'A']++;
	for (int i = 0; i < 26; i++) {
		extra[i] -= cnt[i];
		steps += max(extra[i], 0);
	}
	int cur = 0;
	for (int i = 0; i < (int) s.size() && cur < 26; i++) {
		if (extra[cur] >= 0) {
			cur++, i--;
			continue;
		}
		int let = s[i] - 'A';
		if ((cur < let && extra[let] > 0) || (!cnt[let])) {
			s[i] = cur + 'A';
			extra[let]--;
			extra[cur]++;
			cnt[cur]--;
		} else {
			cnt[let]--;
		}
	}
	cout << steps << endl << s << endl;
	return 0;
}
