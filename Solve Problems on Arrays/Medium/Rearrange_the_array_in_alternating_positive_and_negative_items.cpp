class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        vector<int> res(n);
        for(int i = 0 ; i < nums.size();i++) {
            if(nums[i]>0)positive.push_back(nums[i]);
            else negative.push_back(nums[i]);
        }
        for(int i=0;i<n;i+=2){
            res[i]=positive[i/2];
        }
        for(int i=1;i<n;i+=2){
            res[i]=negative[i/2];
        }
        return res;
    }
};