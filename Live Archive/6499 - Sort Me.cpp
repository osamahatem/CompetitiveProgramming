#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int order[26];

bool cmp(const string &a, const string &b) {
	int i = 0;
	while (i < (int) a.size() && i < (int) b.size()) {
		int ca = a[i] - 'A', cb = b[i] - 'A';
		if (order[ca] != order[cb])
			return order[ca] < order[cb];
		i++;
	}
	return i == (int) a.size();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, tc = 1;
	string s;
	while (scanf("%d", &n), n) {
		cin >> s;
		for (int i = 0; i < 26; i++)
			order[s[i] - 'A'] = i;
		vector<string> all;
		while (n--) {
			cin >> s;
			all.push_back(s);
		}
		sort(all.begin(), all.end(), cmp);
		printf("year %d\n", tc++);
		for (int i = 0; i < (int) all.size(); i++)
			printf("%s\n", all[i].c_str());
	}
	return 0;
}
