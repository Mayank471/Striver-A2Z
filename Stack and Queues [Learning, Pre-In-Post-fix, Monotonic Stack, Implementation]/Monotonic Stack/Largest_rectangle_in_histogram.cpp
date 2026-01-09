class Solution {
public:
    vector<int> findPse(vector<int>& arr) {
        stack<int> s;
        vector<int> res(arr.size());
        for(int i=0; i<arr.size(); i++) {
            while(!s.empty() && arr[s.top()]>arr[i]) s.pop();
            res[i]=s.empty() ?-1 : s.top();
            s.push(i);
        }
        return res;
    }
    vector<int> findNse(vector<int>& arr) {
        stack<int> s;
        vector<int> res(arr.size());
        for(int i=arr.size()-1; i>=0; i--) {
            while(!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            res[i]=s.empty() ? arr.size() : s.top();
            s.push(i);
        }
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse = findPse(heights);
        vector<int> nse = findNse(heights);
        int largest = INT_MIN;
        for(int i=0; i<heights.size(); i++) {
            int PSE = pse[i];
            int NSE = nse[i];
            largest = max(heights[i]*(NSE-PSE-1), largest);
        }
        return largest;
    }
};