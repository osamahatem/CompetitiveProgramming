/*
 * 350D. Looking for Owls.cpp
 *
 *  Created on: Aug 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct fraction {
	long long a, b;

	fraction() {
		a = b = 0;
	}

	fraction(long long aa, long long bb) {
		if (!bb)
			a = 1, b = 0;
		else if (!aa)
			a = 0, b = 1;
		else {
			long long g = __gcd(abs(aa), abs(bb));
			aa /= g, bb /= g;
			if (bb < 0)
				aa *= -1, bb *= -1;
			a = aa, b = bb;
		}
	}

	const bool operator <(const fraction& rhs) const {
		return a * rhs.b < b * rhs.a;
	}

	const bool operator ==(const fraction& rhs) const {
		return !(*this < rhs) && !(rhs < *this);
	}

	const bool operator <=(const fraction& rhs) const {
		return !(rhs < *this);
	}

	const bool operator !=(const fraction& rhs) const {
		return *this < rhs || rhs < *this;
	}

	fraction& operator =(const fraction& rhs) {
		a = rhs.a, b = rhs.b;
		return *this;
	}

	fraction operator +(const fraction& rhs) const {
		return fraction(a * rhs.b + b * rhs.a, b * rhs.b);
	}

	fraction& operator +=(const fraction& rhs) {
		return *this = *this + rhs;
	}

	fraction operator -(const fraction& rhs) const {
		return fraction(a * rhs.b - b * rhs.a, b * rhs.b);
	}

	fraction& operator -=(const fraction& rhs) {
		return *this = *this - rhs;
	}

	fraction operator *(const fraction& rhs) const {
		return fraction(a * rhs.a, b * rhs.b);
	}

	fraction& operator *=(const fraction& rhs) {
		return *this = *this * rhs;
	}

	fraction operator /(const fraction& rhs) const {
		return fraction(a * rhs.b, b * rhs.a);
	}

	fraction& operator /=(const fraction& rhs) {
		return *this = *this / rhs;
	}
};

map<pair<fraction, fraction>, vector<pair<fraction, pair<int, int>>> > lines;
int x[1500], y[1500], r[1500];

vector<pair<fraction, pair<int, int>>> fix(vector<pair<fraction, pair<int, int>>> in) {
	sort(in.begin(), in.end());
	vector<pair<fraction, pair<int, int>>> ret;
	ret.push_back(make_pair(fraction(-100000, 1), make_pair(0, 0)));
	for (int i = 0; i < (int) in.size(); i++) {
		ret.push_back(in[i]);
		ret[i + 1].second = make_pair(0, 0);
	}
	ret.push_back(make_pair(fraction(100000, 1), make_pair(0, 0)));
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	int idx = 0;
	for (int i = 0; i < (int) ret.size(); i++) {
		while (idx < (int) in.size() && in[idx].first <= ret[i].first) {
			ret[i].second.first += in[idx].second.first;
			ret[i + 1].second.second += in[idx].second.second;
			idx++;
		}
		if (i) {
			ret[i].second.first += ret[i - 1].second.first;
			ret[i].second.second += ret[i - 1].second.second;
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);

	while (n--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		fraction m = fraction(y1 - y2, x1 - x2);
		fraction c;
		if (m.a == 1 && m.b == 0)
			c = fraction(x1, 1);
		else
			c = fraction(y1, 1) - m * fraction(x1, 1);
		if (x1 > x2)
			swap(x1, x2);
		pair<fraction, fraction> temp = make_pair(m, c);
		lines[temp].push_back(make_pair(fraction(x1, 1), make_pair(1, 0)));
		lines[temp].push_back(make_pair(fraction(x2, 1), make_pair(0, 1)));
	}
	for (auto it = lines.begin(); it != lines.end(); it++) {
		it->second = fix(it->second);
	}

	long long ans = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
		for (int j = 0; j < i; j++) {
			int dx = x[i] - x[j], dy = y[i] - y[j], rr = 2 * r[i];
			if (r[j] != r[i] || dx * dx + dy * dy <= rr * rr)
				continue;
			fraction xc = fraction(x[i] + x[j], 2);
			fraction yc = fraction(y[i] + y[j], 2);
			fraction m = fraction(x[i] - x[j], y[j] - y[i]);
			fraction c;
			if (m.a == 1 && m.b == 0)
				c = xc;
			else
				c = yc - m * xc;
			pair<fraction, fraction> temp = make_pair(m, c);
			if (lines.count(temp)) {
				pair<fraction, pair<int, int>> tar = make_pair(xc,
						make_pair(0, 0));
				int idx = lower_bound(lines[temp].begin(), lines[temp].end(),
						tar) - lines[temp].begin();
				if (lines[temp][idx].first == tar.first)
					ans += lines[temp][idx].second.first
							- lines[temp][idx].second.second;
				else
					ans += lines[temp][idx - 1].second.first
							- lines[temp][idx].second.second;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
