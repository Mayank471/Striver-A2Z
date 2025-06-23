class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) return -1;

        int l = *min_element(bloomDay.begin(), bloomDay.end());
        int r = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            int flower = 0, bouquet = 0;

            for (int i = 0; i < bloomDay.size(); i++) {
                if (mid >= bloomDay[i]) {
                    flower++;
                    if (flower == k) {
                        bouquet++;
                        flower = 0;
                    }
                } else {
                    flower = 0;
                }
            }

            if (bouquet >= m) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return result;
    }
};
