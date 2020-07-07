////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: You Can Go Your Own Way.cpp
//	Problem Source: GCJ 2019 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 06-04-2019
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Solution summary goes here.
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
        string path;
        cin >> n >> path;

        string ans = "";
        for (int i = 0; i < path.length(); i++) {
            ans += path[i] == 'E' ? 'S' : 'E';
        }

        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
