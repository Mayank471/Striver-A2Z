// User function Template for C++

class Solution {
  public:
    vector<int> spf; // spf[i] will store smallest prime factor of i

    void sieve() { 
        int MAX = 2e5 + 1;
        spf.resize(MAX);
        for (int i = 0; i < MAX; i++)
            spf[i] = i;

        for (int i = 2; i * i < MAX; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAX; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }

    vector<int> findPrimeFactors(int N) {
        vector<int> res;
        while (N != 1) {
            int primeFactor = spf[N];
            res.push_back(primeFactor);
            N /= primeFactor;
        }
        return res;
    }
};
