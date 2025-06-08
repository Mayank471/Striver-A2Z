class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = nums[0];
        int curr_min = nums[0];
        int global_max = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            // If current number is negative, swap max and min
            if (nums[i] < 0) {
                swap(curr_max, curr_min);
            }

            curr_max = max(nums[i], curr_max * nums[i]);
            curr_min = min(nums[i], curr_min * nums[i]);

            global_max = max(global_max, curr_max);
        }

        return global_max;
    }
};
