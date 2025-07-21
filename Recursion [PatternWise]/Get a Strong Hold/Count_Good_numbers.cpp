class Solution {
public:
    int countGoodNumbers(long long n) {
        const int mod = 1e9+7;
        long long odd = n/2, even = (n+1)/2;
        return (power(5, even, mod) * power(4, odd, mod)) % mod;
    }

private:
    long long power(long long x, long long y, int mod) {
        if(y == 0) return 1;
        
        long long half = power(x, y/2, mod);
        half = (half * half) % mod;
        
        return (y % 2 == 0) ? half : (half * x) % mod;
    }
};
