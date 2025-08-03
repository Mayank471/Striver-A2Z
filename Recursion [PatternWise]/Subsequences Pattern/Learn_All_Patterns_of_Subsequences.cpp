// Helper function to count distinct subsequences
int countDistinctSubsequences(string &s) {
    int mod = 1e9 + 7;
    vector<int> last(256, -1);
    vector<int> dp(s.length() + 1);
    
    dp[0] = 1;
    
    for (int i = 1; i <= s.length(); ++i) {
        dp[i] = (2 * dp[i - 1]) % mod;

        if (last[s[i - 1]] != -1) {
            dp[i] = (dp[i] - dp[last[s[i - 1]]] + mod) % mod;
        }

        last[s[i - 1]] = i - 1;
    }

    return dp[s.length()];
}

class Solution {
  public:
    string betterString(string &s1, string &s2) {
        int c1 = countDistinctSubsequences(s1);
        int c2 = countDistinctSubsequences(s2);
        
        if (c1 >= c2) return s1;
        else return s2;
    }
};
