class Solution {
  public:
    int countSetBits(int n) {
        if(n==0)return 0;
        int num = log2(n), count=0;
        count=pow(2,num-1)*num + n - pow(2,num) + 1 + countSetBits(n-pow(2,num));
        return count;
    }
};
