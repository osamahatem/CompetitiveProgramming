/*
 * 979B. Treasure Hunt.cpp
 *
 *  Created on: May 14, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59462
 *
 * A lazier approach than that of the tutorial would be trying all colours,
 * instead of just the letter appearing the most. The time limit and the
 * constraints allows for that.
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int turns;
vector<char> alpha;

int solve(string s) {
	int ret = 0;
	for (int i = 0; i < (int) alpha.size(); i++) {
		int k = turns, b = 0;
		for (int j = 0; s[j]; j++) {
			if (s[j] == alpha[i])
				b++;
			else if (k)
				k--, b++;
		}
		if (turns == k && k == 1)
			b--;
		ret = max(ret, b);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 26; i++) {
		alpha.push_back('a' + i);
		alpha.push_back('A' + i);
	}

	cin >> turns;
	string s;
	cin >> s;
	int a = solve(s);
	cin >> s;
	int b = solve(s);
	cin >> s;
	int c = solve(s);
	int maxi = max(max(a, b), c);
	int cnt = (a == maxi) + (b == maxi) + (c == maxi);
	if (cnt > 1)
		cout << "Draw" << endl;
	else if (a == maxi)
		cout << "Kuro" << endl;
	else if (b == maxi)
		cout << "Shiro" << endl;
	else
		cout << "Katie" << endl;
	return 0;
}
