/*
 * A. The Last Word.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		scanf("%s", s);
		string ans;
		deque<char> temp;
		temp.push_front(s[0]);
		for (int i = 1; s[i]; i++)
			if (s[i] >= temp.front())
				temp.push_front(s[i]);
			else
				temp.push_back(s[i]);
		while (temp.size()) {
			ans += temp.front();
			temp.pop_front();
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}
