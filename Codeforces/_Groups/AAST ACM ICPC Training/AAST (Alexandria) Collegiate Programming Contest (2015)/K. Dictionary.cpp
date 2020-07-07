/*
 * K. Dictionary.cpp
 *
 *  Created on: Oct 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string str[1005];
char buff[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("dictionary.in", "r", stdin);
	int T, N, K;
	scanf("%d", &T);
	while (T--) {
		clock_t tm = clock();
		scanf("%d%d", &N, &K);
		fill(str + 1, str + K + 1, "*");
		while (N--) {
			scanf("%s", buff);
			string temp = buff;
			int sz = temp.size();
			if (sz <= K && (str[sz] == "*" || temp < str[sz]))
				str[sz] = temp;
		}
		set<string> Q;
		for (int i = 1; i <= K; i++)
			if (str[i] != "*")
				Q.insert(str[i]);
		string ans = "-1";
		while (Q.size()) {
			string cur = *(Q.begin());
			Q.erase(Q.begin());
			int sz = cur.size();
			if (sz == K) {
				ans = cur;
				break;
			}
			for (int i = 1; i <= K - sz; i++)
				if (str[i] != "*")
					Q.insert(cur + str[i]);

		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}
