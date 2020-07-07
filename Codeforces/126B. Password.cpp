/*
 * 126B. Password.cpp
 *
 *  Created on: Feb 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int fail[MAXN];
char in[MAXN];
vector<int> matches;

void computeFail(char p[]) {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; p[i]; i++) {
		while (len && p[len] != p[i])
			len = fail[len - 1];
		if (p[len] == p[i])
			len++;
		fail[i] = len;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	computeFail(in);
	int len = strlen(in);
	set<int> valid;
	for (int i = 1; i + 1 < len; i++)
		valid.insert(fail[i]);
	len--;
	int ans = 0;
	while (len > 0) {
		if (valid.count(fail[len])) {
			ans = fail[len];
			break;
		}
		len = fail[len] - 1;
	}
	in[ans] = 0;
	printf("%s\n", ans ? in : "Just a legend");
	return 0;
}
