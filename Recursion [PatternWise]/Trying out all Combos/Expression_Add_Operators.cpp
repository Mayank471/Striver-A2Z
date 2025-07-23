class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string path;
        solve(num, target, 0, 0, 0, path, res);
        return res;
    }

private:
    void solve(string& num, int target, int pos, long sum, long prev, string path, vector<string>& res) {
        if (pos == num.size()) {
            if (sum == target) {
                res.push_back(path);
            }
            return;
        }

        for (int i = 1; i <= num.size() - pos; ++i) {
            string currStr = num.substr(pos, i);
            if (currStr.size() > 1 && currStr[0] == '0') break;

            long curr = stol(currStr);

            if (pos == 0) {
                solve(num, target, i, curr, curr, currStr, res);
            } else {
                solve(num, target, pos + i, sum + curr, curr, path + "+" + currStr, res);
                solve(num, target, pos + i, sum - curr, -curr, path + "-" + currStr, res);
                solve(num, target, pos + i, sum - prev + prev * curr, prev * curr, path + "*" + currStr, res);
            }
        }
    }
};
