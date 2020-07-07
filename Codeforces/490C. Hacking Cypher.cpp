/*
 * 490C. Hacking Cypher.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int amod[1000006], bmod[1000006];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	int a, b;
	cin >> in >> a >> b;
	amod[0] = (in[0] - '0') % a;
	for (int i = 1; i < (int) in.size(); i++)
		amod[i] = (amod[i - 1] * 10 + (in[i] - '0')) % a;
	bmod[(int) in.size() - 1] = (in[(int) in.size() - 1] - '0') % b;
	int p = 10;
	for (int i = (int) in.size() - 2; i >= 0; i--) {
		bmod[i] = (bmod[i + 1] + (in[i] - '0') * p) % b;
		p = p * 10 % b;
	}
	for (int i = 0; i + 1 < (int) in.size(); i++) {
		if (in[i + 1] == '0')
			continue;
		if (amod[i] == 0 && bmod[i + 1] == 0) {
			cout << "YES\n";
			cout << in.substr(0, i + 1) << endl;
			cout << in.substr(i + 1, (int) in.size() - i - 1);
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
