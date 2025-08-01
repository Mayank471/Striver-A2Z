class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> powerset;
        subset(nums , 0 , powerset , res);
        return res;
    }
private:
    void subset(vector<int>& nums, int index, vector<int>& powerset, vector<vector<int>>& res) {
        res.push_back(powerset);
        for(int i = index ; i < nums.size() ; i++) {
            if(i>index && nums[i]==nums[i-1])continue;
            powerset.push_back(nums[i]);
            subset(nums, i+1, powerset, res);
            powerset.pop_back();
        }
    }
};