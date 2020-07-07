/*
 * 778B. Bitwise Formula.cpp
 *
 *  Created on: Feb 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e3 + 5;

int n, m;
vector<int> in[MAXN];
string consts[MAXN];
char var[15], a[1005], b[15], op[5];
map<string, int> rnk;

int solve(int b, int val) {
	int vars[MAXN];
	vars[n] = val;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int cur = 0;
		if (in[i].empty())
			cur = consts[i][b] - '0';
		else {
			int v1 = vars[in[i][0]], v2 = vars[in[i][2]];
			if (in[i][1] == 0)
				cur = v1 & v2;
			else if (in[i][1] == 1)
				cur = v1 | v2;
			else
				cur = v1 ^ v2;
		}
		vars[i] = cur;
		sum += cur;
	}
	return sum;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &m);
	rnk["?"] = n;
	for (int i = 0; i < n; i++) {
		scanf("%s%*s%s", var, a);
		rnk[var] = i;
		if (a[0] != '0' && a[0] != '1') {
			scanf("%s%s", op, b);
			in[i].push_back(rnk[a]);
			in[i].push_back(op[0] == 'A' ? 0 : (op[0] == 'O' ? 1 : 2));
			in[i].push_back(rnk[b]);
		} else {
			consts[i] = a;
		}
	}
	string ans1 = "", ans2 = "";
	for (int i = 0; i < m; i++) {
		int s0 = solve(i, 0), s1 = solve(i, 1);
		ans1 += s0 <= s1 ? '0' : '1';
		ans2 += s0 >= s1 ? '0' : '1';
	}
	printf("%s\n%s\n", ans1.c_str(), ans2.c_str());
	return 0;
}
