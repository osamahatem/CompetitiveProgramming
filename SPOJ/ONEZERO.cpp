/*
 * ONEZERO.cpp
 *
 *  Created on: Sep 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int src;

string BFS() {
	queue<pair<string, int>> Q;
	Q.push( { "1", 1 });
	while (Q.size()) {
		string curS = Q.front().first;
		int curM = Q.front().second;
		Q.pop();
		if (!curM)
			return curS;
		string newS = curS + "0";
		int newM = curM * 10 % src;
		Q.push( { newS, newM });
		newS = curS + "1";
		newM = (curM * 10 + 1) % src;
		Q.push( { newS, newM });
	}
	return "0";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &src);
		printf("%s\n", BFS().c_str());
	}
	return 0;
}
