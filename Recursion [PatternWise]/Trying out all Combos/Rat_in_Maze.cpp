class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> res;
        int n = maze.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (maze[0][0] == 1)
            dfs(0, 0, n, maze, visited, res, "");
        sort(res.begin(), res.end()); // for lexicographical order
        return res;
    }

  private:
    void dfs(int i, int j, int n, vector<vector<int>>& maze,
             vector<vector<int>>& visited, vector<string>& res, string temp) {
        if (i == n - 1 && j == n - 1) {
            res.push_back(temp);
            return;
        }

        visited[i][j] = 1;

        // Down
        if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1)
            dfs(i + 1, j, n, maze, visited, res, temp + 'D');

        // Up
        if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1)
            dfs(i - 1, j, n, maze, visited, res, temp + 'U');

        // Right
        if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1)
            dfs(i, j + 1, n, maze, visited, res, temp + 'R');

        // Left
        if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1)
            dfs(i, j - 1, n, maze, visited, res, temp + 'L');

        visited[i][j] = 0;
    }
};
