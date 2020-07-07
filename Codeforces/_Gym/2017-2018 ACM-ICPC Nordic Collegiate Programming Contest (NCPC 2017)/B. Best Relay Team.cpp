/*
 * B. Best Relay Team.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
pair<double, string> a[505], b[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double x, y;
		char in[25];
		scanf("%s%lf%lf", in, &x, &y);
		a[i] = make_pair(x, in), b[i] = make_pair(y, in);
	}
	sort(b, b + n);
	double ans = 100.0;
	vector<string> out;
	for (int i = 0; i < n; i++) {
		double temp = a[i].first;
		vector<string> tmp;
		tmp.push_back(a[i].second);
		int cnt = 3;
		for (int j = 0; j < n && cnt; j++) {
			if (a[i].second == b[j].second)
				continue;
			cnt--;
			tmp.push_back(b[j].second);
			temp += b[j].first;
		}
		if (temp < ans)
			ans = temp, out = tmp;
	}
	printf("%.2f\n", ans);
	for (int i = 0; i < 4; i++)
		printf("%s\n", out[i].c_str());
	return 0;
}
