/*
 * 149E. Martian Strings.cpp
 *
 *  Created on: Aug 6, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXP = 1e3 + 5;

int n, m, mm, ans;
int f[MAXP], f_rev[MAXP], matc[MAXP], mat[MAXN], matc_rev[MAXP], mat_rev[MAXN];
char s[MAXN], p[MAXP];

void computeFail(int fail[]) {
	fail[0] = 0;
	int len = 0;
	for (int i = 1; p[i]; i++) {
		while (len && p[i] != p[len])
			len = fail[len - 1];
		if (p[i] == p[len])
			len++;
		fail[i] = len;
	}
}

void match(int mat[], int mat_cnt[], int fail[]) {
	int len = 0;
	for (int i = 0; s[i]; i++) {
		while (len && p[len] != s[i])
			len = fail[len - 1];
		if (p[len] == s[i])
			len++;
		mat[i] = len;
		mat_cnt[len]++;
		if (!p[len])
			len = fail[len - 1];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s%d", s, &m);
	n = strlen(s);
	while (m--) {
		memset(matc, 0, sizeof matc);
		memset(matc_rev, 0, sizeof matc_rev);
		scanf("%s", p);
		mm = strlen(p);
		computeFail(f);
		match(mat, matc, f);
		reverse(s, s + n);
		reverse(p, p + mm);
		computeFail(f_rev);
		match(mat_rev, matc_rev, f_rev);
		reverse(s, s + n);
		for (int i = 0; s[i]; i++) {
			matc[mat[n - i - 1]]--;
			if (mat_rev[i] && mat_rev[i] < mm && matc[mm - mat_rev[i]]) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
