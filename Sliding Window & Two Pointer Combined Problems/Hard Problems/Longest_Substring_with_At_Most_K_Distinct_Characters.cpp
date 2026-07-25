class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string &s, int k) {
        if (k == 0) return 0;

        int l = 0, r = 0, maxLen = 0;
        unordered_map<char, int> map;

        while (r < s.size()) {
            map[s[r]]++;

            while (map.size() > k) {
                map[s[l]]--;
                if (map[s[l]] == 0) {
                    map.erase(s[l]);
                }
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};
