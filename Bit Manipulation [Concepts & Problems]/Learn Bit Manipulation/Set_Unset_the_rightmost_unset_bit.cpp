class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int temp = n, count = 0;
        while(n%2!=0) {
            count++;
            n/=2;
        }
        return temp+pow(2,count);
    }
};