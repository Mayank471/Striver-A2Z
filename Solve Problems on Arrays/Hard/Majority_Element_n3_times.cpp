class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size()==1) return nums;
        if (nums.size()==2) {
            vector<int>res;
            if(nums[0]==nums[1]) {
                res.push_back(nums[0]);
                return res;
            } 
            else return nums;
        }
        vector<int> res;
        int count1=0,count2=0,candidate1,candidate2;
        for(int i = 0 ; i < nums.size();i++) {
            if(nums[i]==candidate1)count1++;
            else if(nums[i]==candidate2)count2++;
            else if(count1==0) {
                candidate1=nums[i];
                count1++;
            }
            else if(count2==0) {
                candidate2=nums[i];
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i = 0 ; i < nums.size(); i++) {
            if(nums[i]==candidate1)count1++;
            else if(nums[i]==candidate2)count2++;
        }
        if(count1>nums.size()/3)res.push_back(candidate1);
        if(count2>nums.size()/3 && candidate2 != candidate1)res.push_back(candidate2);
        return res;
    }
};