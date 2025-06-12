class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        if(x<arr[0]) return -1;
        int n = arr.size(), l = 0;
        while( l<n && arr[l]<=x){
            l++;
        }
        return l-1;
    }
};