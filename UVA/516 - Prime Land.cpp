/*
 * 516 - Prime Land.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	while (getline(cin, in), in != "0") {
		int n, p, x = 1;
		stringstream ss;
		ss << in;
		while (ss >> n >> p)
			while (p--)
				x *= n;
		x--;
		vector<pair<int, int> > ans;
		for (int i = 2; i * i <= x; i++) {
			int c = 0;
			while (x % i == 0) {
				c++;
				x /= i;
			}
			if (c)
				ans.push_back(make_pair(i, c));
		}
		if (x > 1)
			ans.push_back(make_pair(x, 1));
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			if (i)
				cout << " ";
			cout << ans[i].first << " " << ans[i].second;
		}
		cout << "\n";
	}
	return 0;
}
