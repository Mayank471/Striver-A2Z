class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mid=0,n=piles.size(), l = 1 , r = piles[0] , k = INT_MAX;
        for( int i = 1 ; i < n ; i++) if(r<piles[i]) r=piles[i];
        while ( l <= r ) {
             mid = (l+r)/2;
            long long sum=0;
            for ( int i = 0 ; i < n ; i++) {
                sum+=(piles[i]+mid-1)/mid;
            }
            if(sum>h)l=mid+1;
            else  {
                k=min(k,mid);
                r = mid - 1;
            }
        }
        return k;
    }
};