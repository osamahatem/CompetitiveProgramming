/*
 * 385E. Bear in the Field.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, sx, sy, dx, dy;
long long t;

template<class T>
class Matrix {
	vector<vector<T>> data;
	int h, w;

public:
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

	pair<int, int> getDimensions() const {
		return make_pair(h, w);
	}

	void resize(int h, int w) {
		this->h = h;
		this->w = w;
		data.resize(h, vector<T>(w));
	}

	vector<T>& operator [](int i) {
		return data[i];
	}

	const vector<T>& operator [](int i) const {
		return data[i];
	}

	Matrix<T>& operator =(const Matrix<T>& a) {
		resize(a.getDimensions().first, a.getDimensions().second);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				data[i][j] = a[i][j];
		return *this;
	}

	Matrix<T> operator *(const Matrix<T>& a) const {
		int hh = a.getDimensions().first, ww = a.getDimensions().second;
		Matrix<T> ret(h, ww);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < ww; j++) {
				T val = 0;
				for (int k = 0; k < hh; k++)
					val += data[i][k] * a[k][j];
				ret[i][j] = val;
			}
		return ret;
	}

	Matrix<T> operator %(long long mod) const {
		Matrix<T> ret(data);
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				ret[i][j] = data[i][j] % mod;
		return ret;
	}

	Matrix<T> operator ^(long long p) const {
		Matrix<T> ret(h, w);
		Matrix<T> b(data);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++)
				ret[i][j] = 0;
			ret[i][i] = 1;
		}
		for (; p; p >>= 1) {
			if (p & 1)
				ret = ret * b % n;
			b = b * b % n;
		}
		return ret;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> sx >> sy >> dx >> dy >> t;
	sx--, sy--;
	dx = (dx % n + n) % n, dy = (dy % n + n) % n;
	vector<vector<long long>> m1 = { { sx }, { sy }, { dx }, { dy }, { 0 },
			{ 1 } };
	vector<vector<long long>> m2 = { { 2, 1, 1, 0, 1, 2 }, { 1, 2, 0, 1, 1, 2 },
			{ 1, 1, 1, 0, 1, 2 }, { 1, 1, 0, 1, 1, 2 }, { 0, 0, 0, 0, 1, 1 }, {
					0, 0, 0, 0, 0, 1 } };
	Matrix<long long> res(m1), P(m2);
	res = res % n;
	P = P % n;
	P = P ^ t;
	res = P * res % n;
	cout << ++res[0][0] << " " << ++res[1][0] << endl;
	return 0;
}
