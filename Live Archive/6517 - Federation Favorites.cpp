#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n), n != -1) {
		vector<int> divisors;
		int sum = 1;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				sum += i;
				divisors.push_back(i);
				if (i != n / i) {
					sum += n / i;
					divisors.push_back(n / i);
				}
			}
		}
		if (sum != n) {
			printf("%d is NOT perfect.\n", n);
			continue;
		}
		sort(divisors.begin(), divisors.end());
		printf("%d = 1", n);
		for (int i = 0; i < (int) divisors.size(); i++)
			printf(" + %d", divisors[i]);
		printf("\n");
	}
	return 0;
}
