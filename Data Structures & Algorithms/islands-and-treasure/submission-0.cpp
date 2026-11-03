class Solution {
   public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            int r = node.first;
            int c = node.second;
            q.pop();
            for (int ind = 0; ind < 4; ind++) {
                int nr = r + dir[ind][0];
                int nc = c + dir[ind][1];
                if (nc < cols && nr < rows && nr >= 0 && nc >= 0 && grid[nr][nc] == INT_MAX){
                        grid[nr][nc]=grid[r][c]+1;
                        q.push({nr,nc});
                    }


            }
        }
    }
};
