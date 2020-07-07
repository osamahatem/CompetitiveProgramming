/*
 * F. Proficiency Test (B).cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string res[105], cor;
bool val[105];
int n, arr[6], cnt = 0;

void check() {
	bool flag = 1;
	for (int i = 0; i < n; i++) {
		int c = 0;
		for (int j = 0; j < 6; j++)
			c += res[i][arr[j]] == cor[arr[j]];
		if ((c > 3 && !val[i]) || (c < 4 && val[i])) {
			flag = 0;
			break;
		}
	}
	if (!flag)
		return;
	cnt++;
}

void solve(int idx) {
	if (idx == 6) {
		check();
		return;
	}
	for (int i = 0; i < 8; i++) {
		arr[idx] = idx * 8 + i;
		solve(idx + 1);
		if (cnt > 1)
			return;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	char temp;
	cin >> cor >> n;
	for (int i = 0; i < n; i++) {
		cin >> res[i] >> temp;
		if (temp == '+')
			val[i] = 1;
	}
	solve(0);
	cout << (cnt == 1 ? "Yes" : "No") << endl;
	return 0;
}
