/*
 * I. Ingenious Lottery Tickets.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int val, cnt;

	const bool operator <(const node& other) const {
		if (cnt != other.cnt)
			return cnt > other.cnt;
		if (val == 7)
			return true;
		if (other.val == 7)
			return false;
		return val < other.val;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		node arr[50];
		for (int i = 0; i < 50; i++)
			arr[i].val = i, arr[i].cnt = 0;
		while (n--) {
			int x;
			for (int i = 0; i < 6; i++) {
				scanf("%d", &x);
				arr[x].cnt++;
			}
		}
		sort(arr, arr + 50);
		int ans[6];
		for (int i = 0; i < 6; i++)
			ans[i] = arr[i].val;
		sort(ans, ans + 6);
		for (int i = 0; i < 6; i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
