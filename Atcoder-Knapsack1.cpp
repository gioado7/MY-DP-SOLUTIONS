#include <bits/stdc++.h>
using namespace std;


#define ll long long


int main4() {
    ios::sync_with_stdio(false);

    int n, W;
    cin >> n >> W;

    vector<ll> w(n + 1);
    vector<ll> v(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> w[i];
        cin >> v[i];
    }

    vector<vector<ll>> dp(n + 1);
    for (int i = 0; i < n + 1; i++) {
        if (i == 0) {
            vector<ll> cur(W + 1, 0);
            dp[0] = cur;
            continue;
        }
        vector<ll> cur(W + 1); cur[0] = 0;
        dp[i] = cur;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (j - w[i] < 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }else {
                dp[i][j] = max(max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]), dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][W] << endl;

    return 0;
}