class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0; i<n; i++) board[i]=s;
        vector<int> leftRow(n,0);
        vector<int> upperDiagonal(2*n-1,0);
        vector<int> lowerDiagonal(2*n-1,0);
        solve(0, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
        return res;  
    }
private: 
    void solve(int col, vector<string>& board, vector<vector<string>>& res, vector<int>&leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
        if(col==n) {
            res.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+row-col]==0) {
                board[row][col]='Q';
                leftRow[row]=1;
                lowerDiagonal[row+col]=1;
                upperDiagonal[n-1+row-col]=1;
                solve(col+1, board, res, leftRow, upperDiagonal, lowerDiagonal, n);
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+row-col]=0;
                board[row][col]='.';
            }
        }
    }
};