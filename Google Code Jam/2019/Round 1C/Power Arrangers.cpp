////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Power Arrangers.cpp
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

string scan;

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int T, F;
    cin >> T >> F;
    while (T--) {
        vector<int> to_look;
        for (int i = 0; i + 1 < 120; i++) {
            to_look.push_back(i);
        }

        string ans = "";
        for (int i = 0; i < 5; i++) {
            map<char, vector<int>> locations;
            for (int c = 0; c < 5; c++) {
                if (ans.find('A' + c) == -1) {
                    locations['A' + c];
                }
            }

            for (auto j : to_look) {
                cout << j * 5 + i + 1 << endl;
                cin >> scan;
                locations[scan[0]].push_back(j);
            }

            char nxt = 'x';
            int mini = 600;
            for (auto p : locations) {
                if (p.second.size() < mini) {
                    nxt = p.first;
                    mini = p.second.size();
                }
            }
            ans += nxt;
            to_look = locations[nxt];
        }
        cout << ans << endl;
        cin >> scan;
        assert(scan == "Y");
    }

    return 0;
}
