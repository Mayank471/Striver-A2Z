class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool found = false;
        int n = nums.size() , l = 0 , r = nums.size()-1;
        while( l<=r) {
            int mid = (l+r)/2;
            if(nums[mid]==target) {found=true;return found;}
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            }
            else if( nums[mid]>=nums[l]) {
                if(nums[mid]>target&&target>=nums[l])r=mid-1;
                else l = mid+1;
            }
            else {
                if(nums[mid]<target&&target<=nums[r])l=mid+1;
                else r = mid-1;
            }
        }
        return found;
    }
};