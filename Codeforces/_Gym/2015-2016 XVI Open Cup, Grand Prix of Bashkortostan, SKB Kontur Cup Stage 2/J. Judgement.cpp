/*
 * J. Judgement.cpp
 *
 *  Created on: Jun 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXA = 1000000;

int n, p, q, a[105], b[105];
long long dp[MAXA][2];
int par[MAXA][4];

void init() {
	memset(par, 0, sizeof par);
	dp[0][n % 2] = 0;
	for (int i = 1; i < MAXA; i++)
		dp[i][n % 2] = -(1ll << 40);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> p;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> q;
	for (int i = 0; i < n; i++)
		cin >> b[i];

	init();
	for (int nn = n - 1; nn >= 0; nn--)
		for (int i = q - 1; i > 0; i--) {
			dp[i][nn % 2] = dp[i][(nn + 1) % 2];
			if (b[nn] <= i) {
				long long temp = dp[i - b[nn]][(nn + 1) % 2] + a[nn] - b[nn];
				if (temp > dp[i][nn % 2]) {
					dp[i][nn % 2] = temp;
					par[i][nn / 25] |= 1 << (nn % 25);
				}
			}
		}
	for (int i = q - 1; i > 0; i--)
		if (dp[i][0] + i >= p) {
			cout << "NO" << endl;
			int x = i;
			for (int nn = 0; nn < n; nn++) {
				int took = (par[x][nn / 25] >> (nn % 25)) & 1;
				cout << took;
				if (took)
					x -= b[nn];
			}
			return 0;
		}
	init();
	for (int nn = n - 1; nn >= 0; nn--)
		for (int i = p - 1; i > 0; i--) {
			dp[i][nn % 2] = dp[i][(nn + 1) % 2];
			if (a[nn] <= i) {
				long long temp = dp[i - a[nn]][(nn + 1) % 2] + b[nn] - a[nn];
				if (temp > dp[i][nn % 2]) {
					dp[i][nn % 2] = temp;
					par[i][nn / 25] |= 1 << (nn % 25);
				}
			}
		}
	for (int i = p - 1; i > 0; i--)
		if (dp[i][0] + i >= q) {
			cout << "NO" << endl;
			int x = i;
			for (int nn = 0; nn < n; nn++) {
				int took = (par[x][nn / 25] >> (nn % 25)) & 1;
				cout << took;
				if (took)
					x -= a[nn];
			}
			return 0;
		}
	cout << "YES" << endl;
	return 0;
}
