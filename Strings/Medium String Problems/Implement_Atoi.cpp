class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++; 

        s = s.substr(i);
        if (s.empty()) return 0;

        int sign = 1;
        if (s[0] == '-') sign = -1;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

        long num = 0;
        while (i < s.size() && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (num > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            i++;
        }

        return int(sign * num);
    }
};
