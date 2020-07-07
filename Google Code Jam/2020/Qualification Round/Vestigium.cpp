////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: Vestigium.cpp
//	Problem Source: GCJ 2020 - Qualification Round
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 04/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int mat[105][105], vis[105], id = 0;

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
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];

        int k = 0, r = 0, c = 0;

        for (int i = 0; i < n; i++)
            k += mat[i][i];

        for (int i = 0; i < n; i++) {
            id++;
            for (int j = 0; j < n; j++) {
                if (vis[mat[i][j]] == id) {
                    r++;
                    break;
                }
                vis[mat[i][j]] = id;
            }
        }

        for (int i = 0; i < n; i++) {
            id++;
            for (int j = 0; j < n; j++) {
                if (vis[mat[j][i]] == id) {
                    c++;
                    break;
                }
                vis[mat[j][i]] = id;
            }
        }

        cout << "Case #" << t << ": " << k << " " << r << " " << c << endl;
    }

    return 0;
}

