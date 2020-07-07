/*
 * 718A. Efim and Strange Grade.cpp
 *
 *  Created on: Sep 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t;
	scanf("%d%d%s", &n, &t, in);
	int point = find(in, in + n, '.') - in;
	int idx = point + 1;
	for (; idx < n && in[idx] < '5'; idx++)
		;
	idx--;
	bool add = (in[idx + 1] > '4');
	while (idx > point && t && add) {
		if (in[idx] < '9')
			in[idx]++;
		else
			in[idx] = '0';
		if (in[idx] < '5' && in[idx] > '0')
			add = 0;
		t--, idx--;
	}
	if (!t)
		add = 0;
	in[idx + 2] = 0;
	if (add) {
		idx = point - 1;
		in[idx + 1] = 0;
		while (idx >= 0 && add) {
			if (in[idx] < '9')
				in[idx]++;
			else
				in[idx] = '0';
			if (in[idx] > '0')
				add = 0;
			idx--;
		}
	}
	if (add)
		printf("1");
	printf("%s\n", in);
	return 0;
}
