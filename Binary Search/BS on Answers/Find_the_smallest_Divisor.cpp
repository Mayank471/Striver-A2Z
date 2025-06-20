class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int mid=0,l = 1; 
        int r = *max_element(nums.begin(), nums.end());
        while( l <=r ) {
            mid = (l+r)/2;
            int sum = 0;
            for(int i = 0 ; i < nums.size() ; i++) {
                sum+=(nums[i]+mid-1)/mid;
            }
            if( sum > threshold) l = mid+1;
            else r= mid-1;
        }
        return l;
    }
};