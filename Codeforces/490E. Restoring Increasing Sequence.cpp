/*
 * 490E. Restoring Increasing Sequence.cpp
 *
 *  Created on: Nov 23, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string in, last = "0";

bool get(int idx, bool flag) {
	if (idx == (int) in.size())
		return flag;
	if (in[idx] != '?') {
		if (!flag && in[idx] < last[idx])
			return false;
		return get(idx + 1, flag || (in[idx] > last[idx]));
	}
	for (int i = (bool) (idx == 0); i < 10; i++) {
		if (!flag && i + '0' < last[idx])
			continue;
		bool ret = get(idx + 1, flag || (i + '0' > last[idx]));
		if (ret) {
			in[idx] = i + '0';
			return true;
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	vector<string> ans;
	int n;
	cin >> n;
	while (n--) {
		cin >> in;
		if (in.size() < last.size()) {
			cout << "NO\n";
			return 0;
		}
		if (in.size() > last.size()) {
			for (int i = 0; i < (int) in.size(); i++)
				if (in[i] == '?')
					in[i] = '0' + (bool) (!i);
		} else {
			if (!get(0, 0)) {
				cout << "NO\n";
				return 0;
			}
		}
		ans.push_back(in);
		last = in;
	}
	cout << "YES\n";
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}
