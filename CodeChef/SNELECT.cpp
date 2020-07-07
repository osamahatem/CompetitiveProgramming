/*
 * SNELECT.cpp
 *
 *  Created on: May 31, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char str[105];
bool eaten[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(eaten, 0, sizeof eaten);
		scanf("%s", str);
		for (int i = 0; str[i]; i++) {
			if (str[i] != 'm')
				continue;
			if (i && str[i - 1] == 's' && !eaten[i - 1])
				eaten[i - 1] = 1;
			else if (str[i + 1] == 's' && !eaten[i + 1])
				eaten[i + 1] = 1;
		}
		int cs = 0, cm = 0;
		for (int i = 0; str[i]; i++)
			cs += (str[i] == 's' && !eaten[i]), cm += (str[i] == 'm');
		printf("%s\n", (cs > cm ? "snakes" : (cm > cs ? "mongooses" : "tie")));
	}
	return 0;
}
