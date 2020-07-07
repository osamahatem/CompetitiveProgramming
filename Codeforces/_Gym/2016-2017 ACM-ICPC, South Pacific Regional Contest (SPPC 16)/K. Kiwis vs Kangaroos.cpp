/*
 * K. Kiwis vs Kangaroos.cpp
 *
 *  Created on: Oct 12, 2017
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

	string str;
	int ans = 0;
	cnt[0] = 2;
	cnt['n' - 'a'] = 1;
	cnt['g' - 'a'] = 1;
	cnt['o' - 'a'] = 2;
	cnt['i' - 'a'] = -3;
	cnt['w' - 'a'] = -1;
	cnt['b' - 'a'] = -1;
	cnt['d' - 'a'] = -1;
	cin >> str;
	for (int i = 0; str[i]; i++)
		ans += cnt[tolower(str[i]) - 'a'];
	cout << (ans > 0 ? "Kangaroos" : (ans < 0 ? "Kiwis" : "Feud continues"))
			<< endl;
	return 0;
}
