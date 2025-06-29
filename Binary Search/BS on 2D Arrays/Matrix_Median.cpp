// User function template for C++

class Solution {
  public:
    int upperbound(vector<int>& mat , int x) {
        int l = 0 , r = mat.size();
        while(l<r) {
            int mid = (l+r)/2;
            if(mat[mid]<=x)l=mid+1;
            else r = mid;
        }
        return l;
    }
  
    int median(vector<vector<int>> &mat) {
        // code here
        int n = mat.size() , m = mat[0].size();
        int l = INT_MAX;
        for (const auto &row : mat) {
            l = min(l, *min_element(row.begin(), row.end()));
        }
        int r = INT_MIN;
        for (const auto &row : mat) {
            r = max(r, *max_element(row.begin(), row.end()));
        }
        while(l<=r) {
            int mid = (l+r)/2;
            int count = 0;
            for( int i = 0;i<n;i++) {
                count+=upperbound(mat[i] , mid);
            }
            if(count<(n*m+1)/2) l = mid+1;
            else r = mid - 1;
        }
        return l;
    }
};