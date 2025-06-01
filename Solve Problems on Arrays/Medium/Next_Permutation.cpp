class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int possible = 1;
        int i;
        for(i = n - 1 ; i > 0; i--) {
            if(nums[i - 1] < nums[i]) {
                possible = 0;
                int j = n - 1;
                while(nums[j] <= nums[i - 1]) j--;
                swap(nums[i - 1], nums[j]);
                int l = i, r = n - 1;
                while(l < r) {
                    swap(nums[l], nums[r]);
                    l++;
                    r--;
                }
                break;
            }
        }
        if(possible) {
            for(int i = 0; i < n / 2; i++) {
                swap(nums[i], nums[n - i - 1]);
            }
        }
    }
};
