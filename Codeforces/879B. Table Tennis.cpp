/*
 * 879B. Table Tennis.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, p[505];
long long k;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%lld", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	int cur = p[0], cnt = 0;
	queue<int> Q;
	for (int i = 1; i < n; i++)
		Q.push(p[i]);
	while (cur != n && cnt < k) {
		int op = Q.front();
		Q.pop();
		if (cur > op)
			Q.push(op), cnt++;
		else {
			Q.push(cur);
			cur = op, cnt = 1;
		}
	}
	printf("%d\n", cur);
	return 0;
}
