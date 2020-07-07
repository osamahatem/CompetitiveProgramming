/*
 * 125B. Simple XML.cpp
 *
 *  Created on: Apr 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	char in[1005];
	scanf("%s", in);
	int sp = 0, idx = 0, len = strlen(in);
	string ans;
	while (idx < len) {
		bool close = 0;
		string temp;
		while (in[idx] != '>') {
			if (in[idx] == '/')
				close = 1;
			temp += in[idx++];
		}
		temp += in[idx++];
		if (close)
			sp -= 2;
		for (int i = 0; i < sp; i++)
			ans += " ";
		if (!close)
			sp += 2;
		ans += temp + "\n";
	}
	printf("%s", ans.c_str());
	return 0;
}
