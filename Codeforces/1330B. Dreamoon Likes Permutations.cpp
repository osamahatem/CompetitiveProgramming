////////////////////////////////////////////////////////////////////////////////
//
//	Solution Name: 1330B. Dreamoon Likes Permutations.cpp
//	Problem Source: Codeforces Round #631 (Div. 2)
//
// 	Author: Osama Hatem Sharafeldin
//	Date: 03/04/2020
//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
//
//	Assume all elements belong to one permutation, then move elements one-by-one
//  while checking, after each move, whether the current partition is valid,
//  e.g. both are correct permutations.
//
////////////////////////////////////////////////////////////////////////////////

#include <bits/stdc++.h>

using namespace std;

int arr[200005], cnt[200005];

int main() {
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        set<int> s1, s2;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s2.insert(arr[i]), cnt[arr[i]]++;
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i + 1 < n; i++) {
            cnt[arr[i]]--;
            if (cnt[arr[i]] == 0)
                s2.erase(arr[i]);
            s1.insert(arr[i]);

            if (s1.size() == i + 1 && *s1.rbegin() == i + 1 && s2.size() == n - i - 1 && *s2.rbegin() == n - i - 1)
                ans.push_back({ i + 1, n - i - 1 });
        }
        cnt[arr[n - 1]]--;

        cout << ans.size() << endl;
        for (auto p : ans)
            cout << p.first << " " << p.second << endl;
    }

    return 0;
}

