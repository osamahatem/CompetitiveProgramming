/*
 * 12596 - Recursive Texting.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long memo[21][26];
int num[26];
string nums[10];

long long solve(int n, int c) {
	if (n == 1)
		return nums[num[c]].size();
	long long &ret = memo[n][c];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < (int) nums[num[c]].size(); i++)
		ret += solve(n - 1, nums[num[c]][i] - 'A');
	return ret;
}

void init() {
	memset(memo, -1, sizeof memo);
	nums[2] = "TWO";
	nums[3] = "THREE";
	nums[4] = "FOUR";
	nums[5] = "FIVE";
	nums[6] = "SIX";
	nums[7] = "SEVEN";
	nums[8] = "EIGHT";
	nums[9] = "NINE";
	int c = 0;
	for (int n = 2; n <= 9; n++) {
		int x = 3;
		if (n == 7 || n == 9)
			x++;
		for (int i = 0; i < x; i++)
			num[c++] = n;
	}
}

char ans(int n, int k, string S) {
	if (n == 0)
		return S[k - 1];
	for (int i = 0; i < (int) S.size(); i++) {
		long long temp = solve(n, S[i] - 'A');
		if (temp < k)
			k -= temp;
		else {
			return ans(n - 1, k, nums[num[S[i] - 'A']]);
		}
	}
	return 'a';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, k;
		string S;
		cin >> S >> n >> k;
		cout << "Case " << t << ": " << ans(n, k, S) << "\n";
	}
	return 0;
}
