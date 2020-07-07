/*
 * 504C. Misha and Palindrome Degree.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, arr[MAXN], cnt[MAXN], temp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	long long ans = 0;
	int s = 0, e = N - 1;
	while (s < e && arr[s] == arr[e])
		s++, e--;
	if (s >= e) {
		printf("%I64d\n", (long long) N * (N + 1) / 2);
		return 0;
	}
	int oddCnt = 0;
	for (int i = s; i <= e; i++) {
		cnt[arr[i]]++;
		oddCnt += (cnt[arr[i]] % 2 ? 1 : -1);
	}
	if (((e - s + 1) % 2 == 0 && oddCnt) || ((e - s + 1) % 2 && oddCnt != 1)) {
		printf("0\n");
		return 0;
	} else
		ans += (long long) (s + 1) * (N - e);
	int ss = s, ee = e;
	memcpy(temp, cnt, sizeof temp);
	for (; ee > ss && temp[arr[ee]] > 1; ee--, ss++)
		ans += s + 1, temp[arr[ee]] -= 2;
	ss = s, ee = e;
	memcpy(temp, cnt, sizeof temp);
	for (; ee > ss && temp[arr[ss]] > 1; ee--, ss++)
		ans += N - e, temp[arr[ss]] -= 2;
	bool sym = 1;
	memset(temp, 0, sizeof temp);
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < N; i++)
		cnt[arr[i]]++;
	for (int i = 0; i < N / 2; i++)
		temp[arr[i]]++;
	for (int i = 1; i <= N; i++)
		if (cnt[arr[i]] / 2 != temp[arr[i]])
			sym = 0;
	for (int i = (N + 1) / 2 - 1; sym && i >= 0 && arr[i] == arr[N - 1 - i];
			i--)
		ans += s + 1 + N - e;
	printf("%I64d\n", ans);
	return 0;
}
