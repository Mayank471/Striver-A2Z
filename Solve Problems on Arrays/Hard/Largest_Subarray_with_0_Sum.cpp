class Solution {
  public:
    int maxLen(vector<int>& arr) {
        // code here
        int  maxlen=0 , n = arr.size() , sum=0;
        unordered_map<int , int> res;
        for( int i = 0 ; i < n ; i++) {
            sum+=arr[i];
            if(sum==0) {
                maxlen = i+1;
            }
            if(res.find(sum)!=res.end()) {
                maxlen = max(maxlen , i-res[sum]);
            }
            else {
                res[sum]=i;
            }
        }
        return maxlen;
    }
};
