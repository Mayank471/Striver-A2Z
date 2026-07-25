class Solution {
public:
    string minWindow(string &s, string &t) {
        int sLen = s.size(), tLen = t.size();
        int minLen = INT_MAX;
        string result = "";

        for (int i = 0; i < sLen; i++) {
            int j = 0;
            int k = i;

            // Forward pass: try to match entire t in s
            while (k < sLen && j < tLen) {
                if (s[k] == t[j]) {
                    j++;
                }
                k++;
            }

            if (j < tLen) continue; // not matched

            // Backward pass to minimize window
            int end = k; // exclusive
            j = tLen - 1;
            k--;

            while (j >= 0) {
                if (s[k] == t[j]) {
                    j--;
                }
                k--;
            }

            // k is at one before the valid start
            k++;
            if (end - k < minLen) {
                minLen = end - k;
                result = s.substr(k, minLen);
            }
        }

        return result;
    }
};
