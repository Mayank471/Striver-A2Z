class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == divisor) return 1;

        // Use long to safely handle INT_MIN
        long n = dividend;
        long d = divisor;

        bool isNegative = (n < 0) ^ (d < 0);  // XOR to determine the sign

        n = n < 0 ? -n : n;
        d = d < 0 ? -d : d;

        long ans = 0;

        while (n >= d) {
            int count = 0;
            while (n >= (d << (count + 1))) {
                count++;
            }
            ans += 1L << count;
            n -= d << count;
        }

        return isNegative ? -ans : ans;
    }
};
