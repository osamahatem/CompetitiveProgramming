/*
 * 378D. Preparing for the Contest.cpp
 *
 *  Created on: Jun 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

struct student {
	int skill, pass, id;

	static const bool bySkill(const student &a, const student &b) {
		return a.skill < b.skill;
	}

	static const bool byID(const student &a, const student &b) {
		return a.id < b.id;
	}
};

int n, m, s;
student all[MAXN], bug[MAXN];
int days[MAXN];

bool check(int d) {
	for (int i = 1; i <= n; i++)
		days[i] = d;
	set<pair<int, int>> avail;
	int idx = n - 1, ss = s;
	for (int i = m - 1; i >= 0; i--) {
		while (idx >= 0 && all[idx].skill >= bug[i].skill) {
			avail.insert(make_pair(all[idx].pass, all[idx].id));
			idx--;
		}
		if (avail.empty())
			return false;
		int pass = avail.begin()->first, id = avail.begin()->second;
		if (pass > ss)
			return false;
		avail.erase(avail.begin());
		ss -= pass;
		bug[i].pass = id;
		if (--days[id])
			avail.insert(make_pair(0, id));
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < m; i++)
		scanf("%d", &bug[i].skill), bug[i].id = i;
	sort(bug, bug + m, student::bySkill);
	for (int i = 0; i < n; i++)
		scanf("%d", &all[i].skill), all[i].id = i + 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &all[i].pass);
	sort(all, all + n, student::bySkill);
	int st = 1, en = m + 1;
	while (st < en) {
		int mid = (st + en) / 2;
		if (check(mid))
			en = mid;
		else
			st = mid + 1;
	}
	if (st == m + 1) {
		printf("NO\n");
		return 0;
	}
	check(st);
	sort(bug, bug + m, student::byID);
	printf("YES\n");
	for (int i = 0; i < m; i++) {
		if (i)
			printf(" ");
		printf("%d", bug[i].pass);
	}
	printf("\n");
	return 0;
}
