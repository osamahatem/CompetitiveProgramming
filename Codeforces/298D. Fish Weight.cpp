/*
 * 298D. Fish Weight.cpp
 *
 *  Created on: Nov 28, 2014
 *      Author: Osama Hatem
 */
 
/*
If there exists an index i such that a[i] > b[i], the answer is 'YES'. Old (bad)
implementation; I don't remember what I was thinking.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k, a[100005], b[100005];
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a, a + n);
	sort(b, b + m);
	int i = 0, j = 0;
	bool flag = 0;
	while (i < n && j < m) {
		int cnt = 0;
		while (j < m && b[j] < a[i])
			flag = 1, j++, cnt++;
		if (!cnt)
			j++;
		i++;
	}
	if (i < n || (i == n && j == m && flag))
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
