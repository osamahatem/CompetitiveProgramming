////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1332B. Composite Coloring.cpp
//	Problem Source: Codeforces Round #630 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 31/03/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	All given numbers are composite, which means they're the product of at least
//  2 primes. There are only 11 primes that are less than sqrt(1000), so we can
//  group numbers in any way such that all coloured the same share one of those
//  11 primes.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

const int P_SZ = 11;

int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
int arr[1005];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int used[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
        int colours = 0;

        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            for (int j = 0; j < P_SZ; j++) {
                if (arr[i] % primes[j] == 0) {
                    if (!used[j]) {
                        used[j] = ++colours;
                    }
                    arr[i] = used[j];
                    break;
                }
            }
        }

        cout << colours << "\n";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " \n"[i + 1 == n];
    }

    return 0;
}
