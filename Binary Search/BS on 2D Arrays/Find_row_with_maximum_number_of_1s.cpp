// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int index = -1 , maxcount = -1;
        for(int i = 0 ; i < arr.size();i++) {
            int l = 0 , r = arr[i].size()-1 , count = 0;
            while(l<=r) {
                int mid = (l+r)/2;
                if(arr[i][mid]==1)r = mid -1;
                else l = mid+1;
            }
            count = arr[i].size()-l;
            if(count > maxcount) {
                maxcount = count;
                index = i;
            }
        }
        return index;
    }
};