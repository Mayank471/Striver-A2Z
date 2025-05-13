class Solution {
    public:
        bool isPalindrome(int x) {
            bool palindrome = true;
            if(x<0) return false;
            vector<int> arr;
            while(x!=0)
            {
                int r = x%10;
                arr.push_back(r);
                x/=10;
            }
            for(int i = 0;i<arr.size()/2;i++)
            {
                if(arr[i]!=arr[arr.size()-i-1]) palindrome = false;
                else continue;
            }
            return palindrome;
        }
    };