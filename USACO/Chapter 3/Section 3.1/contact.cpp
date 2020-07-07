/*
 ID: 19semse1
 PROG: contact
 LANG: C++
 */
/*
 * contact.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<pair<int, int>, int> cnt;
map<pair<int, int>, int>::iterator it;
map<int, vector<string> > ans;
map<int, vector<string> >::iterator it2;

string toString(int x, int l) {
	string ret;
	for (int i = 0; i < l; i++) {
		ret += x % 2 + '0';
		x /= 2;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

bool cmp(const string &a, const string &b) {
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
//#endif

	int a, b, n;
	string in, temp;
	cin >> a >> b >> n;
	while (cin >> temp)
		in += temp;
	for (int i = a; i <= b; i++) {
		if (i > (int) in.size())
			break;
		int p = 1 << (i - 1), cur = 0;
		for (int j = 0; j < i; j++)
			cur = cur * 2 + in[j] - '0';
		cnt[make_pair(cur, i)]++;
		for (int j = i; j < (int) in.size(); j++) {
			cur -= (in[j - i] - '0') * p;
			cur = cur * 2 + in[j] - '0';
			cnt[make_pair(cur, i)]++;
		}
	}
	for (it = cnt.begin(); it != cnt.end(); it++)
		ans[it->second].push_back(toString(it->first.first, it->first.second));
	vector<pair<int, vector<string> > > out;
	for (it2 = ans.begin(); it2 != ans.end(); it2++)
		out.push_back(make_pair(it2->first, it2->second));
	for (int i = (int) ans.size() - 1; i >= 0 && n > 0; i--, n--) {
		sort(out[i].second.begin(), out[i].second.end(), cmp);
		cout << out[i].first;
		for (int j = 0, k = 0; j < (int) out[i].second.size();
				j++, k = (k + 1) % 6) {
			if (k)
				cout << " ";
			if (!k)
				cout << endl;
			cout << out[i].second[j];
		}
		cout << endl;
	}
	return 0;
}
