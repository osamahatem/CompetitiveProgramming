/*
 * 913D. Too Easy Problems.cpp
 *
 *  Created on: Jan 8, 2018
 *      Author: Osama Hatem
 */

/*
http://codeforces.com/blog/entry/56992
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

struct problem {
	int a, t, id;

	bool operator <(const problem p) const {
		return make_pair(t, a) < make_pair(p.t, p.a);
	}
};

int n, T;
problem arr[MAXN];
vector<int> ans;

bool check(int cnt) {
	ans.clear();
	int tt = T;
	for (int i = 0; (int) ans.size() < cnt && i < n; i++)
		if (arr[i].a >= cnt && arr[i].t <= tt)
			tt -= arr[i].t, ans.push_back(arr[i].id);
	return (int) ans.size() == cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> T;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a >> arr[i].t;
		arr[i].id = i + 1;
	}
	sort(arr, arr + n);
	int s = 0, e = n;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (check(mid))
			s = mid;
		else
			e = mid - 1;
	}
	check(s);
	cout << ans.size() << endl << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
