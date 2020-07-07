/*
 * 4476 - Electric Bill.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int get_consumption(int A) {
	int total = 0;
	if (A >= 200)
		total += 100, A -= 200;
	else
		total += A / 2, A = 0;
	if (A >= 3 * 9900)
		total += 9900, A -= 3 * 9900;
	else
		total += A / 3, A = 0;
	if (A >= 5 * 990000)
		total += 990000, A -= 5 * 990000;
	else
		total += A / 5, A = 0;
	total += A / 7, A = 0;
	return total;
}

int get_money(int cons) {
	int money = 0;
	if (cons >= 100)
		money += 200, cons -= 100;
	else
		money += 2 * cons, cons = 0;
	if (cons >= 9900)
		money += 3 * 9900, cons -= 9900;
	else
		money += 3 * cons, cons = 0;
	if (cons >= 990000)
		money += 5 * 990000, cons -= 990000;
	else
		money += 5 * cons, cons = 0;
	money += 7 * cons;
	return money;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int a, b;
	while (scanf("%d%d", &a, &b), a) {
		int totalCWh = get_consumption(a);
		int s = 0, e = totalCWh;
		while (s < e) {
			int mid = (s + e) / 2;
			int m1 = get_money(mid), m2 = get_money(totalCWh - mid);
			if (m2 - m1 > b)
				s = mid + 1;
			else
				e = mid;
		}
		printf("%d\n", get_money(s));
	}
	return 0;
}
