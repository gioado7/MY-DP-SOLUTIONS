#include <bits/stdc++.h>
using namespace std;


#define ll long long



int main3() {
    ios::sync_with_stdio(false);

    string str1, str2;
    cin >> str1 >> str2;
    unsigned int n = str1.length();
    unsigned int m = str2.length();

    vector<vector<ll>> dp(n + 1);
    for (int i = 0; i < n + 1; i++) {
        if (i == 0) {
            vector<ll> cur(m + 1, 0);
            dp[i] = cur;
            continue;
        }
        vector<ll> cur(m + 1);
        cur[0] = 0;
        dp[i] = cur;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    unsigned int x = n, y = m;

    string res;

    while (x > 0 && y > 0) {
        if (str1[x - 1] == str2[y - 1]) {
            res += str1[x - 1];
            x -= 1;
            y -= 1;
        }else {
            if (dp[x - 1][y] > dp[x][y - 1]) {
                x -= 1;
            }else y -= 1;
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;

    return 0;
}