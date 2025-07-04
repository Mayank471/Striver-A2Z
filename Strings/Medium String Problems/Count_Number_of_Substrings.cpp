class Solution {
  public:
  
    int count(string& s , int k) {
        // code here.
        vector<int> freq(26,0);
        int count = 0 , j = 0 , ans = 0;
        for(int i = 0 ; i < s.size() ; i++) {
            freq[s[i]-'a']++;
            
            if(freq[s[i]-'a']==1)count++;
            
            while(count>k) {
                freq[s[j]-'a']--;
                if(freq[s[j]-'a']==0) count--;
                j++;
            }
            ans+=i-j+1;
        }
        return ans;
    }
    int countSubstr(string& s, int k) {
        // code here.
        return count(s,k)-count(s,k-1);
    }
};