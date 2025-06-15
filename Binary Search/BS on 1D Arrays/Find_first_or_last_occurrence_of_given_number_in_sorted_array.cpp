class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        if (l >= nums.size() || nums[l] != target) return res;
        res[0] = l;
        r = nums.size() - 1; 
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] <= target) l = mid + 1;
            else r = mid - 1;
        }

        res[1] = r;
        return res;
    }
};
