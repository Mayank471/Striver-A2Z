class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l = 0, r = arr.size();
        while(l<r) {
            int mid = (l+r)/2;
            int count = arr[mid] - (mid+1);
            if(count< k) {
                l=mid+1;
            }
            else r = mid;
        }
        return l+k;
    }
};