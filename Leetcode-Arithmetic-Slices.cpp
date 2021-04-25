#include <bits/stdc++.h>
using namespace std;



//#define ll long long



int numberOfArithmeticSlices(vector<int>& nums) {
    // at least 3...
    if (nums.size() < 3) return 0;

    int res = 0;
    int dp = 0;
    unsigned int n = nums.size();
    for (int i = 2; i < n; i++) {
        if (nums[i] + nums[i - 2] != 2 * nums[i - 1]) {
            dp = 0;
            continue;
        }
        res += (1 + dp++);
    }

    return res;
}




int main() {
    ios::sync_with_stdio(false);


    //test
    vector<int> vec = {1, 2, 3, 4};
    if (numberOfArithmeticSlices(vec) == 3) cout << "Correct!" << endl;
    else cout << "Wrong!" << endl;



    return 0;
}