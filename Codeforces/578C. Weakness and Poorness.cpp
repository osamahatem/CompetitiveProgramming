/*
 * 578C. Weakness and Poorness.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-12;

int n, arr[200005];

double check(double avg) {
	double maxi = 0.0, mini = 0.0, ans = 0.0;
	for (int i = 0; i < n; i++) {
		maxi += arr[i] - avg, mini += arr[i] - avg;
		maxi = max(maxi, arr[i] - avg), mini = min(mini, arr[i] - avg);
		ans = max(ans, max(abs(maxi), abs(mini)));
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	double s = -10000.0, e = 10000.0;
	for (double sz = (e - s) * 2.0 / 3.0; sz > EPS; sz *= 2.0 / 3.0) {
		double m1 = s + sz / 2.0, m2 = e - sz / 2.0;
		if (check(m1) < check(m2))
			e = m2;
		else
			s = m1;
	}
	printf("%.6f\n", check(s));
	return 0;
}
