int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    int l = *max_element(boards.begin(),boards.end()) , r = 0;
    for(int i = 0 ; i < n ; i++) r+=boards[i];
    while(l<=r) {
        int mid = ( l + r)/2;
        int sum = 0 , count = 0;
        for ( int i = 0 ; i < n ; i++) {
            if(sum+boards[i]>mid){
                count++;
                sum=0;
            }
            sum+=boards[i];
        }
        if(sum>0)count++;
        if(count > k) l=mid+1;
        else r = mid-1;
    }
    return l;
}