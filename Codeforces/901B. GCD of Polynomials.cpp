/*
 * 901B. GCD of Polynomials.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: Osama Hatem
 */
 
/*
We generate polynomials in the reverse order from the end-state (1, 0), similar
to Fibonacci sequence.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;

void solve() {
	vector<int> a, b;
	a.push_back(1);
	b.push_back(0);
	for (int i = 0; i < n; i++) {
		vector<int> temp = a;
		reverse(a.begin(), a.end());
		a.push_back(0);
		reverse(a.begin(), a.end());
		bool flag = false;
		for (int j = 0; j < (int) b.size(); j++)
			if (abs(a[j] + b[j]) > 1)
				flag = true;
		if (flag)
			for (int j = 0; j < (int) a.size(); j++)
				a[j] *= -1;
		flag = false;
		for (int j = 0; j < (int) b.size(); j++)
			if (abs(a[j] + b[j]) > 1)
				flag = true;
		for (int j = 0; j < (int) b.size(); j++)
			a[j] += b[j];
		b = temp;
	}
	if (a.back() < 0)
		for (int i = 0; i < (int) a.size(); i++)
			a[i] *= -1;
	if (b.back() < 0)
		for (int i = 0; i < (int) b.size(); i++)
			b[i] *= -1;
	cout << (int) a.size() - 1 << endl;
	for (int i = 0; i < (int) a.size(); i++) {
		if (i)
			cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << (int) b.size() - 1 << endl;
	for (int i = 0; i < (int) b.size(); i++) {
		if (i)
			cout << " ";
		cout << b[i];
	}
	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	solve();
	return 0;
}
