class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort( nums , 0 , nums.size()-1);
    }
    long long mergeSort(vector<int>& arr , int left, int right) {
        long long count = 0;
        int mid = (left+right)/2;
        if(left<right) {
            count+=mergeSort(arr , left , mid);
            count+=mergeSort(arr , mid+1 , right);
            count+=merge(arr , left , mid , right);
        }
        return count;
    }
    long long merge(vector<int>& arr ,int left ,int mid , int right ) {
        vector<int> temp;
        long long count=0;
        int j = mid+1;
        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2LL * arr[j]) {
                j++;
            }
        count += (j - (mid + 1));
        }
        int i = left;
        j=mid+1;
        while(i<=mid&&j<=right) {
            if(arr[i]<=arr[j]) {
                temp.push_back(arr[i]);
                i++;
            }
            else {
                temp.push_back(arr[j]);
                j++;
            }
        }
            while (i <= mid) temp.push_back(arr[i++]);
            while (j <= right) temp.push_back(arr[j++]);
            for( int i = left; i<=right;i++) {
                arr[i]=temp[i-left];
            }
            return count;

    }
};