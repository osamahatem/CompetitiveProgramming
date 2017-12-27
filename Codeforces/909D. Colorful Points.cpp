/*
 * 909D. Colorful Points.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56666

My solution: I do a simulation using a linked list and update the points that
should be deleted on the go. Only points that are neighbour to deleted points
are affected and those can be checked every time a point is deleted. Complexity
is O(N).
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

char str[MAXN];
int nxt[MAXN], prv[MAXN], sz;

bool check(int idx) {
	return (prv[idx] != -1 && str[idx] != str[prv[idx]])
			|| (nxt[idx] != sz && str[idx] != str[nxt[idx]]);
}

void del(int idx) {
	if (prv[idx] != -1)
		nxt[prv[idx]] = nxt[idx];
	if (nxt[idx] != sz)
		prv[nxt[idx]] = prv[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", str);
	sz = strlen(str);
	queue<int> Q;
	for (int i = 0; i < sz; i++) {
		nxt[i] = i + 1, prv[i] = i - 1;
		if (check(i))
			Q.push(i);
	}
	int ans = 0;
	for (; Q.size(); ans++) {
		int q = Q.size(), last_prv = -1, last_nxt = -1;
		while (q--) {
			int x = Q.front();
			Q.pop();
			if (prv[x] != last_prv && last_prv != -1 && check(last_prv))
				Q.push(last_prv);
			if (prv[x] != last_nxt && last_nxt != -1 && last_nxt != x
					&& check(last_nxt))
				Q.push(last_nxt);
			last_prv = prv[x], last_nxt = nxt[x];
			del(x);
		}
		if (last_prv != -1 && check(last_prv))
			Q.push(last_prv);
		if (last_nxt != -1 && last_nxt != sz && check(last_nxt))
			Q.push(last_nxt);
	}
	printf("%d\n", ans);
	return 0;
}
