class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int mod = 1e9 + 7;

        // dp[i][j] = number of subsets from first i elements with sum j
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        // Base case: There's one subset (empty set) that sums to 0
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j) {
                    dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};
