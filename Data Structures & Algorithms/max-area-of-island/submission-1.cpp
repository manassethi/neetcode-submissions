class Solution {
   public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    area = max(area, bfs(grid, i, j));
                }
            }
        }

        return area;
    }

    int bfs(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 0;
        int ans = 1;
        queue<pair<int, int>> q;
        q.push({r, c});
        while (!q.empty()) {
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            for (int ind = 0; ind < 4; ind++) {
                int nr = row + dir[ind][0];
                int nc = col + dir[ind][1];
                if (nr < grid.size() && nc < grid[0].size() && nr >= 0 && nc >= 0 &&
                    grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    ans++;
                    grid[nr][nc] = 0;
                }
            }

            
        }
        return ans;
    }
};
