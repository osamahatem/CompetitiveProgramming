/*
 * 6812 - (More) Multiplication.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char out[25][25];
int da[4], db[4];

int getLen(int x) {
	int ret = 0;
	while (x)
		x /= 10, ret++;
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int a, b, pro;
	while (scanf("%d%d", &a, &b), a && b) {
		memset(out, ' ', sizeof out);
		pro = a * b;
		int la = getLen(a), lb = getLen(b), lp = getLen(pro);
		for (int i = la - 1; i >= 0; i--) {
			da[i] = a % 10;
			a /= 10;
		}
		for (int i = lb - 1; i >= 0; i--) {
			db[i] = b % 10;
			b /= 10;
		}
		int w = la * 4 + 5, h = lb * 4 + 5;
		for (int i = 1; i + 1 < w; i++)
			out[0][i] = out[h - 1][i] = '-';
		for (int i = 1; i + 1 < h; i++)
			out[i][0] = out[i][w - 1] = '|', out[i][w] = '\0';
		out[0][w] = out[h - 1][w] = '\0';
		out[0][0] = out[0][w - 1] = out[h - 1][0] = out[h - 1][w - 1] = '+';
		int ch = 2, cw = 2;
		for (int j = 0; j < lb; j++) {
			cw = 2;
			for (int i = 0; i < la; i++) {
				out[ch][cw] = '+', out[ch][cw + 1] = out[ch][cw + 2] =
						out[ch][cw + 3] = '-';
				out[ch + 1][cw] = out[ch + 2][cw] = out[ch + 3][cw] = '|';
				out[ch + 1][cw + 3] = out[ch + 2][cw + 2] =
						out[ch + 3][cw + 1] = '/';
				cw += 4;
			}
			out[ch][cw] = '+';
			out[ch + 1][cw] = out[ch + 2][cw] = out[ch + 3][cw] = '|';
			ch += 4;
		}
		cw = 2;
		for (int i = 0; i < la; i++) {
			out[ch][cw] = '+', out[ch][cw + 1] = out[ch][cw + 2] = out[ch][cw
					+ 3] = '-';
			cw += 4;
		}
		out[ch][cw] = '+';
		ch = 1, cw = 4;
		for (int i = 0; i < la; i++) {
			out[ch][cw] = '0' + da[i];
			cw += 4;
		}
		ch = 4, cw = w - 2;
		for (int i = 0; i < lb; i++) {
			out[ch][cw] = '0' + db[i];
			ch += 4;
		}
		cw = 2;
		for (int i = 0; i < la; i++) {
			ch = 2;
			for (int j = 0; j < lb; j++) {
				out[ch + 1][cw + 1] = '0' + da[i] * db[j] / 10;
				out[ch + 3][cw + 3] = '0' + da[i] * db[j] % 10;
				ch += 4;
			}
			cw += 4;
		}
		cw = w - 6, ch = h - 2;
		for (int i = 0; i < lp; i++) {
			out[ch][cw] = '0' + pro % 10;
			if (i != lp - 1) {
				if (i < la)
					out[ch][cw - 2] = '/';
				else
					out[ch - 2][cw] = '/';
			}
			pro /= 10;
			if (i + 1 < la)
				cw -= 4;
			if (i == la - 1)
				ch -= 2, cw -= 2;
			if (i >= la)
				ch -= 4;
		}
		for (int i = 0; i < h; i++)
			cout << out[i] << endl;
	}
	return 0;
}
