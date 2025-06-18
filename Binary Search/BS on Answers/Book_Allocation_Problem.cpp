int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
    int l = *max_element(arr.begin(),arr.end()) , r = 0;
    for(int i=0;i<n;i++)r+=arr[i];
    while(l<=r) {
        int mid = (l+r)/2;
        int student = 0,sum = 0;
        for( int i = 0 ; i < n ; i++) {
            if(sum+arr[i]>mid) {
                student++;
                sum=0;
            }
            sum+=arr[i];
        }
        if(sum>0)student++;
        if(student>m)l=mid+1;
        else r = mid-1;

    }
    return l;
    // Write your code here.
    
}