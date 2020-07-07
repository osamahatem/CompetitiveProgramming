/*
 * 305C. Ivan and Powers of Two.cpp
 *
 *  Created on: Dec 7, 2014
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
	int n, a;
	set<int> p;
	cin >> n;
	while (n--) {
		cin >> a;
		while (p.count(a)){
			p.erase(a);
			++a;
		}
		p.insert(a);
	}
	int ans = 0, cur = 0;
	while (p.size()) {
		int top = *p.begin();
		p.erase(p.begin());
		ans += top - cur;
		cur = ++top;
	}
	cout << ans << endl;
	return 0;
}
