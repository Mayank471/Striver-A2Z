class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> res(nums.begin(), nums.end());
        int maxlen = 0;

        for (int num : res) {
            if (res.find(num - 1) == res.end()) { 
                int current = num;
                int len = 1;
                while (res.find(current + 1) != res.end()) {
                    current++;
                    len++;
                }
                maxlen = max(maxlen, len);
            }
        }

        return maxlen;
    }
};
