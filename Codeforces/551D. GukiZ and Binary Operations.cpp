/*
 * 551D. GukiZ and Binary Operations.cpp
 *
 *  Created on: Jun 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

template<class T>
class Matrix {
	vector<vector<T> > data;
	int h, w;

public:
	Matrix<T>() {
		h = w = 0;
		data = vector<vector<T> >();
	}

	Matrix<T>(int h, int w, bool identity) {
		this->h = h;
		this->w = w;
		data = vector<vector<T> >(h, vector<T>(w, 0));
		if (identity)
			for (int i = 0; i < h; i++)
				data[i][i] = 1;
	}

	pair<int, int> getDimensions() {
		return make_pair(h, w);
	}

	void resize(int h, int w) {
		this->h = h;
		this->w = w;
		data.resize(h, vector<T>(w));
	}

	Matrix<T>(vector<vector<T> > data) {
		this->data = data;
		h = data.size();
		w = data[0].size();
	}

	void setElementAt(int r, int c, T val) {
		data[r][c] = val;
	}

	T getElementAt(int r, int c) {
		return data[r][c];
	}

	Matrix<T> operator *(T val) {
		Matrix<T> ret(h, w, 0);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				ret.setElementAt(i, j, val * data[i][j]);
		return ret;
	}

	Matrix<T> operator *=(T val) {
		return this * val;
	}

	Matrix<T> operator *(Matrix<T> a) {
		Matrix<T> ret(h, a.getDimensions().second, 0);
		for (int i = 0; i < ret.getDimensions().first; i++)
			for (int j = 0; j < ret.getDimensions().second; j++) {
				T val = 0;
				for (int k = 0; k < a.getDimensions().first; k++)
					val += data[i][k] * a.getElementAt(k, j);
				ret.setElementAt(i, j, val);
			}
		return ret;
	}

	Matrix<T> operator *=(Matrix<T> a) {
		return this * a;
	}

	Matrix<T> operator %(long long mod) {
		Matrix<T> ret(data);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				ret.setElementAt(i, j, data[i][j] % mod);
		return ret;
	}

	Matrix<T> operator %=(long long mod) {
		return this % mod;
	}

	static Matrix<T> power(Matrix<T> b, long long p, long long mod) {
		Matrix<T> ret(b.getDimensions().first, b.getDimensions().second, 1);
		for (; p; p >>= 1) {
			if (p & 1)
				ret = ret * b % mod;
			b = b * b % mod;
		}
		return ret % mod;
	}
};

long long fastPower(long long b, long long p, long long mod) {
	long long ret = 1;
	for (; p; p >>= 1) {
		if (p & 1)
			ret = ret * b % mod;
		b = b * b % mod;
	}
	return ret % mod;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long n, k, m, temp;
	int l, logk = 0;
	cin >> n >> k >> l >> m;
	temp = k;
	while (temp) {
		temp /= 2;
		logk++;
	}
	if (logk > l) {
		cout << 0 << endl;
		return 0;
	}
	vector<vector<long long> > m1 = { { 0, 1 }, { 1, 1 } };
	vector<vector<long long> > m2 = { { 0 }, { 1 } };
	Matrix<long long> M1(m1), M2(m2);
	Matrix<long long> fib = Matrix<long long>::power(M1, n + 2, m) * M2;
	long long zero = fib.getElementAt(0, 0);
	long long one = (fastPower(2, n, m) - zero + m) % m;
	long long ans = 1 % m;
	for (int i = 0; i < l; i++) {
		ans = ans * (k & 1 ? one : zero) % m;
		k /= 2;
	}
	cout << ans << endl;
	return 0;
}
