class Solution {
public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size(), sum = 0;
        vector<int> res(2); 
        sort(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (i < n - 1 && arr[i + 1] == arr[i]) {
                res[0] = arr[i]; 
            }
        }

        long long expected_sum = n * (n + 1) / 2;
        res[1] = expected_sum - (sum - res[0]); 
        return res;
    }
};