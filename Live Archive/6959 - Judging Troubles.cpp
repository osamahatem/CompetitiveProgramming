/*
 * 6959 - Judging Troubles.cpp
 *
 *  Created on: Sep 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	while (scanf("%d", &n) != EOF) {
		vector<string> v1, v2;
		for (int i = 0; i < n; i++) {
			scanf("%s", in);
			v1.push_back((string) in);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", in);
			v2.push_back((string) in);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int ret = 0;
		for (int i = 0, j = 0; i < n && j < n;)
			if (v1[i] < v2[j])
				i++;
			else if (v1[i] > v2[j])
				j++;
			else
				i++, j++, ret++;
		printf("%d\n", ret);
	}
	return 0;
}
