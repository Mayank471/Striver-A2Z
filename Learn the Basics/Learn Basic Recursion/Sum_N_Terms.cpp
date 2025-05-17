class Solution {
    public:
      int sum = 0;
      int sumOfSeries(int n) {
          // code here
          if(n==1)
          {
              sum+=1;
              return sum;
          }
          else {
              sum+=pow(n,3);
              sumOfSeries(n-1);
          }
      }
  };