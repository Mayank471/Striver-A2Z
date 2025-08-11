class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> res;
        for( int i=2; i<=sqrt(n); i++) {
            if(n%i == 0){
                res.push_back(i);
                while(n%i==0)n/=i;
            }
        }
        if(n!=1)res.push_back(n);
        return res;
    }
};