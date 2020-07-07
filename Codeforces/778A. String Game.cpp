/*
 * 778A. String Game.cpp
 *
 *  Created on: Feb 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int t, p, pos[MAXN];
char st[MAXN], sp[MAXN];

bool check(int x) {
	string temp = "";
	for (int i = 0; i < t; i++)
		if (pos[i] >= x)
			temp += st[i];
	int idx = 0;
	for (int i = 0; sp[idx] && i < (int) temp.size(); i++)
		if (sp[idx] == temp[i])
			idx++;
	return !sp[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%s", st, sp);
	t = strlen(st), p = strlen(sp);
	for (int i = 0; i < t; i++) {
		int x;
		scanf("%d", &x);
		pos[--x] = i;
	}
	int s = 0, e = t - 1;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (check(mid))
			s = mid;
		else
			e = mid - 1;
	}
	printf("%d\n", s);
	return 0;
}
