/*
 * 6819 - Shrine Maintenance.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-3;
const double R = 1000.0;
const double PI = acos(-1.0);

int W, N, D;
vector<int> val, divs;
bool visDist[5000];
double memDist[5000];

double getDist(double ang1, double ang2) {
	return R * sin(ang1 * PI / 180.0) / sin(ang2 * PI / 180.0);
}

bool check(double _dist) {
	for (int s = 0; s < (int) val.size(); s++) {
		int ww = W, i;
		double dist = 2.0 * R;
		for (i = 0; ww && i + 1 < (int) val.size(); i++) {
			int cur = (s + i) % val.size();
			int nxt = (cur + 1) % val.size();
			if (val[nxt] < val[cur])
				swap(nxt, cur);
			cur = val[cur], nxt = val[nxt];
			int dist_p = min(N - (nxt - cur), nxt - cur);
			if (!visDist[dist_p]) {
				double ang = 360.0 / N * dist_p;
				double ang2 = (180.0 - ang) / 2.0;
				memDist[dist_p] = getDist(ang, ang2);
				visDist[dist_p] = 1;
			}
			if (dist + memDist[dist_p] > _dist) {
				ww--, dist = 2.0 * R;
				continue;
			}
			dist += memDist[dist_p];
		}
		if (ww && i == (int) val.size() - 1)
			return true;
	}
	return false;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	while (scanf("%d", &W), W) {
		memset(visDist, 0, sizeof visDist);
		scanf("%d%d", &N, &D);
		val.clear();
		divs.resize(D);
		for (int i = 0; i < D; i++)
			scanf("%d", &divs[i]);
		for (int i = 1; i <= N; i++) {
			bool flag = 0;
			for (int j = 0; j < D; j++)
				if (i % divs[j] == 0)
					flag = 1;
			if (flag)
				val.push_back(i);
		}
		double s = 2.0 * R, e = 20e6;
		for (double sz = (e - s) / 2.0; sz > EPS; sz /= 2)
			if (!check(s + sz))
				s += sz;
		printf("%.1f\n", s);
	}
	return 0;
}
