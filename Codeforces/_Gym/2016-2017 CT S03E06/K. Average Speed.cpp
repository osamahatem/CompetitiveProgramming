/*
 * K. Average Speed.cpp
 *
 *  Created on: Oct 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char s[20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	double dist = 0.0;
	int last = 0, sp = 0;
	while (gets(s) != NULL) {
		int len = strlen(s);
		int h = (s[0] - '0') * 10 + s[1] - '0';
		int m = (s[3] - '0') * 10 + s[4] - '0';
		int sec = (s[6] - '0') * 10 + s[7] - '0';
		int curT = h * 3600 + m * 60 + sec;
		dist += (curT - last) / 3600.0 * sp;
		last = curT;
		if (len > 8) {
			sp = 0;
			for (int i = 9; s[i]; i++)
				sp = sp * 10 + s[i] - '0';
		} else {
			printf("%s %.2f km\n", s, dist);
		}
	}
	return 0;
}
