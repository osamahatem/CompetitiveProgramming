/*
 * 3I. Primitive Product.cpp
 *
 *  Created on: Feb 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<vector<int> > ans;
vector<int> temp;
bool neg = 0;

void solve(int idx) {
	if (idx == (int) temp.size()) {
		bool flag = 0;
		for (int i = 0; i < (int) temp.size(); i++)
			if (temp[i] < 0)
				flag = !flag;
		if (flag == neg)
			ans.push_back(temp);
		return;
	}
	int nxt = (int) temp.size();
	for (int i = idx; i < (int) temp.size(); i++)
		if (temp[i] != temp[idx]) {
			nxt = i;
			break;
		}
	solve(nxt);
	for (int i = idx; i < nxt; i++) {
		temp[i] = -temp[i];
		solve(nxt);
	}
	for (int i = idx; i < nxt; i++)
		temp[i] = -temp[i];
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("product.in", "r", stdin);
	freopen("product.out", "w", stdout);
//#endif

	int n;
	cin >> n;
	if (n < 0)
		neg = 1, n = -n;
	for (int i = 2; i * i <= n; i++)
		while (n % i == 0) {
			n /= i;
			temp.push_back(i);
		}
	if (n > 1)
		temp.push_back(n);
	solve(0);
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		sort(ans[i].begin(), ans[i].end());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < (int) ans.size(); i++) {
		for (int j = 0; j < (int) ans[i].size(); j++) {
			if (j)
				cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}
