/*
 * G. Nen Categories.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("nen.in", "r", stdin);
	int T;
	cin >> T;
	while (T--) {
		int en, tr, co, em, ma;
		cin >> en >> tr >> co >> em >> ma;
		int sen = en * 3 + (em + tr) * 2;
		int str = tr * 3 + (en + co) * 2;
		int sco = co * 3 + tr * 2;
		int sem = em * 3 + (en + ma) * 2;
		int sma = ma * 3 + em * 2;
		int sp = (co + ma) * 2;
		int maxi = -1;
		string ans;
		if (sen > maxi)
			maxi = sen, ans = "Enhancer";
		if (str > maxi)
			maxi = str, ans = "Transmuter";
		if (sco > maxi)
			maxi = sco, ans = "Conjurer";
		if (sem > maxi)
			maxi = sem, ans = "Emitter";
		if (sma > maxi)
			maxi = sma, ans = "Manipulator";
		if (sp > maxi)
			maxi = sp, ans = "Specialist";
		cout << ans << endl;
	}
	return 0;
}
