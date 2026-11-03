class Solution {
   public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int rows;
    int cols;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         rows = heights.size();
         cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for (int r = 0; r < rows; r++) {
            dfs(r, 0, pac, heights);
            dfs(r, cols - 1, atl, heights);
        }

        for (int c = 0; c < cols; c++) {
            dfs(0, c, pac, heights);
            dfs(rows - 1, c, atl, heights);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pac[i][j] == true && atl[i][j] == true) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for (int ind = 0; ind < 4; ind++) {
            int nr = r + dir[ind][0];
            int nc = c + dir[ind][1];
            if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && heights[nr][nc] >= heights[r][c] &&
                !ocean[nr][nc]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
};
