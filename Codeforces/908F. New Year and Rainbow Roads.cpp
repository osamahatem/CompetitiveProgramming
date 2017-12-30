/*
 * 908F. New Year and Rainbow Roads.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56713
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int INF = 2e9;

int n, p[MAXN];
vector<int> blue, red;
char co[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long ans = 0;
	scanf("%d", &n);
	int last = -1;
	for (int i = 0; i < n; i++) {
		scanf("%d%*c%c", &p[i], &co[i]);
		if (co[i] == 'B')
			blue.push_back(p[i]);
		if (co[i] == 'R')
			red.push_back(p[i]);
		if (co[i] == 'G') {
			long long maxB = 0, maxR = 0;

			for (int j = 1; j < (int) blue.size(); j++)
				maxB = max(maxB, 0ll + blue[j] - blue[j - 1]);
			if (blue.size())
				maxB = max(maxB, 0ll + p[i] - blue.back());
			if (last != -1 && blue.size())
				maxB = max(maxB, 0ll + blue[0] - last);

			for (int j = 1; j < (int) red.size(); j++)
				maxR = max(maxR, 0ll + red[j] - red[j - 1]);
			if (red.size())
				maxR = max(maxR, 0ll + p[i] - red.back());
			if (last != -1 && red.size())
				maxR = max(maxR, 0ll + red[0] - last);

			if (last != -1) {
				long long temp1 = p[i] - last;
				if (blue.size())
					temp1 += p[i] - last;
				if (red.size())
					temp1 += p[i] - last;
				temp1 = min(temp1, 2ll * (p[i] - last));

				long long temp2 = p[i] - last;
				if (blue.size())
					temp2 += p[i] - last - maxB;
				if (red.size())
					temp2 += p[i] - last - maxR;

				ans += min(temp1, temp2);
			} else {
				if (blue.size())
					ans += p[i] - blue[0];
				if (red.size())
					ans += p[i] - red[0];
			}
			red.clear(), blue.clear(), last = p[i];
		}
	}
	for (int i = 1; i < (int) blue.size(); i++)
		ans += blue[i] - blue[i - 1];
	for (int i = 1; i < (int) red.size(); i++)
		ans += red[i] - red[i - 1];
	if (last != -1) {
		if (blue.size())
			ans += blue[0] - last;
		if (red.size())
			ans += red[0] - last;
	}
	cout << ans << endl;
	return 0;
}
