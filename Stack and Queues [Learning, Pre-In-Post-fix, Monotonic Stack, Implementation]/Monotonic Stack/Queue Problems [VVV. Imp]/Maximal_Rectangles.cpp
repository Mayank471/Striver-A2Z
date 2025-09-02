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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> hisMatrix(n,vector<int>(m,0));
        for(int i=0; i<m; i++) {
            int sum=0;
            for(int j=0; j<n; j++) {
                if(matrix[j][i]=='1') sum++;
                if(matrix[j][i]=='0') sum=0;
                hisMatrix[j][i]=sum;
            }   
        }
        int maxArea=0;
        for(int i=0; i<n; i++) {
            maxArea = max(maxArea, largestRectangleArea(hisMatrix[i]));
        }
        return maxArea;
    }
};