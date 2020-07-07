/*
 * A. Anagrams.cpp
 *
 *  Created on: Sep 27, 2016
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

	int n;
	vector<int> ans;
	scanf("%d", &n);
	n--;
	for (int i = 1; i <= n / i; i++) {
		if (n % i == 0) {
			ans.push_back(i);
			if (i != n / i)
				ans.push_back(n / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
