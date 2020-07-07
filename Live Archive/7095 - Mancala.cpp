/*
 * 7095 - Mancala.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int T;
	cin >> T;
	while (T--) {
		int t, n;
		cin >> t >> n;
		vector<int> ans;
		for (int i = 1; i <= n; i++) {
			int cnt = 1, b;
			for (b = 1; b <= (int) ans.size() && ans[b - 1]; b++)
				ans[b - 1]--, cnt++;
			if (b > (int) ans.size())
				ans.push_back(cnt);
			else
				ans[cnt - 1] = cnt;
		}
		cout << t << " " << ans.size();
		for (int i = 0; i < (int) ans.size(); i++)
			cout << (i % 10 ? " " : "\n") << ans[i];
		cout << endl;
	}
	return 0;
}
