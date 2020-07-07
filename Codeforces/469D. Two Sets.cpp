/*
 * 469D. Two Sets.cpp
 *
 *  Created on: Jun 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int, int> pos;
int arr[100005];
bool invalidA[100005], invalidB[100005];

struct DisjointSet {
	vector<int> root, rank;

	DisjointSet(int n) {
		for (int i = 0; i < n; i++) {
			root.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int n) {
		return (root[n] == n ? root[n] : root[n] = find(root[n]));
	}

	bool merge(int a, int b) {
		int sa = find(a);
		int sb = find(b);
		if (sa == sb)
			return false;
		if (rank[sa] < rank[sb])
			root[sa] = root[sb];
		else
			root[sb] = root[sa];
		if (rank[sa] == rank[sb])
			rank[sa]++;
		return true;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		pos[arr[i]] = i;
	}
	DisjointSet DS(n);
	for (int i = 0; i < n; i++) {
		if (pos.count(a - arr[i]))
			DS.merge(i, pos[a - arr[i]]);
		if (pos.count(b - arr[i]))
			DS.merge(i, pos[b - arr[i]]);
	}
	for (int i = 0; i < n; i++) {
		int setID = DS.find(i);
		if (!pos.count(a - arr[i]))
			invalidA[setID] = 1;
		if (!pos.count(b - arr[i]))
			invalidB[setID] = 1;
	}
	for (int i = 0; i < n; i++)
		if (invalidA[i] && invalidB[i]) {
			printf("NO\n");
			return 0;
		}
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		int setID = DS.find(i);
		printf("%d", invalidA[setID]);
	}
	printf("\n");
	return 0;
}
