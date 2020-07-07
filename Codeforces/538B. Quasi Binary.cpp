/*
 * 538B. Quasi Binary.cpp
 *
 *  Created on: Apr 26, 2015
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

	int n, temp, mini = 0;
	cin >> n;
	temp = n;
	while (temp) {
		mini = max(mini, temp % 10);
		temp /= 10;
	}
	cout << mini << endl;
	vector<int> ans(mini, 0);
	int pw = 1;
	while (n) {
		for (int i = 0; i < mini; i++)
			if (n % 10)
				ans[i] += pw, n--;
		n /= 10;
		pw *= 10;
	}
	for (int i = 0; i < mini; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
