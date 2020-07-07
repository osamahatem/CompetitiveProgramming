/*
 *  L. String Modification.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[5005], t[5005];
int ls, lt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%s", s, t);
	ls = strlen(s), lt = strlen(t);
	int idx = 0;
	for (int i = 0; i < lt && idx < ls; i++)
		idx += s[idx] == t[i];
	if (idx < ls) {
		printf("No\n");
		return 0;
	}
	idx = 1;
	while (t[idx] == t[idx - 1] && idx < lt)
		idx++;
	for (int i = 0; i < ls && idx && s[i] == t[0]; i++, idx--)
		;
	printf("%s\n", (idx ? "No" : "Yes"));
	return 0;
}
