/*
 * 1001. Reverse Root.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	double x;
	vector<double> all;
	while (scanf("%lf", &x) != EOF)
		all.push_back(x);
	reverse(all.begin(), all.end());
	for (int i = 0; i < (int) all.size(); i++)
		printf("%.4f\n", sqrt(all[i]));
	return 0;
}
