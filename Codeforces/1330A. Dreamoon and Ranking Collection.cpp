////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1330A. Dreamoon and Ranking Collection.cpp
//	Problem Source: Codeforces Round #631 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 03/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Just use the x attempts you have to fill the first empty x ranks, and that
//  will give the answer.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int arr[205];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        memset(arr, 0, sizeof(arr));

        while (n--) {
            int temp;
            cin >> temp;
            arr[temp] = 1;
        }

        int ans = 0;
        while (x >= 0) {
            ans++;
            if (arr[ans] == 0)
                x--;
        }

        cout << --ans << endl;
    }

    return 0;
}

