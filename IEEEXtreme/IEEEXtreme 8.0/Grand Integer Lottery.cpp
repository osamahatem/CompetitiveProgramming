/*
 * Grand Integer Lottery.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string toString(long long x) {
	if (x == 0)
		return "0";
	string ret = "";
	while (x) {
		ret += (char) (x % 10 + '0');
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool check(string a, string b) {
	for (int i = 0; i + b.size() <= a.size(); i++)
		if (b == a.substr(i, b.size()))
			return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int s, e, p, n;
	cin >> s >> e >> p >> n;
	long long all[18];
	for (int i = 0; i < n; i++)
		cin >> all[i];
	vector<int> ans;
	for (int i = s; i <= e; i++)
		for (int j = 0; j < n; j++)
			if (check(toString(i), toString(all[j]))) {
				ans.push_back(i);
				break;
			}
	--p;
	if (p < (int) ans.size())
		cout << ans[p] << endl;
	else
		cout << "DOES NOT EXIST\n";
	return 0;
}
