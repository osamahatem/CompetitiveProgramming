/*
 * 6953 - Digi Comp II.cpp
 *
 *  Created on: Sep 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int in[MAXN], ch[MAXN][2];
long long balls[MAXN];
bool state[MAXN];
char ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int m, l, r;
	long long n;
	char st;
	while (scanf("%lld%d%*c", &n, &m) != EOF) {
		memset(in, 0, (m + 1) * sizeof(int));
		memset(balls, 0, (m + 1) * sizeof(long long));
		balls[1] = n;
		for (int i = 1; i <= m; i++) {
			scanf("%c%d%d%*c", &st, &l, &r);
			state[i] = st == 'R';
			in[l]++, in[r]++;
			ch[i][0] = l, ch[i][1] = r;
		}
		queue<int> Q;
		for (int i = 1; i <= m; i++)
			if (!in[i])
				Q.push(i);
		while (Q.size()) {
			int cur = Q.front();
			Q.pop();
			if (!cur)
				continue;
			balls[ch[cur][0]] += balls[cur] / 2;
			balls[ch[cur][1]] += balls[cur] / 2;
			if (balls[cur] % 2) {
				balls[ch[cur][state[cur]]]++;
				state[cur] = !state[cur];
			}
			in[ch[cur][0]]--, in[ch[cur][1]]--;
			if (!in[ch[cur][0]])
				Q.push(ch[cur][0]);
			if (!in[ch[cur][1]] && ch[cur][0] != ch[cur][1])
				Q.push(ch[cur][1]);
			ans[cur - 1] = (state[cur] ? 'R' : 'L');
		}
		ans[m] = 0;
		printf("%s\n", ans);
	}
	return 0;
}
