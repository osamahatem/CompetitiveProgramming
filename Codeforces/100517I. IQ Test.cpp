/*
 * I. IQ Test.cpp
 *
 *  Created on: Mar 10, 2018
 *      Author: Osama Hatem
 */
 
/*
We first sort employees by time, and then perform a DP. The state of the DP is
i, the index of the first unassigned employee, and we try all possible
partitions by trying all choices for the last employee in a new group starting
at i. We notice that this employee's time will be added to all others in the
group (it is the time the group will take), and to all employees in subsequent
groups (they will wait that amount before starting). Using this info, we can
build the current answer from the sub-problems.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long inf = 1e18;

int n;
pair<long long, int> emp[10005];
long long dp[10005], path[10005];
vector<vector<int>> ans;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("iq.in", "r", stdin);
	freopen("iq.out", "w", stdout);

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			cin >> emp[i].first, emp[i].second = i + 1;
		sort(emp, emp + n);

		dp[n] = 0;
		for (int i = n - 1; ~i; i--) {
			dp[i] = inf;
			for (int j = i; j < n; j++) {
				long long temp = dp[j + 1] + emp[j].first * (n - i);
				if (temp < dp[i])
					dp[i] = temp, path[i] = j;
			}
		}

		ans.clear();
		int idx = 0;
		while (idx < n) {
			vector<int> temp;
			for (int i = idx; i <= path[idx]; i++)
				temp.push_back(emp[i].second);
			ans.push_back(temp);
			idx = path[idx] + 1;
		}

		cout << dp[0] << endl << ans.size() << endl;
		for (auto v : ans) {
			cout << v.size();
			for (auto x : v)
				cout << " " << x;
			cout << endl;
		}
	}
	return 0;
}
