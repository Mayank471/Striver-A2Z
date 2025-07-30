class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())return res;
        unordered_map<char,string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        backtrack(digits, 0, "", res, mp);
        return res;
    }
    void backtrack(string& digits, int index, string temp, vector<string>& res, unordered_map<char,string>& mp){
        if(index == digits.length()){
            res.push_back(temp);
            return;
        }
        string letters = mp.at(digits[index]);
        for(char letter: letters) {
            backtrack(digits, index+1, temp+letter, res, mp);
        }
    }
};