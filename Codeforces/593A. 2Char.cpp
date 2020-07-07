/*
 * 593A. 2Char.cpp
 *
 *  Created on: Nov 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool valid(string str, int a, int b) {
	for (int i = 0; i < (int) str.size(); i++)
		if (str[i] - 'a' != a && str[i] - 'a' != b)
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<string> all(n);
	for (int i = 0; i < n; i++)
		cin >> all[i];
	int ans = 0;
	for (int a = 0; a < 26; a++)
		for (int b = a + 1; b < 26; b++) {
			int temp = 0;
			for (int i = 0; i < n; i++)
				if (valid(all[i], a, b))
					temp += all[i].size();
			ans = max(ans, temp);
		}
	cout << ans << endl;
	return 0;
}
