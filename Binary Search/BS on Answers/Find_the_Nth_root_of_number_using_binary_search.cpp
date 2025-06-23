class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        int l = 1 , r=m;
        while( l<=r) {
            int mid = (l+r)/2;
            long long power=1;
            for( int i = 0 ; i < n ;i++) {
                power*=mid;
                if(power>m) break;
            }
            if(power==m)return mid;
            if(power<m)l=mid+1;
            else r=mid-1;
        }
        return -1;
    }
};