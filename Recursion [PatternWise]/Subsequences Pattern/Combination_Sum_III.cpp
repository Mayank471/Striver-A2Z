class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nums(9);
        for (int i = 0; i < nums.size(); i++) nums[i] = i + 1;  // nums = [1,2,...,9]
        
        vector<int> list;
        combination(nums, 0, 0, list, res, k, n);
        return res;
    }

private:
    void combination(vector<int>& nums, int index, int total, vector<int>& list, vector<vector<int>>& res, int k, int n) {
        if (total == n && list.size() == k) {
            res.push_back(list);
            return;
        }

        if (total > n || list.size() > k) return;

        for (int i = index; i < nums.size(); i++) {
            list.push_back(nums[i]);
            combination(nums, i + 1, total + nums[i], list, res, k, n);
            list.pop_back();
        }
    }
};
