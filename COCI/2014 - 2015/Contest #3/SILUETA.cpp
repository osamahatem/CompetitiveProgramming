/*
 * SILUETA.cpp
 *
 *  Created on: Nov 29, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char out[1005][1005];
int maxi[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	memset(out, '.', sizeof out);
	memset(out[0], '*', sizeof out[0]);
	memset(maxi, 0, sizeof maxi);

	int n, l, r, h, maxh = 0, s = 1000, e = 0;
	vector<pair<int, int> > events;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &l, &r, &h);
		maxh = max(maxh, h);
		s = min(s, l);
		e = max(e, r);
		events.push_back(make_pair(l, h));
		events.push_back(make_pair(r, -h));
	}
	sort(events.begin(), events.end());
	int ev = 0, sz = events.size();
	multiset<int, greater<int> > S;
	multiset<int, greater<int> >::iterator it;
	S.insert(0);
	for (int i = s; i <= e; i++) {
		while (ev < sz && events[ev].first == i) {
			if (events[ev].second < 0) {
				it = S.find(-events[ev].second);
				S.erase(it);
			} else
				S.insert(events[ev].second);
			ev++;
		}
		maxi[i] = *S.begin();
	}
	int ans = 0;
	for (int i = 1; i <= maxi[s]; i++)
		out[i][s] = '#';
	for (int i = s + 1; i <= e; i++) {
		if (maxi[i] == maxi[i - 1])
			out[maxi[i]][i] = '#', ans++;
		else {
			for (int j = min(maxi[i], maxi[i - 1]);
					j <= max(maxi[i], maxi[i - 1]); j++)
				out[j][i - 1] = '#', ans++;
			ans++;
		}
	}
	for (int i = s; i <= e; i++)
		out[0][i] = '*';
	for (int i = 0; i <= maxh; i++)
		out[i][e + 1] = '\0';
	printf("%d\n", --ans);
	for (int i = maxh; i >= 0; i--)
		printf("%s\n", out[i] + s);
	return 0;
}
