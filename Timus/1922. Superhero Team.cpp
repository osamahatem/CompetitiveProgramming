/*
 * 1922. Superhero Team.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int v, idx;

	const bool operator <(const node &a) const {
		return v < a.v;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, v;
	node arr[1005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].v);
		arr[i].idx = i + 1;
	}
	sort(arr, arr + n);
	bool flag = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 >= arr[i].v)
			flag = 1;
		else
			c += flag, flag = 0;
	}
	c += flag;
	printf("%d\n", c);
	flag = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 >= arr[i].v)
			flag = 1;
		else if (flag) {
			flag = 0;
			printf("%d", i);
			for (int j = 0; j < i; j++)
				printf(" %d", arr[j].idx);
			printf("\n");
		}
	}
	if (flag) {
		printf("%d", n);
		for (int i = 0; i < n; i++)
			printf(" %d", arr[i].idx);
		printf("\n");
	}
	return 0;
}
