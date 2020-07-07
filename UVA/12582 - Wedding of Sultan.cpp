/*
 * 12582 - Wedding of Sultan.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[60];
map<char, int> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		ans.clear();
		scanf("%s", in);
		stack<char> S;
		S.push(in[0]);
		for (int i = 1; in[i]; i++) {
			char cur = S.top();
			ans[cur]++;
			if (in[i] == cur)
				S.pop();
			else
				S.push(in[i]);
		}
		ans[in[0]]--;
		printf("Case %d\n", t);
		for (auto it = ans.begin(); it != ans.end(); it++)
			printf("%c = %d\n", it->first, it->second);
	}
	return 0;
}
