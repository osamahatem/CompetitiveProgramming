/*
 * 679A. Bear and Prime 100.cpp
 *
 *  Created on: Jun 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool checkPrime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	vector<int> arr;
	for (int i = 2; i < 50; i++)
		if (checkPrime(i))
			arr.push_back(i);
	int c = 0, p = -1;
	for (int i = 0; i < (int) arr.size(); i++) {
		cout << arr[i] << endl;
		string temp;
		cin >> temp;
		if (temp == "yes")
			c++, p = arr[i];
	}
	if (c > 1)
		cout << "composite" << endl;
	else if (!c)
		cout << "prime" << endl;
	else {
		if (p < 10) {
			cout << p * p << endl;
			string temp;
			cin >> temp;
			if (temp == "yes")
				cout << "composite" << endl;
			else
				cout << "prime" << endl;
		} else
			cout << "prime" << endl;
	}
	return 0;
}
