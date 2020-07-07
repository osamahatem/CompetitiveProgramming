/*
 * 11181 - Probability Given.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, r;
double p[22], pg[22];

int countOnes(int x) {
	int ret = 0;
	while (x)
		ret++, x -= x & -x;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t = 0;
	while (cin >> n >> r, n) {
		for (int i = 0; i < n; i++)
			cin >> p[i], pg[i] = 0.0;
		double pr = 0.0;
		for (int i = 0; i < (1 << n); i++) {
			if (countOnes(i) != r)
				continue;
			double temp = 1.0;
			for (int j = 0; j < n; j++)
				temp *= (i & (1 << j) ? p[j] : 1.0 - p[j]);
			pr += temp;
			for (int j = 0; j < n; j++)
				if (i & (1 << j))
					pg[j] += temp;
		}
		cout << fixed << setprecision(6);
		cout << "Case " << ++t << ":" << endl;
		for (int i = 0; i < n; i++)
			cout << pg[i] / pr << endl;
	}
	return 0;
}
