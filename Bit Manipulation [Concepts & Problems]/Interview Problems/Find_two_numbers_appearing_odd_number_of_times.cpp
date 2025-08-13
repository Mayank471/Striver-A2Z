class Solution {
  public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N) {
        long long int xorsum = 0;
        for (int i = 0; i < N; i++) {
            xorsum ^= Arr[i];
        }

        // Find a rightmost set bit in xorsum
        long long int diffBit = xorsum & -xorsum;

        long long int a = 0, b = 0;
        for (int i = 0; i < N; i++) {
            if (Arr[i] & diffBit)
                a ^= Arr[i];
            else
                b ^= Arr[i];
        }

        // Return in decreasing order
        if (a < b) swap(a, b);
        return {a, b};
    }
};
