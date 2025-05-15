class Solution {
    public:
      vector<long long> factorialNumbers(long long n) {
          // Write Your Code here
          vector<long long> res;
          long long fact = 1;
          int i=1;
          while(fact<=n)
          {
              res.push_back(fact);
              i++;
              fact*=i;
          }
          return res;
      }
  };