class Solution {
public:

    vector<int> findNse(vector<int>& arr) {
        vector<int> nse(arr.size());
        stack<int> s;
        for(int i=arr.size()-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()]>arr[i]){
                s.pop();
            }
            nse[i] = s.empty() ? arr.size() : s.top();
            s.push(i);
        }
        return nse;
    }
    vector<int> findNle(vector<int>& arr) {
        vector<int> nle(arr.size());
        stack<int> s;
        for(int i=arr.size()-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()]<arr[i]){
                s.pop();
            }
            nle[i] = s.empty() ? arr.size() : s.top();
            s.push(i);
        }
        return nle;
    }
    vector<int> findPse(vector<int>& arr) {
        vector<int> pse(arr.size());
        stack<int> s;
        for(int i=0; i<arr.size(); i++) {
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            pse[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return pse;
    }
    vector<int> findPle(vector<int>& arr) {
        vector<int> ple(arr.size());
        stack<int> s;
        for(int i=0; i<arr.size(); i++) {
            while(!s.empty() && arr[s.top()]<=arr[i]){
                s.pop();
            }
            ple[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return ple;
    }
    long long subArrayMin(vector<int>& arr) {
        long long sum=0;
        vector<int> nse = findNse(arr);
        vector<int> pse = findPse(arr);
        for(int i=0; i<arr.size(); i++){
            int left = i-pse[i];
            int right = nse[i]-i;
            sum+=1LL*left*right*arr[i];
        }
        return sum;
    }
    long long subArrayMax(vector<int>& arr) {
        long long sum=0;
        vector<int> nle = findNle(arr);
        vector<int> ple = findPle(arr);
        for(int i=0; i<arr.size(); i++){
            int left = i-ple[i];
            int right = nle[i]-i;
            sum+=left*right*1LL*arr[i];
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return subArrayMax(nums) - subArrayMin(nums);
    }

};