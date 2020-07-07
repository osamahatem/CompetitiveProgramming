#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;
const double INF = 1e18;

int N, head[45], from[1000], to[1000], cap[1000], next[1000], last, id = 0,
		inQ[45], par[45];
double cost[1000], dist[45];

void addEdge(int f, int t, int cp, double cst) {
	next[last] = head[f];
	from[last] = f;
	to[last] = t;
	cap[last] = cp;
	cost[last] = cst;
	head[f] = last++;
}

void addAugEdge(int f, int t, int cp, double cst) {
	addEdge(f, t, cp, cst);
	addEdge(t, f, 0, -cst);
}

bool bellman(int src) {
	fill(dist, dist + N + 1, INF);
	dist[src] = 0.0;
	queue<int> Q;
	Q.push(src);
	for (int i = 0; i <= N; i++) {
		int s = Q.size();
		while (s--) {
			int cur = Q.front();
			Q.pop();
			inQ[cur] = 0;
			for (int i = head[cur]; i != -1; i = next[i]) {
				if (cap[i] && dist[to[i]] > dist[cur] + cost[i]) {
					dist[to[i]] = dist[cur] + cost[i];
					par[to[i]] = i;
					if (!inQ[to[i]])
						Q.push(to[i]), inQ[to[i]] = id;
				}
			}
		}
		if (Q.empty())
			break;
	}
	return dist[N] < INF;
}

double minCostMaxFlow(int src) {
	double ans = 0.0;
	while (1) {
		id++;
		if (!bellman(src))
			break;
		ans += dist[N];
		for (int i = N; i != src; i = from[par[i]]) {
			cap[par[i]]--;
			cap[par[i] ^ 1]++;
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m), n || m) {
		last = 0;
		memset(head, -1, sizeof head);
		N = n + m + 1;
		for (int i = 1; i <= m; i++)
			addAugEdge(0, i, 1, 0);
		for (int i = 1; i <= n; i++)
			addAugEdge(m + i, N, 1, 0);

		double temp;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%lf", &temp);
				addAugEdge(j, m + i, 1, temp);
			}
		}

		printf("%.2f\n", minCostMaxFlow(0) / n + EPS);
	}
	return 0;
}
