/*
 ID: 19semse1
 PROG: prefix
 LANG: C++
 */
/*
 * prefix.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool pre[200005];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
//#endif

	pre[0] = 1;
	vector<string> prim;
	string text, temp;
	while (cin >> temp, temp != ".")
		prim.push_back(temp);
	while (cin >> temp)
		text += temp;
	int len = text.size(), ans = 0;
	for (int i = 0; i < len; i++) {
		if (!pre[i])
			continue;
		for (int j = 0; j < (int) prim.size(); j++) {
			int en = i + (int) prim[j].size();
			if (en > len || pre[en])
				continue;
			bool flag = 1;
			for (int k = 0; k < (int) prim[j].size(); k++)
				if (prim[j][k] != text[i + k]) {
					flag = 0;
					break;
				}
			if (flag)
				pre[en] = 1, ans = max(ans, en);
		}
	}
	cout << ans << endl;
	return 0;
}
