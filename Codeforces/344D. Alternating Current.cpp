/*
 * 344D. Alternating Current.cpp
 *
 *  Created on: Dec 25, 2014
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

	string in;
	cin >> in;
	stack<char> S;
	for (int i = 0; i < (int) in.size(); i++)
		if (S.size() && in[i] == S.top())
			S.pop();
		else
			S.push(in[i]);
	if (S.size())
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}
