class Solution {
  public:
    void print_divisors(int n) {
        vector<int> res;
        for(int i=1; i<=sqrt(n); i++) {
            if(n%i==0){
                cout<<i<<" ";
                if(i!=(n/i))
                res.push_back(n/i);
            }
        }
        for(int i=res.size()-1; i>=0; i--) 
            cout<<res[i]<<" ";
        return;
    }
};