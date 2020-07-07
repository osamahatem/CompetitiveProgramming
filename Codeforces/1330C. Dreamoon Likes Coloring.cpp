////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1330C. Dreamoon Likes Coloring.cpp
//	Problem Source: Codeforces Round #631 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 03/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Looping over the colours from end to start, we fill the cells, also from end
//  to start, in such a way that every colour is applied starting at the
//  earliest position satisfying the following constraints:
//  1.  No gaps are left between the cells of this colour and the previous one.
//  2.  There is at least 1 empty cell left for each of the remaining colour.
//
//  If it's not possible to satisfy those constraints at any step, a valid
//  colouring is not possible.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int arr[100005], ans[100005];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    int last = n + 1;
    for (int i = m - 1; ~i; i--) {
        int max_pos = min(n - arr[i] + 1, last - 1);
        int min_pos = max(i + 1, last - arr[i]);

        if (min_pos > max_pos) {
            cout << "-1\n";
            return 0;
        }

        ans[i] = last = min_pos;
    }

    if (last != 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << " \n"[i + 1 == m];

    return 0;
}

