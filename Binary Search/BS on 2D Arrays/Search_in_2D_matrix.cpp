class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        while(i<matrix.size()&&matrix[i][0]<=target) {
            i++;
        }
        if(i==0)return false;
        else i--;
        int l = 0 , r = matrix[i].size()-1;
        while(l<=r) {
            int mid = (l+r)/2;
            if(matrix[i][mid]==target) {
                return true;
            }
            else if(matrix[i][mid]>target)r=mid-1;
            else l = mid+1;
        }
        return false;;
    }
};