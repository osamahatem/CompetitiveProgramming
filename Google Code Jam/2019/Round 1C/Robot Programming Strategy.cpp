////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Robot Programming Strategy.cpp
//	Problem Source: GCJ 2019 - Round 1C
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04-05-2019
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Solution summary goes here.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 500;
const int MAX_A = 255;

int trie[MAX_A * MAX_LEN + 5][3], idx;
int dp[MAX_A * MAX_LEN + 5][MAX_LEN + 5];

void insert(string str) {
    int cur = 0;
    for (int i = 0; str[i]; i++) {
        int nxt = str[i] == 'R' ? 0 : (str[i] == 'P' ? 1 : 2);
        if (trie[cur][nxt] == -1) {
            trie[cur][nxt] = ++idx;
        }
        cur = trie[cur][nxt];
    }
}

bool solve(int node, int len) {
    if (len == MAX_LEN) {
        return false;
    }

    if (node == -1) {
        return true;
    }

    if (trie[node][0] != -1 && trie[node][1] != -1 && trie[node][2] != -1) {
        return false;
    }

    if (dp[node][len] != -1) {
        return dp[node][len];
    }

    bool ans = false;
    for (int i = 0; i < 3; i++) {
        if (trie[node][i] == -1) {
            ans |= solve(trie[node][(i + 2) % 3], len + 1);
        }
    }
    return dp[node][len] = ans;
}

string build(int node, int len) {
    if (node == -1 || len == MAX_LEN) {
        return "";
    }

    for (int i = 0; i < 3; i++) {
        if (trie[node][i] == -1 && solve(trie[node][(i + 2) % 3], len + 1)) {
            int nxt = (i + 2) % 3;
            string ans = nxt == 0 ? "R" : (nxt == 1 ? "P" : "S");
            ans += build(trie[node][(i + 2) % 3], len + 1);
            return ans;
        }
    }

    return "";
}

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(dp, -1, sizeof dp);
        memset(trie, -1, sizeof trie);
        idx = 0;

        int A;
        cin >> A;

        while (A--) {
            string temp;
            cin >> temp;
            while (temp.length() < MAX_LEN) {
                temp += temp;
            }
            temp = temp.substr(0, MAX_LEN);
            insert(temp);
        }

        cout << "Case #" << t << ": ";
        if (solve(0, 0)) {
            cout << build(0, 0) << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
