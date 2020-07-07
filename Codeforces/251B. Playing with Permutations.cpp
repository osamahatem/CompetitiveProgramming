/*
 * 251B. Playing with Permutations.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, q[100], pos[100], s[100], t1[100], t2[100];

bool cmp(int a[], int b[]) {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
		q[i]--;
		pos[q[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		s[i]--;
	}
	int hk = 200, tk = 200;
	for (int i = 0; i < n; i++)
		t1[i] = i;
	for (int i = 0; i <= k; i++) {
		if (cmp(t1, s)) {
			hk = i;
			break;
		}
		for (int j = 0; j < n; j++)
			t2[j] = t1[q[j]];
		memcpy(t1, t2, sizeof t1);
	}
	for (int i = 0; i < n; i++)
		t1[i] = i;
	for (int i = 0; i <= k; i++) {
		if (cmp(t1, s)) {
			tk = i;
			break;
		}
		for (int j = 0; j < n; j++)
			t2[j] = t1[pos[j]];
		memcpy(t1, t2, sizeof t1);
	}
	bool ans = true;
	if (!hk || min(hk, tk) > k)
		ans = false;
	if (hk + tk < 3 && k > 1)
		ans = false;
	if (!(hk <= k && (k - hk) % 2 == 0) && !(tk <= k && (k - tk) % 2 == 0))
		ans = false;
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
