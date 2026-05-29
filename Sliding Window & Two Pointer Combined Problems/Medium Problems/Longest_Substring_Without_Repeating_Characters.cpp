class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, maxLen = 0;
        vector<int> hash(255, 0);

        while (j < s.size()) {
            if (hash[s[j]] == 0) {
                hash[s[j]]++;
                maxLen = max(maxLen, j - i + 1);
                j++;
            } else {
                hash[s[i]]--;
                i++;
            }
        }
        return maxLen;
    }
};
