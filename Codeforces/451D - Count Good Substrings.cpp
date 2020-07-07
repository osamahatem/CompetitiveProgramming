#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	char arr[100005];
	scanf("%s", arr);
	int len = strlen(arr), cntOdd[2], cntEven[2];
	cntOdd[0] = cntOdd[1] = cntEven[0] = cntEven[1] = 0;
	long long ansOdd = 0, ansEven = 0;
	for (int i = 0; i < len; i++) {
		ansOdd++;
		int c = arr[i] - 'a';
		if (i % 2 == 0) {
			ansOdd += cntEven[c];
			ansEven += cntOdd[c];
			cntEven[c]++;
		} else {
			ansOdd += cntOdd[c];
			ansEven += cntEven[c];
			cntOdd[c]++;
		}
	}
	printf("%I64d %I64d\n", ansEven, ansOdd);
	return 0;
}
