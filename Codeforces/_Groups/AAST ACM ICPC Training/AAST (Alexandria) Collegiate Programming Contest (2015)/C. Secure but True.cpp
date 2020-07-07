/*
 * C. Secure but True.cpp
 *
 *  Created on: Oct 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string alpha = "AHIMOTUVWXY", in;
char buff[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("password.in", "r", stdin);
	int T, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &k, buff);
		in = buff;
		reverse(in.begin(), in.end());
		int idx = 0;
		while (k) {
			if (idx == (int) in.size())
				k--, in += 'A';
			int a = find(alpha.begin(), alpha.end(), in[idx]) - alpha.begin();
			int b = k % 11;
			in[idx] = alpha[(a + b) % 11];
			k /= 11;
			k += (a + b) / 11;
			idx++;
		}
		reverse(in.begin(), in.end());
		printf("%s\n", in.c_str());
	}
	return 0;
}
