class Solution {
   public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({0, {i, j}});
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            auto node = q.front();
            int r = node.second.first;
            int c = node.second.second;
            int dist = node.first;
            q.pop();
            for (int ind = 0; ind < 4; ind++) {
                int nr = r + dir[ind][0];
                int nc = c + dir[ind][1];
                if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    int d = dist + 1;
                    ans = max(ans, d);
                    q.push({d, {nr, nc}});
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }

        return ans;
    }
};
