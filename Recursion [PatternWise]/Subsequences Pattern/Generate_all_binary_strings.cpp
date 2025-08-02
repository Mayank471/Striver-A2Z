class Solution {
  public:
    vector<string> generateBinaryStrings(int num) {
        vector<string> result;
        string current = "";
        generateHelper(num, current, result, false);
        return result;
    }

  private:
    void generateHelper(int n, string current, vector<string>& result, bool prevOne) {
        if (n == 0) {
            result.push_back(current);
            return;
        }

        // Always add '0'
        generateHelper(n - 1, current + "0", result, false);

        // Add '1' only if previous was not '1'
        if (!prevOne) {
            generateHelper(n - 1, current + "1", result, true);
        }
    }
};
