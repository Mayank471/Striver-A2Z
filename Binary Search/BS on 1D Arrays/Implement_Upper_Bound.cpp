class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> res(2,-1);
        int max = INT_MIN, min = INT_MAX;
        for( int i = 0 ; i < arr.size();i++) {
            if(arr[i]>=x) {
                if ( arr[i]< min) {
                    min = arr[i];
                    res[1] = arr[i];
                }
            }
            if(arr[i]<=x) {
                if(arr[i]>max) {
                    max = arr[i];
                    res[0] = arr[i];
                }
            }
        }
        return res;
    }
};