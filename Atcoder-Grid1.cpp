#include <bits/stdc++.h>
using namespace std;


#define ll long long


const ll MOD = 1e9 + 7;


int main() {
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    for (int i = 0; i < h; i++) cin >> g[i];

    vector<vector<ll> > dp(h, vector<ll>(w, 0)); dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (g[i][j] == '.') {
                if (i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                if (j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;


    return 0;
}
