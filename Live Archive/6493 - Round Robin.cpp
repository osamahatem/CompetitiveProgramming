#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check(vector<int> &a) {
	int x = a[0];
	for (int i = 1; i < (int) a.size(); i++)
		if (a[i] != x)
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, t;
	while (scanf("%d", &n), n) {
		scanf("%d", &t);
		vector<int> players(n, 0);
		int start = 0;
		while (1) {
			int sz = (int) players.size();
			for (int i = 0; i < sz; i++)
				players[i] += t / sz;
			int extra = t % sz;
			for (int i = 0; i < extra; i++)
				players[start++]++, start %= sz;
			start = (start - 1 + sz) % sz;
			players.erase(players.begin() + start);
			if (check(players)) {
				printf("%d %d\n", (int) players.size(), players[0]);
				break;
			}
			start %= sz - 1;
		}
	}
	return 0;
}
