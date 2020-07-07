/*
 * 790A. Bear and Different Names.cpp
 *
 *  Created on: Mar 18, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k;
string name = "Aa", temp;
string ans[55];

void nextName() {
	name[1]++;
	if (name[1] > 'z')
		name[0]++, name[1] = 'a';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		ans[i] = name;
		nextName();
	}
	cin >> temp;
	if (temp == "NO")
		ans[0] = ans[1];
	for (int i = 1; i + k - 1 < n; i++) {
		cin >> temp;
		if (temp == "NO") {
			ans[i + k - 1] = ans[i];
		} else {
			nextName();
			ans[i + k - 1] = name;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	return 0;
}
