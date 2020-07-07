////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Manhattan Crepe Cart.cpp
//	Problem Source: GCJ 2019 - Round 1B
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 28-04-2019
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
        int p, q;
        cin >> p >> q;

        vector<int> important, north, south, east, west;
        for (int i = 0; i < p; i++) {
            int x, y;
            string dir;
            cin >> x >> y >> dir;

            important.push_back(x);
            if (x > 0) important.push_back(x - 1);
            if (x < q) important.push_back(x + 1);
            important.push_back(y);
            if (y > 0) important.push_back(y - 1);
            if (y < q) important.push_back(y + 1);

            if (dir == "N")
                north.push_back(y);
            else if (dir == "S")
                south.push_back(y);
            else if (dir == "E")
                east.push_back(x);
            else
                west.push_back(x);
        }

        important.push_back(0);
        sort(important.begin(), important.end());
        important.erase(unique(important.begin(), important.end()),
                        important.end());

        sort(north.begin(), north.end());
        sort(south.begin(), south.end());
        sort(east.begin(), east.end());
        sort(west.begin(), west.end());

        int maxi = -1, ansx, ansy;
        for (auto x : important) {
            for (auto y : important) {
                int cnt = 0;
                if (x > 0)
                    cnt +=
                        lower_bound(east.begin(), east.end(), x) - east.begin();
                if (x < q)
                    cnt +=
                        west.end() - upper_bound(west.begin(), west.end(), x);
                if (y > 0)
                    cnt += lower_bound(north.begin(), north.end(), y) -
                           north.begin();
                if (y < q)
                    cnt += south.end() -
                           upper_bound(south.begin(), south.end(), y);

                if (cnt > maxi || (cnt == maxi && x < ansx) ||
                    (cnt == maxi && x == ansx && y < ansy))
                    maxi = cnt, ansx = x, ansy = y;
            }
        }

        cout << "Case #" << t << ": " << ansx << " " << ansy << endl;
    }

    return 0;
}
