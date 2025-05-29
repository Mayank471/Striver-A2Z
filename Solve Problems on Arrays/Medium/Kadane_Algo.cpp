class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum2=nums[0] , sum1=nums[0];
        for(int i = 1;i<nums.size();i++) {
            sum1 = max(sum1+nums[i] , nums[i]);
            sum2 = max(sum2,sum1);
        }
        return sum2;
    }
};