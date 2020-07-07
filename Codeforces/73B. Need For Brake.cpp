/*
 * 73B. Need For Brake.cpp
 *
 *  Created on: Aug 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct racer {
	int p;
	string name;

	const bool operator <(const racer &r) const {
		if (p != r.p)
			return p > r.p;
		return name < r.name;
	}
};

char buff[25];
int award[MAXN];
vector<racer> all;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	string name;
	racer me;
	scanf("%d", &n);
	all.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", buff, &all[i].p);
		all[i].name = buff;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &award[i]);
	sort(award, award + m, greater<int>());
	scanf("%s", buff);
	name = buff;
	for (int i = 0; i < n; i++) {
		if (name == all[i].name) {
			me = all[i];
			swap(all[i], all[n - 1]);
			all.pop_back();
			break;
		}
	}
	sort(all.begin(), all.end());
	vector<racer> temp = all;
	for (int i = 1; i < m; i++)
		temp[n - i - 1].p += award[i];
	me.p += award[0];
	temp.push_back(me);
	sort(temp.begin(), temp.end());
	int rnk = lower_bound(temp.begin(), temp.end(), me) - temp.begin();
	printf("%d ", ++rnk);
	me.p -= award[0];
	temp = all;
	if (m == n)
		me.p += award[--m];
	int curA = 0;
	for (int i = n - 2; i >= 0 && curA < m; i--) {
		if (me < temp[i]) {
			temp[i].p += award[curA];
			if (temp[i] < me) {
				curA++;
				continue;
			}
			temp[i].p -= award[curA];
		}
	}
	temp.push_back(me);
	sort(temp.begin(), temp.end());
	rnk = lower_bound(temp.begin(), temp.end(), me) - temp.begin();
	printf("%d\n", ++rnk);
	return 0;
}
