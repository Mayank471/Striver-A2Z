class Solution {
    public:
      long long sumOfDivisors(long long n) {
          long long sum = 0;
          for (long long d = 1; d <= n; d++) {
              sum += d * (n / d);
          }
          return sum;
      }
  };
  