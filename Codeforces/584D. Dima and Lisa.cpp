/*
 * 584D. Dima and Lisa.cpp
 *
 *  Created on: Oct 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, sum;
	cin >> n;
	sum = n;
	while (!isPrime(n))
		n--;
	vector<int> ans;
	ans.push_back(n);
	sum -= n;
	if (sum == 2)
		ans.push_back(2);
	else if (sum > 2)
		for (int i = 2; i + 1 < sum; i++)
			if (isPrime(i) && isPrime(sum - i)) {
				ans.push_back(i), ans.push_back(sum - i);
				break;
			}
	cout << ans.size() << endl << ans[0];
	for (int i = 1; i < (int) ans.size(); i++)
		cout << " " << ans[i];
	cout << endl;
	return 0;
}
