class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int , int> result;
        for(int i = 0;i<nums.size();i++) {
            result[nums[i]]++;
        }
        int mincount = INT_MAX , num = 0;
        for(auto &numb : result) {
            if(numb.second<mincount) {
                mincount = numb.second;
                num = numb.first;
            }
        }
        return num; 
    }
};