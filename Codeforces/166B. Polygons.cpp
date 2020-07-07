/*
 * 166B. Polygons.cpp
 *
 *  Created on: Jul 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXM = 2e4 + 5;

struct point {
	int x, y;
};

point A[MAXN], B[MAXM], P;

long long ccw(const point &p1, const point &p2, const point &p3) {
	return (long long) (p2.x - p1.x) * (p3.y - p1.y)
			- (long long) (p2.y - p1.y) * (p3.x - p1.x);
}

long long distSq(const point &p1, const point &p2) {
	return (long long) (p1.x - p2.x) * (p1.x - p2.x)
			+ (long long) (p1.y - p2.y) * (p1.y - p2.y);
}

bool cmp(const point &p1, const point &p2) {
	long long c = ccw(P, p1, p2);
	return (c != 0 ? c > 0 : distSq(P, p1) < distSq(P, p2));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &A[i].x, &A[i].y);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &B[i].x, &B[i].y);
	P = A[0];
	for (int i = 1; i < n; i++)
		if ((A[i].y < P.y) || (A[i].y == P.y && A[i].x < P.x))
			P = A[i];
	for (int i = 0; i < m; i++)
		if ((B[i].y < P.y) || (B[i].y == P.y && B[i].x < P.x))
			P = B[i];
	sort(A, A + n, cmp);
	sort(B, B + m, cmp);
	A[n] = A[0];
	int cur = 0;
	for (int i = 0; i < m && cur < n; i++) {
		long long c2 = ccw(P, B[i], A[cur + 1]);
		long long c1 = ccw(P, B[i], A[cur]);
		long long c3 = ccw(A[cur], A[cur + 1], B[i]);
		if (c2 >= 0 && c1 <= 0 && c3 <= 0) {
			printf("NO\n");
			return 0;
		}
		if (c2 <= 0)
			cur++, i--;
	}
	printf("YES\n");
	return 0;
}
