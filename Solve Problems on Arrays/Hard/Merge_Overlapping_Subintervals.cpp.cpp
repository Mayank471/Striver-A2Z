class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int l = 0, r = 1;
        while (l < n) {
            int start = intervals[l][0];
            int end = intervals[l][1];
        
            while (r < n && end >= intervals[r][0]) {
                end = max(end, intervals[r][1]);
                r++;
            }

            res.push_back({start, end});
            l = r;
            r = l + 1;
        }

        return res;
    }
};
