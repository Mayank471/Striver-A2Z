class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;
        vector<int> mp(26, 0);
        
        while (r < s.size()) {
            mp[s[r] - 'A']++;
            maxFreq = max(maxFreq, mp[s[r] - 'A']);

            if (r - l + 1 - maxFreq > k) {
                mp[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
