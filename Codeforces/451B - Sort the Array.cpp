#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool sorted(int arr[], int n) {
	for (int i = 0; i + 1 < n; i++)
		if (arr[i] > arr[i + 1])
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, arr[100005], s = 1, e = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i + 1 < n; i++) {
		if (arr[i] > arr[i + 1]) {
			int j;
			for (j = i + 1; j < n && arr[j] < arr[j - 1]; j++)
				;
			reverse(arr + i, arr + j);
			if (!sorted(arr, n)) {
				printf("no\n");
				return 0;
			}
			s = i + 1, e = j;
			break;
		}
	}
	printf("yes\n%d %d\n", s, e);
	return 0;
}
