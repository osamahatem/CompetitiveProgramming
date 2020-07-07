/*
 * PingPongQueue.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class PingPongQueue {
public:
	vector<int> whoPlaysNext(vector<int> skills, int N, int K) {
		int last = 0, cnt = 0, L = 0, W = 0;
		queue<int> Q;
		for (int x : skills)
			Q.push(x);
		set<int> cur;
		for (int i = 0; i < K; i++) {
			while (cur.size() < 2) {
				cur.insert(Q.front());
				Q.pop();
			}
			L = *cur.begin();
			Q.push(L);
			cur.erase(cur.begin());
			W = *cur.begin();
			if (W != last)
				cnt = 0;
			cnt++;
			if (cnt == N) {
				Q.push(W);
				cur.erase(cur.begin());
				cnt = 0;
			}
			last = W;
		}
		return {L, W};
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
