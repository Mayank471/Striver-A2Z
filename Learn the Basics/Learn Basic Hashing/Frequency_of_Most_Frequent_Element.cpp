class Solution {
    public:
        int maxFrequency(vector<int>& nums, int k) {
            sort(nums.begin(),nums.end());
            long long l=0,r=0 , total = 0 , maxFreq=0, n = nums.size();
            for (r; r<n;r++)
            {
                total+=nums[r];
                while(l<r && nums[r]*(r-l+1) > k + total )
                {
                    total-=nums[l];
                    l++;
                }
                maxFreq = max(maxFreq , r-l+1);
            }
            return maxFreq;
        }
    };