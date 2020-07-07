#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n), n) {
		vector<int> num;
		int x;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			num.push_back(x);
		}
		sort(num.begin(), num.end());

		int idx = 0;
		while (idx < 2) {
			for (int i = idx; i < (int) num.size(); i++) {
				if (num[i]) {
					swap(num[i], num[idx++]);
					break;
				}
			}
		}

		int ans[2];
		ans[0] = ans[1] = 0;
		bool flag = 0;
		for (int i = 0; i < (int) num.size(); i++) {
			ans[flag] = ans[flag] * 10 + num[i];
			flag = !flag;
		}
		printf("%d\n", ans[0] + ans[1]);
	}
	return 0;
}
