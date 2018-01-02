/*
 * 1177 - Picture.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: Osama Hatem
 */
 
/*
Sweep once for the x-axis and once for the y-axis. For each coordinate, add 2 to
the answer for each contiguous range covered by any rectangle.
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct range {
	int x, s, e, t;

	bool operator <(const range &r) const {
		if (x != r.x)
			return x < r.x;
		return s < r.s;
	}
};

int n;
vector<range> xs, ys;

int sweep(vector<range> &all) {
	sort(all.begin(), all.end());
	int ret = 0, last = -1e6;
	map<int, int> ev;
	for (int i = 0; i < (int) all.size(); i++) {
		range r = all[i];
		if (r.x != last) {
			int cnt = 0, cur = 0;
			for (map<int, int>::iterator e = ev.begin(); e != ev.end(); e++) {
				cnt += e->second;
				if (cnt == 0)
					cur += 2;
			}
			ret += cur * (r.x - last);
			last = r.x;
		}
		ev[r.s] += r.t, ev[r.e] -= r.t;
		if (ev[r.s] == 0)
			ev.erase(r.s);
		if (ev[r.e] == 0)
			ev.erase(r.e);
	}
	int cnt = 0, cur = 0;
	for (map<int, int>::iterator e = ev.begin(); e != ev.end(); e++) {
		cnt += e->second;
		if (cnt == 0)
			cur += 2;
	}
	ret += cur * (all.back().x - last);
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		xs.push_back(range { y1, x1, x2, 1 });
		xs.push_back(range { y2, x1, x2, -1 });
		ys.push_back(range { x1, y1, y2, 1 });
		ys.push_back(range { x2, y1, y2, -1 });
	}
	cout << (n ? sweep(xs) + sweep(ys) : 0) << endl;
	return 0;
}
