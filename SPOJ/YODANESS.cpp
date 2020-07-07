/*
 * YODANESS.cpp
 *
 *  Created on: Dec 5, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e4 + 5;

int arr[MAXN], temp[MAXN];
char in[25];
map<string, int> rnk;

int solve(int s, int e) {
	int sz = e - s;
	if (sz < 2)
		return 0;
	int mid = (s + e + 1) / 2;
	int ptr1 = s, ptr2 = mid;
	int ret = solve(s, mid) + solve(mid, e);
	memcpy(temp + s, arr + s, sz * sizeof(int));
	for (int i = s; i < mid; i++) {
		if (ptr2 < e && temp[ptr2] < temp[i])
			arr[ptr1++] = temp[ptr2++], ret += mid - (i--);
		else
			arr[ptr1++] = temp[i];
	}
	while (ptr2 < e)
		arr[ptr1++] = temp[ptr2++];
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		rnk.clear();
		vector<string> yoda;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", in);
			yoda.push_back(in);
		}
		for (int i = 0; i < n; i++) {
			scanf("%s", in);
			rnk[in] = i;
		}
		for (int i = 0; i < n; i++)
			arr[i] = rnk[yoda[i]];
		printf("%d\n", solve(0, n));
	}
	return 0;
}
