/*
 * I. Interest Targeting.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	pair<int, int> ids;
	int ctime, heur, advID, stime, flag;

	static const bool interest(const node& a, const node& b) {
		if (a.ids != b.ids)
			return a.ids < b.ids;
		return a.ctime < b.ctime;
	}

	static const bool event(const node& a, const node& b) {
		if (a.ids != b.ids)
			return a.ids < b.ids;
		return a.stime < b.stime;
	}

	static const bool output(const node& a, const node& b) {
		if (a.heur != b.heur)
			return a.heur < b.heur;
		if (a.ids != b.ids)
			return a.ids < b.ids;
		if (a.ctime != b.ctime)
			return a.ctime < b.ctime;
		if (a.advID != b.advID)
			return a.advID < b.advID;
		return a.stime < b.stime;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	vector<node> interest, event;
	scanf("%d%d", &n, &m);
	interest.resize(n), event.resize(m);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", &interest[i].ids.first, &interest[i].ids.second,
				&interest[i].ctime, &interest[i].heur);
	for (int i = 0; i < m; i++)
		scanf("%d%d%d%d%d", &event[i].ids.first, &event[i].ids.second,
				&event[i].advID, &event[i].stime, &event[i].flag);
	sort(interest.begin(), interest.end(), node::interest);
	sort(event.begin(), event.end(), node::event);
	int idxn = n - 1, idxm = m - 1;
	vector<node> ans;
	while (~idxn && ~idxm) {
		if (interest[idxn].ids < event[idxm].ids) {
			idxm--;
		} else if (event[idxm].ids != interest[idxn].ids
				|| event[idxm].stime <= interest[idxn].ctime) {
			idxn--;
		} else {
			node add;
			add.ids = event[idxm].ids;
			add.ctime = interest[idxn].ctime;
			add.heur = interest[idxn].heur;
			add.advID = event[idxm].advID;
			add.stime = event[idxm].stime;
			add.flag = event[idxm].flag;
			ans.push_back(add), idxm--;
		}
	}
	sort(ans.begin(), ans.end(), node::output);
	printf("%d\n", ans.size());
	for (auto el : ans)
		printf("%d %d %d %d %d %d %d\n", el.ids.first, el.ids.second, el.ctime,
				el.heur, el.advID, el.stime, el.flag);
	return 0;
}
