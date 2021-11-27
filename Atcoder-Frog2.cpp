#include <bits/stdc++.h>
using namespace std;



#define ll long long

ll helper(vector<ll>& dp, vector<ll>& vec, int j, int& g) {
    ll res = LONG_LONG_MAX;
    if (j >= g) {
        for (int k = j - g; k < j; k++) {
            res = min(res, dp[k] + abs(vec[j] - vec[k]));
        }
    }else {
        for (int k = 0; k < j; k++) {
            res = min(res, dp[k] + abs(vec[j] - vec[k]));
        }
    }
    return res;
}

int main2() {
    ios::sync_with_stdio(false);


    int n, g;
    cin >> n >> g;
    vector<ll> vec(n);
    for (int i = 0; i < n; i++) cin >> vec[i];

    vector<ll> dp(n); dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = helper(dp, vec, i, g);
    }


    cout << dp[n - 1] << endl;


    return 0;
}