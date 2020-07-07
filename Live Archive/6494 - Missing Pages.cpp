#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, p, arr[4];
	while (scanf("%d", &n), n) {
		scanf("%d", &p);
		p--;
		int temp = min(p, n - p - 1);
		arr[0] = temp;
		arr[1] = temp ^ 1;
		temp = n - temp - 1;
		arr[2] = temp;
		arr[3] = temp ^ 1;
		sort(arr, arr + 4);
		int idx = 0;
		for (int i = 0; i < 4; i++) {
			if (arr[i] == p)
				continue;
			arr[idx++] = arr[i];
		}
		printf("%d %d %d\n", ++arr[0], ++arr[1], ++arr[2]);
	}
	return 0;
}
