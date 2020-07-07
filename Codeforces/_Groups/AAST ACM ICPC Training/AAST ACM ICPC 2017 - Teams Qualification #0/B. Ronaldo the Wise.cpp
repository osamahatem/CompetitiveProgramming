#include <bits/stdc++.h>

using namespace std;
const int MAX = 100100;
int a[MAX], b[MAX];
int main () {
	freopen("ronaldo.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		long long suma = 0, sumb = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", a + i);
			suma += a[i];
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d", b + i);
			sumb += b[i];
		}
		sort(a, a + n);
		sort(b, b + m);
		int idxa = 0;
		int idxb = m - 1;
		int ans = 0;
		while(sumb > suma && idxa < n && idxb >= 0 && a[idxa] < b[idxb]) {
			int diff = b[idxb] - a[idxa];
			sumb -= diff;
			suma += diff;
			if (idxa % 3 == 0)
				++ans;
			idxa++, idxb--;
		}
		if (sumb > suma)
			ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}
