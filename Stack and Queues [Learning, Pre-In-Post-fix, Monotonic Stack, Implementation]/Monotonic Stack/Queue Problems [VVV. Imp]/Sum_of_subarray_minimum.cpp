class Solution {
public:
    vector<int> findNse(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> s;
        for(int i=arr.size()-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            nse[i] = s.empty() ? arr.size() : s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> findPse(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> s;
        for(int i=0; i<arr.size(); i++) {
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int sum=0, mod = 1e9+7;
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        for(int i=0; i<arr.size(); i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            sum = (sum+(left*right*1ll*arr[i])%mod)%mod;
        }
        return sum;
    }
};