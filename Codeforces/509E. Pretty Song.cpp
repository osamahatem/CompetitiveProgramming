/*
 * 509E. Pretty Song.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int len;
double acum1[MAXN], acum2[MAXN];
char in[MAXN];
string vow = "IEAOUY";

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	len = strlen(in);
	for (int i = 1; i * 2 <= len; i++)
		acum1[i] = acum1[i - 1] + (1.0 / i + 1.0 / (len - i + 1)) * i;
	for (int i = 1; i <= len; i++)
		acum2[i] = acum2[i - 1] + 1.0 / i;
	double ans = 0.0;
	for (int i = 0; i < len; i++) {
		if (vow.find(in[i]) == string::npos)
			continue;
		int dist = min(i, len - i - 1);
		ans += acum1[dist] + (acum2[len - dist] - acum2[dist]) * (dist + 1);
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}
