class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        combination(candidates, target, 0, comb, 0, res);
        return res;
    }

private:
    void combination(vector<int>& candidates, int target, int index, vector<int>& comb, int total, vector<vector<int>>& res) {
        if (total == target) {
            res.push_back(comb);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (total + candidates[i] > target) break;
            comb.push_back(candidates[i]);
            combination(candidates, target,i+1,comb, total + candidates[i], res);  
            comb.pop_back(); 
        }
    }
};
