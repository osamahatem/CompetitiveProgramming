#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans = 0;
		double v, d, f, c;
		scanf("%d%lf", &n, &d);
		while (n--) {
			scanf("%lf%lf%lf", &v, &f, &c);
			if (f < d / v * c)
				continue;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
