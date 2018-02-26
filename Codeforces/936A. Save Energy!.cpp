/*
 * 936A. Save Energy!.cpp
 *
 *  Created on: Feb 25, 2018
 *      Author: Osama Hatem
 */
 
/*
Let's define a cycle as the number of times we need to check the oven until it
is actually turned off, because this keeps repeating until the food is cooked.
During a cycle, we can easily calculate the amount of cooking time gained,
divide the target by that amount, and then easily handle the remainder time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long k, d, t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> k >> d >> t;
	t *= 2;
	long long cycle = k / d * d;
	if (k % d)
		cycle += d;
	long long per_cycle = cycle + k;
	double ans = (t / per_cycle) * cycle;
	t %= per_cycle;
	if (t <= k + k)
		ans += 0.5 * t;
	else {
		t -= k + k;
		ans += k + t;
	}
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
