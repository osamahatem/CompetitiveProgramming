/*
 * 722B. Verse Pattern.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[105];
char in[105];
string vow = "aeiouy";

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%*c", &arr[i]);
	for (int i = 0; i < n; i++) {
		gets(in);
		for (int j = 0; in[j]; j++)
			if (vow.find(in[j]) != string::npos)
				arr[i]--;
		if (arr[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}
