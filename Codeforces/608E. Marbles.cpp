/*
 * 608E. Marbles.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int fail[MAXN];
char a[MAXN], b[MAXN];
map<char, char> rev;

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

bool match(char p[], char s[]) {
	int len = 0;
	for (int i = 0; s[i]; i++) {
		while (len && p[len] != s[i])
			len = fail[len - 1];
		if (p[len] == s[i])
			len++;
		if (len && !s[i + 1])
			return true;
		if (!p[len])
			len = fail[len - 1];
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	rev['S'] = 'N', rev['N'] = 'S', rev['W'] = 'E', rev['E'] = 'W';
	scanf("%*d%s%s", a, b);
	int len = strlen(a);
	reverse(a, a + len);
	for (int i = 0; b[i]; i++)
		b[i] = rev[b[i]];
	computeFail(a);
	printf("%s\n", (match(a, b) ? "NO" : "YES"));
	return 0;
}
