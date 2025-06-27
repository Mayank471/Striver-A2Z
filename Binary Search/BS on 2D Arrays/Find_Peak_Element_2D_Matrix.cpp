class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> res(2);
        int l = 0, r = mat[0].size() - 1; // Corrected upper bound
        while (l <= r) {
            int mid = (l + r) / 2;
            int maxVal = -1;
            for (int i = 0; i < mat.size(); i++) {
                if (mat[i][mid] > maxVal) {
                    maxVal = mat[i][mid];
                    res[0] = i;
                }
            }

            int leftVal = (mid - 1 >= 0) ? mat[res[0]][mid - 1] : -1;
            int rightVal = (mid + 1 < mat[0].size()) ? mat[res[0]][mid + 1] : -1;

            if (maxVal > leftVal && maxVal > rightVal) {
                res[1] = mid;
                return res;
            } else if (maxVal < leftVal) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
