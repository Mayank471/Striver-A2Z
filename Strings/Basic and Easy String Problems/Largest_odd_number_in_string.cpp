class Solution {
public:
    string largestOddNumber(string num) {
        int l = num.size()-1;
        while(l>=0 && num[l]%2==0) {
            l--;
        }   
        return num.substr(0,l+1);
    }
};