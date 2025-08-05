class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //  code here
        if(n>=0)
        return (n>>k)&1 == 1;
        
    }
};