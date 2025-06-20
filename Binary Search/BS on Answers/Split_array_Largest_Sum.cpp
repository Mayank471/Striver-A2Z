class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end()) , r = 0;
        for(int i=0;i<nums.size();i++)r+=nums[i];
        while(l<=r){
            int mid = (l+r)/2;
            int sum = 0,count=1;
            for(int i = 0 ; i < nums.size();i++)
            {
                if(sum+nums[i]>mid) {
                    count++;
                    sum=0;
                }
                sum+=nums[i];
            }
            if( count <= k) r= mid-1;
            else l = mid+1;
        }
        return l;
    }
};