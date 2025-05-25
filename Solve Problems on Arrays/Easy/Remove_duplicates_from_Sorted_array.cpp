class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1, temp;
        int i = 0, j = nums.size() - 1;
        if (nums.empty()) return 0;

        while (i < j) {
            if (nums[i] != nums[i + 1]) {
                i++;
                count++;
            } else {
                // rotate duplicates to the end
                temp = nums[i + 1];
                for (int k = i + 1; k < j; k++) {
                    nums[k] = nums[k + 1];
                }
                nums[j] = temp;
                j--;  // reduce the considered range
                // Do not increment `i` here so we re-check the new nums[i+1]
            }
        }
        return count;
    }
};
