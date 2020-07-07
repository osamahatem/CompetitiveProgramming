/*
 * 589G. Hiring.cpp
 *
 *  Created on: Oct 20, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

struct Candidate {
	int d, r, id, ans;

	static const bool cmpByD(const Candidate& a, const Candidate& b) {
		return a.d < b.d;
	}

	static const bool cmpById(const Candidate& a, const Candidate& b) {
		return a.id < b.id;
	}
};

int N, M;
pair<long long, int> tree[4 * MAXN];
pair<int, int> days[MAXN];
Candidate all[MAXN];

void build(int n = 1, int s = 0, int e = M - 1) {
	if (s == e) {
		tree[n].first = days[s].first;
		tree[n].second = 1;
		return;
	}
	int mid = (s + e) / 2;
	build(n * 2, s, mid), build(n * 2 + 1, mid + 1, e);
	tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
	tree[n].second = tree[n * 2].second + tree[n * 2 + 1].second;
}

void update(int t, int n = 1, int s = 0, int e = M - 1) {
	if (t < s || t > e)
		return;
	if (s == e) {
		tree[n] = make_pair(0, 0);
		return;
	}
	int mid = (s + e) / 2;
	update(t, n * 2, s, mid), update(t, n * 2 + 1, mid + 1, e);
	tree[n].first = tree[n * 2].first + tree[n * 2 + 1].first;
	tree[n].second = tree[n * 2].second + tree[n * 2 + 1].second;
}

int query(int val, int d, int n = 1, int s = 0, int e = M - 1) {
	if (tree[n].first - tree[n].second * d < val)
		return -1;
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (tree[n * 2].first - tree[n * 2].second * d >= val)
		return query(val, d, n * 2, s, mid);
	val -= tree[n * 2].first - tree[n * 2].second * d;
	return query(val, d, n * 2 + 1, mid + 1, e);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &days[i].first);
		days[i].second = i;
	}
	build();
	sort(days, days + M);
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &all[i].d, &all[i].r);
		all[i].id = i;
	}
	sort(all, all + N, Candidate::cmpByD);
	for (int i = 0, j = 0; i < N; i++) {
		while (j < M && days[j].first <= all[i].d)
			update(days[j++].second);
		all[i].ans = query(all[i].r, all[i].d) + 1;
	}
	sort(all, all + N, Candidate::cmpById);
	for (int i = 0; i < N; i++) {
		if (i)
			printf(" ");
		printf("%d", all[i].ans);
	}
	printf("\n");
	return 0;
}
