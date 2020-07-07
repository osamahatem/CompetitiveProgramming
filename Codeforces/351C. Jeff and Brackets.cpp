/*
 * 351C. Jeff and Brackets.cpp
 *
 *  Created on: Jul 24, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 2e9 + 5;

template<class T>
class Matrix {
	vector<vector<T>> data;
	int h, w;

public:
	Matrix<T>() {
		h = w = 0;
		data = vector<vector<T>>();
	}

	Matrix<T>(vector<vector<T>> data) {
		this->data = data;
		h = data.size();
		w = data[0].size();
	}

	Matrix<T>(int h, int w) {
		this->h = h;
		this->w = w;
		data = vector<vector<T> >(h, vector<T>(w));
	}

	void resize(int h, int w) {
		this->h = h;
		this->w = w;
		data.resize(h, vector<T>(w));
	}

	pair<int, int> getDimensions() const {
		return make_pair(h, w);
	}

	vector<T>& operator [](int i) {
		return data[i];
	}

	const vector<T>& operator [](int i) const {
		return data[i];
	}

	Matrix<T>& operator =(const Matrix<T> a) {
		resize(a.getDimensions().first, a.getDimensions().second);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				data[i][j] = a[i][j];
		return *this;
	}

	Matrix<T> operator *(const Matrix<T> a) {
		int ww = a.getDimensions().second;
		Matrix<T> ret(h, ww);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < ww; j++) {
				T val = INF;
				for (int k = 0; k < w; k++)
					val = min(val, data[i][k] + a[k][j]);
				ret[i][j] = val;
			}
		return ret;
	}

	Matrix<T>& operator *=(const Matrix<T> a) {
		return *this = *this * a;
	}

	Matrix<T> operator ^(long long p) const {
		Matrix<T> ret(h, w);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				ret[i][j] = i == j ? 0 : INF;
		Matrix<T> b(data);
		for (; p; p >>= 1) {
			if (p & 1)
				ret *= b;
			b *= b;
		}
		return ret;
	}

	Matrix<T>& operator ^=(long long p) {
		return *this = *this ^ p;
	}
};

int n, m, a[20], b[20], dp[21][21][20];

int solve(int before, int after, int idx = 0) {
	if (before < 0 || before > n)
		return INF;
	if (idx == n)
		return before == after ? 0 : INF;
	int &ret = dp[before][after][idx];
	if (ret != -1)
		return ret;
	ret = min(solve(before + 1, after, idx + 1) + a[idx],
			solve(before - 1, after, idx + 1) + b[idx]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(dp, -1, sizeof dp);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<vector<long long>> data(n + 1, vector<long long>(n + 1));
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			data[i][j] = solve(i, j);
	Matrix<long long> M(data);
	M ^= m;
	cout << M[0][0] << endl;
	return 0;
}
