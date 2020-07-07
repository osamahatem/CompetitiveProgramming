/*
 * 12656 - Almost Palindrome.cpp
 *
 *  Created on: Aug 31, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int k;
string s;

bool check(int a, int b) {
	int diff = 0;
	for (int i = a; diff <= k && b - i + a > i; i++)
		if (s[i] != s[b - i + a])
			diff++;
	return (diff <= k);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t = 0, idx[1005];
	string temp;
	while (cin >> k) {
		getline(cin, temp);
		getline(cin, temp);
		s.clear();
		for (int i = 0; i < (int) temp.size(); i++)
			if (isalpha(temp[i]))
				s += tolower(temp[i]), idx[(int) s.size() - 1] = i;
		int ans = 2 * k, start = 1;
		for (int i = 0; i < (int) s.size(); i++) {
			for (int j = i; j < (int) s.size(); j++) {
				int st = idx[i], en = idx[j];
				int len = en - st + 1;
				if (len < ans)
					continue;
				if (check(i, j)) {
					if (len > ans)
						ans = len, start = st;
					else
						start = min(start, st);
				}
			}
		}
		cout << "Case " << ++t << ": " << ans << " " << ++start << "\n";
	}
	return 0;
}
