class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int top=0, down=mat.size()-1;
        while(top<down) {
            if(mat[top][down] == 1)top++;
            else down--;
        }
        for(int i=0; i<mat.size(); i++) {
            if(i!=top){
                if(mat[i][top]==0 || mat[top][i]==1)return-1;
            }
        }
        return top;
    }
};