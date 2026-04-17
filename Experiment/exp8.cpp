#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, 0);

    for(int i = 0; i < n; i++) {
        int mx = 0;
        for(int j = i; j >= 0 && i - j + 1 <= k; j--) {
            mx = max(mx, arr[j]);
            dp[i] = max(dp[i], (j > 0 ? dp[j-1] : 0) + mx * (i - j + 1));
        }
    }
    return dp[n-1];
}

int main() {
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;

    cout << maxSumAfterPartitioning(arr, k);

    return 0;
}