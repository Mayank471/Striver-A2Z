class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        vector<int> res;
        for(int i = min(a,b) ; i >0 ; i--)
        {
            if(a%i==0 && b%i==0) {
            res.push_back(a*b/i);
            res.push_back(i);
            break;
            }
        }
        return res;
    }
};