class Solution {
  public:
    double findSmallestMaxDist(vector<int> &nums, int k) {
        // Code here
        int n = nums.size();
        double l = 0 , r = nums[n-1]-nums[0],eps = 1e-6;
        while( r-l>eps) {
            double mid = (l+r)/2.0;
            int count=0;
            for(int i = 0 ; i < n-1 ; i++) {
                if(nums[i+1]-nums[i]>mid) {
                    count+=floor((nums[i+1]-nums[i])/mid);
                }
            }
            if(count>k)l=mid;
            else r = mid;
        }
        return r;
    }
};