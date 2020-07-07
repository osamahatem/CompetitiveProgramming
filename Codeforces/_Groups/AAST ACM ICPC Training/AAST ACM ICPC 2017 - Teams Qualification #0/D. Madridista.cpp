#include <bits/stdc++.h>

using namespace std;
const int MAX = 100100;
int a[MAX], b[MAX];
int main () {
	freopen("madridista.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		int p = 0;
		vector<int> vals;
		for (p = 1; p <= n; p++) {
			if (n % p)
				continue;
			int kk = k;
			vals.clear();
			for (int i = 0; i < p; i++) {
				map<int, int> cnt;
				int maxi = 0, val;
				for (int j = i; j < n; j += p)
					cnt[a[j]]++;
				for (auto it : cnt)
					if (it.second > maxi)
						maxi = it.second, val = it.first;
				vals.push_back(val);
				kk -= n / p - maxi;
			}
			if (kk >= 0)
				break;
		}
		printf("%d\n", p);
		for (int i = 0; i < p; i++)
			for (int j = i; j < n; j += p)
				a[j] = vals[i];
		for (int i = 0; i < n; ++i) {
			printf("%d ", a[i]);
		}
		puts("");
	}
	return 0;
}
