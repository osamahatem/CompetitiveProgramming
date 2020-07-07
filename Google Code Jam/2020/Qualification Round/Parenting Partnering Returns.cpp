////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Parenting Partnering Returns.cpp
//	Problem Source: GCJ 2020 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        vector<pair<pair<int, int>, int>> acts(n);
        for (int i = 0; i < n; i++) {
            cin >> acts[i].first.first >> acts[i].first.second;
            acts[i].second = i;
        }

        sort(acts.begin(), acts.end());

        string ans(n, 'C');
        int t1 = 0, t2 = 0;
        for (int i = 0; i < n; i++) {
            if (t1 <= acts[i].first.first)
                t1 = acts[i].first.second;
            else if (t2 <= acts[i].first.first)
                t2 = acts[i].first.second, ans[acts[i].second] = 'J';
            else {
                ans = "IMPOSSIBLE";
                break;
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}

