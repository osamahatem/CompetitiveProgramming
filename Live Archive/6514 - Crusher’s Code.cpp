#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<vector<int>, double> memoM, memoC;
map<int, int> rank;

bool isSorted(vector<int> &N) {
	for (int i = 1; i < (int) N.size(); i++)
		if (N[i] < N[i - 1])
			return false;
	return true;
}

double Monty(vector<int> &N) {
	if (isSorted(N))
		return 0.0;
	if (memoM.count(N))
		return memoM[N];
	double ret = 0.0;
	int c = 0;
	for (int i = 0; i < (int) N.size(); i++) {
		for (int j = 0; j < (int) N.size(); j++) {
			int a = min(i, j), b = max(i, j);
			if (N[a] > N[b]) {
				c++;
				swap(N[a], N[b]);
				ret += Monty(N);
				swap(N[a], N[b]);
			}
		}
	}
	int all = (int) N.size() * (int) N.size();
	return memoM[N] = (all + ret) / c;
}

double Carlos(vector<int> &N) {
	if (isSorted(N))
		return 0.0;
	if (memoC.count(N))
		return memoC[N];
	double ret = 0.0;
	int c = 0;
	for (int i = 0; i + 1 < (int) N.size(); i++) {
		if (N[i] > N[i + 1]) {
			c++;
			swap(N[i], N[i + 1]);
			ret += Carlos(N);
			swap(N[i], N[i + 1]);
		}
	}
	int all = (int) N.size() - 1;
	return memoC[N] = (all + ret) / c;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	memoM.clear();
	memoC.clear();
	int t;
	scanf("%d", &t);
	while (t--) {
		rank.clear();
		int r = 0;
		vector<int> num, rnk;
		int x, n;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &x);
			rnk.push_back(x);
			num.push_back(x);
		}
		sort(rnk.begin(), rnk.end());
		for (int i = 0; i < (int) rnk.size(); i++) {
			int x = rnk[i];
			if (!rank.count(x))
				rank[x] = ++r;
		}
		for (int i = 0; i < (int) num.size(); i++)
			num[i] = rank[num[i]];
		printf("Monty %.6f Carlos %.6f\n", Monty(num), Carlos(num));
	}
	return 0;
}
