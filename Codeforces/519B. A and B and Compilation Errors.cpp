/*
 * 519B. A and B and Compilation Errors.cpp
 *
 *  Created on: Feb 28, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

multiset<int> num;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a, num.insert(a), num.insert(a);
	for (int i = 1; i < n; i++) {
		cin >> a;
		num.erase(num.find(a));
	}
	for (int i = 2; i < n; i++) {
		cin >> a;
		num.erase(num.find(a));
	}
	int a1 = *num.begin(), b = *(--num.end()), c = *(++num.begin());
	if (a1 == c)
		cout << a1 << endl << b << endl;
	else
		cout << b << endl << a1 << endl;
	return 0;
}
