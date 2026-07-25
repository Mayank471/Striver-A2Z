class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> map;
        for (char c : t) {
            map[c]++;
        }

        int l = 0, r = 0;
        int count = 0; 
        int minLength = INT_MAX, sIndex = -1;

        while (r < s.size()) {
            map[s[r]]--;
            if (map[s[r]] >= 0) {
                count++;
            }
            while (count == t.size()) {
                if (r - l + 1 < minLength) {
                    minLength = r - l + 1;
                    sIndex = l;
                }
                map[s[l]]++;
                if (map[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return sIndex == -1 ? "" : s.substr(sIndex, minLength);
    }
};
