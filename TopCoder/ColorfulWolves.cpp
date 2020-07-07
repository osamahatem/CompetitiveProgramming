/*
 * ColorfulWolves.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class ColorfulWolves {
	static const int INF = 1000000;

public:
	int getmin(vector<string> adj) {
		int N = adj.size();
		int dist[50][50];
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			for (int j = 0; j < N; j++) {
				dist[i][j] = (adj[i][j] == 'Y' ? cnt : INF);
				cnt += adj[i][j] == 'Y';
			}
		}
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		return dist[0][N - 1] >= INF ? -1 : dist[0][N - 1];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
