/*
 * RATING.cpp
 *
 *  Created on: Dec 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MAXR = 1e5 + 5;

struct node {
	int ra, rb, id, ans;

	static const bool byRating(const node &a, const node &b) {
		if (a.ra != b.ra)
			return a.ra < b.ra;
		return a.rb < b.rb;
	}

	static const bool byID(const node &a, const node &b) {
		return a.id < b.id;
	}
};

int N, tree[MAXR];
node all[MAXN];

void update(int idx, int val) {
	while (idx < MAXR) {
		tree[idx] += val;
		idx += idx & -idx;
	}
}

int query(int idx) {
	int ret = 0;
	while (idx > 0) {
		ret += tree[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d", &all[i].ra, &all[i].rb), all[i].id = i;
	sort(all, all + N, node::byRating);
	vector<int> temp;
	int last = 0;
	for (int i = 0; i < N; i++) {
		if (all[i].ra != last) {
			for (int j = 0; j < (int) temp.size(); j++)
				update(temp[j], 1);
			temp.clear();
			last = all[i].ra;
		}
		all[i].ans = query(all[i].rb);
		all[i].ans += lower_bound(temp.begin(), temp.end(), all[i].rb)
				- temp.begin();
		temp.push_back(all[i].rb);
	}
	sort(all, all + N, node::byID);
	for (int i = 0; i < N; i++)
		printf("%d\n", all[i].ans);
	return 0;
}
