/*
 * 486C. Palindrome Transformation.cpp
 *
 *  Created on: Nov 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dist(char a, char b) {
	if (a > b)
		swap(a, b);
	int ret = b - a;
	return min(ret, 26 - ret);
}

int dist(int a, int b, int len) {
	int ret = max(a, b) - min(a, b);
	ret = min(ret, len - ret);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int len, p;
	string in;
	cin >> len >> p >> in;
	--p;
	int ans = 0, mini = len, maxi = 0, cnt = 0;
	for (int i = 0; i < len / 2; i++) {
		ans += dist(in[i], in[len - 1 - i]);
		if (dist(in[i], in[len - 1 - i]) && p >= len / 2) {
			maxi = max(maxi, len - 1 - i);
			mini = min(mini, len - 1 - i);
			cnt++;
		} else if (dist(in[i], in[len - 1 - i])) {
			maxi = max(maxi, i);
			mini = min(mini, i);
			cnt++;
		}
	}
	if (cnt == 1)
		ans += dist(p, maxi, len);
	else if (cnt == 2) {
		ans += dist(mini, maxi, len);
		ans += min(dist(p, maxi, len), dist(p, mini, len));
	} else if (cnt) {
		ans += maxi - mini;
		ans += min(dist(p, maxi, len), dist(p, mini, len));
	}
	cout << ans << endl;
	return 0;
}
