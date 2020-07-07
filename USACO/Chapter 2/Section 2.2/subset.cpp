/*
 ID: 19semse1
 PROG: subset
 LANG: C++
 */
/*
 * subset.cpp
 *
 *  Created on: Mar 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
//#endif

	int n, n1, n2;
	long long ans = 0;
	cin >> n;
	int sum = n * (n + 1) / 2;
	if (sum % 2) {
		cout << "0" << endl;
		return 0;
	}
	n1 = n / 2, n2 = n - n1;
	vector<int> s1, s2;
	for (int i = 0; i < (1 << n1); i++) {
		int temp = 0;
		for (int b = 0; b < n1; b++)
			if (i & (1 << b))
				temp += b + 1;
		s1.push_back(temp);
	}
	for (int i = 0; i < (1 << n2); i++) {
		int temp = 0;
		for (int b = 0; b < n2; b++)
			if (i & (1 << b))
				temp += n1 + b + 1;
		s2.push_back(temp);
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < (int) s1.size(); i++) {
		int x = lower_bound(s2.begin(), s2.end(), sum / 2 - s1[i]) - s2.begin();
		int y = upper_bound(s2.begin(), s2.end(), sum / 2 - s1[i]) - s2.begin();
		ans += y - x;
	}
	cout << ans / 2 << endl;
	return 0;
}
