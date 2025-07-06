class Solution {
public:
    string frequencySort(string s) {
        string res = "";
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }
        vector<vector<char>> bucketdata(s.length() + 1);

        for (auto [ch, fq] : freq) {
            bucketdata[fq].push_back(ch);
        }
        for (int fq = s.length(); fq >= 1; fq--) {
            for (char ch : bucketdata[fq]) {
                res.append(fq, ch);
            }
        }

        return res;
    }
};
