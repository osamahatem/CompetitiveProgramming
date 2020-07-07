/*
 * B. Boolean Satisfiability.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[1005];
bool t[255], f[255];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("boolean.in", "r", stdin);
	freopen("boolean.out", "w", stdout);
	scanf("%s", str);
	bool flag = 0;
	for (int i = 0; str[i]; i++) {
		if (str[i] == '|')
			flag = 0;
		else if (str[i] == '~')
			flag = 1;
		else
			(flag ? f[str[i]] : t[str[i]]) = 1;
	}
	int cnt = 0;
	flag = 0;
	for (int i = 0; i < 250; i++) {
		cnt += f[i] || t[i];
		flag |= f[i] && t[i];
	}
	cout << (1ll << cnt) - !flag << endl;
	return 0;
}
