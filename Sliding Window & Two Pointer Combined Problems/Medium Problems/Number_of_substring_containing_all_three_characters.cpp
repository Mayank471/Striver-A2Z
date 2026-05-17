class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> map(3, 0);
        int l = 0, r = 0, count = 0;

        while (r < s.size()) {
            map[s[r] - 'a']++;

            while (map[0] > 0 && map[1] > 0 && map[2] > 0) {
                count += n - r;
                map[s[l] - 'a']--;
                l++;
            }

            r++;
        }
        return count;
    }
};
