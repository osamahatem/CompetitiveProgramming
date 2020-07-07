/*
 * Cooking the Books.cpp
 *
 *  Created on: Jan 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		cout << "Case #" << ++tc << ": ";
		string in, maxi, mini;
		cin >> in;
		maxi = mini = in;
		int sz = in.size();
		for (int i = 0; i < sz; i++) {
			for (int j = i + 1; j < sz; j++) {
				if (i || in[j] > '0') {
					swap(in[i], in[j]);
					mini = min(mini, in);
					maxi = max(maxi, in);
					swap(in[i], in[j]);
				}
			}
		}
		cout << mini << " " << maxi << endl;
	}
	return 0;
}
