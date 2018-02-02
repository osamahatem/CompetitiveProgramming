/*
 * 4452 - The Ministers' Major Mess.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: Osama Hatem
 */
 
/*
If a minister votes on 1 or 2 bills, all of them must match his vote for him to
be satisfied, otherwise, at most 1 bill can differ. These rules can be modelled
to an implication graph, and we can use 2-SAT to check whether a valid solution
exists.
If one does, we can test the effect of each bill decision by forcing each bill's
value to true once and to false once, and calling 2-SAT each time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 205;
const string OUT = "#yn?";

int n, m;
vector<int> adj[MAXN];
int idx[MAXN], low[MAXN], id;
bool vis[MAXN];
int stk[MAXN], stkID;
int comp[MAXN], compID;

void SCC(int src) {
	idx[src] = low[src] = ++id, stk[stkID++] = src, vis[src] = true;
	for (auto ch : adj[src]) {
		if (!vis[ch])
			SCC(ch);
		if (!comp[ch])
			low[src] = min(low[src], low[ch]);
	}
	if (low[src] == idx[src]) {
		compID++;
		do {
			comp[stk[--stkID]] = compID;
		} while (stk[stkID] != src);
	}
}

bool check() {
	memset(vis, 0, sizeof vis);
	memset(comp, 0, sizeof comp);
	for (int i = 0; i < (n << 1); i++)
		if (!vis[i])
			SCC(i);
	for (int i = 0; i < (n << 1); i += 2)
		if (comp[i] == comp[i ^ 1])
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0, k, x, arr[5];
	char c;
	while (cin >> n >> m, n) {
		for (int i = 0; i < (n << 1); i++)
			adj[i].clear();

		while (m--) {
			cin >> k;
			for (int i = 0; i < k; i++) {
				cin >> x >> c;
				x = (x - 1) << 1;
				arr[i] = x ^ (c == 'n');
			}
			if (k < 3)
				for (int i = 0; i < k; i++)
					adj[arr[i] ^ 1].push_back(arr[i]);
			else
				for (int i = 0; i < k; i++)
					for (int j = 0; j < k; j++)
						if (i != j)
							adj[arr[i] ^ 1].push_back(arr[j]);
		}

		cout << "Case " << ++T << ": ";
		if (check()) {
			string ans = "";
			for (int i = 0; i < (n << 1); i += 2) {
				int temp = 0;
				adj[i ^ 1].push_back(i);
				temp += (int) check();
				adj[i ^ 1].pop_back();
				adj[i].push_back(i ^ 1);
				temp += ((int) check()) << 1;
				adj[i].pop_back();
				ans += OUT[temp];
			}
			cout << ans << endl;
		} else
			cout << "impossible" << endl;
	}
	return 0;
}
