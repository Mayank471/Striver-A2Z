class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int l = 0 , r = arr.size()-1,count=0;
        while(l<=r) {
            int mid = (l+r)/2;
            if(arr[mid]<target)l=mid+1;
            else r = mid-1;
        }
        count-=l;
        r=arr.size()-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(arr[mid]<=target)l=mid+1;
            else r=mid-1;
        }
        count+=r+1;
        return count;
    }
};