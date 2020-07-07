/*
 * 589D. Boulevard.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, t[1005], s[1005], f[1005], ans[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i] >> s[i] >> f[i];
		for (int j = 0; j < i; j++) {
			int d1 = f[i] - s[i], d2 = f[j] - s[j];
			int s1 = s[i], f1 = f[i], s2 = s[j], f2 = f[j];
			int t1 = t[i], t2 = t[j];
			if (d1 > 0 && d2 > 0) {
				if (s2 < s1)
					swap(s1, s2), swap(f1, f2), swap(t1, t2);
				if (s2 <= f1 && s2 - s1 == t2 - t1)
					ans[i]++, ans[j]++;
			} else if (d1 < 0 && d2 < 0) {
				if (s1 < s2)
					swap(s1, s2), swap(f1, f2), swap(t1, t2);
				if (s2 >= f1 && s1 - s2 == t2 - t1)
					ans[i]++, ans[j]++;
			} else {
				if (d1 < 0)
					swap(s1, s2), swap(f1, f2), swap(t1, t2);
				if (t1 < t2)
					s1 += t2 - t1;
				else
					s2 -= t1 - t2;
				if (s1 > f1 || s2 < f2 || s1 > s2)
					continue;
				s1 *= 2, s2 *= 2, f1 *= 2, f2 *= 2;
				int mid = (s1 + s2) / 2;
				if (mid >= s1 && mid <= f1 && mid <= s2 && mid >= f2)
					ans[i]++, ans[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
