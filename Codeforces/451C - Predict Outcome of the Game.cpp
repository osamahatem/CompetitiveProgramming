#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int t;
	long long n, k, d1, d2;
	string ans;
	scanf("%d", &t);
	while (t--) {
		bool flag = 0;
		cin >> n >> k >> d1 >> d2;
		long long temp, x, y, z, maxi, diff;
		for (int i = -1; i <= 1; i += 2) {
			for (int j = -1; j <= 1; j += 2) {
				temp = k + 2 * d1 * i + d2 * j;
				if (temp % 3 == 0) {
					x = temp / 3;
					y = x - d1 * i;
					z = y - d2 * j;
					if (x < 0 || y < 0 || z < 0)
						continue;
					maxi = max(x, max(y, z));
					diff = 3 * maxi - x - y - z;
					if (n - k >= diff && (n - k - diff) % 3 == 0)
						flag = 1;
				}
			}
		}
		cout << (flag ? "yes\n" : "no\n");
	}
	return 0;
}
