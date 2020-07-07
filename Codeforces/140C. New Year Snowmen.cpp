/*
 * 140C. New Year Snowmen.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int val, rep;

	const bool operator <(const node &a) const {
		if (rep != a.rep)
			return rep < a.rep;
		return val > a.val;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, r;
	vector<int> all;
	vector<node> cnt;
	priority_queue<node> Q;
	cin >> n;
	while (n--) {
		cin >> r;
		all.push_back(r);
	}
	sort(all.begin(), all.end());
	for (int i = 0; i < (int) all.size(); i++) {
		if (cnt.empty() || all[i] != cnt.back().val)
			cnt.push_back(node { all[i], 1 });
		else
			cnt[(int) cnt.size() - 1].rep++;
	}
	vector<vector<int> > ans;
	for (int i = 0; i < (int) cnt.size(); i++)
		Q.push(cnt[i]);
	while (Q.size() >= 3) {
		node n1 = Q.top();
		Q.pop();
		node n2 = Q.top();
		Q.pop();
		node n3 = Q.top();
		Q.pop();
		vector<int> temp;
		temp.push_back(n1.val);
		temp.push_back(n2.val);
		temp.push_back(n3.val);
		n1.rep--, n2.rep--, n3.rep--;
		if (n1.rep)
			Q.push(n1);
		if (n2.rep)
			Q.push(n2);
		if (n3.rep)
			Q.push(n3);
		sort(temp.begin(), temp.end(), greater<int>());
		ans.push_back(temp);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << endl;
	return 0;
}
