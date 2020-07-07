/*
 ID: 19semse1
 PROG: fracdec
 LANG: C++
 */
/*
 * fracdec.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int vis[100005];

string toString(int x) {
	string ret;
	do {
		ret += '0' + x % 10;
		x /= 10;
	} while (x);
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
//#endif

	memset(vis, -1, sizeof vis);
	int n, d;
	cin >> n >> d;
	string ans = toString(n / d) + ".";
	n %= d;
	while (n && vis[n] == -1) {
		vis[n] = ans.size();
		n *= 10;
		int x = n / d;
		ans += '0' + x;
		n %= d;
	}
	if (n) {
		ans.insert(vis[n], "(");
		ans += ')';
	} else if (ans[(int) ans.size() - 1] == '.')
		ans += "0";
	for (int i = 0; i < (int) ans.size(); i += 76)
		cout << ans.substr(i, 76) << endl;
	return 0;
}
