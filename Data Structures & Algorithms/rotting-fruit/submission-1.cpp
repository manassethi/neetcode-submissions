class Solution {
   public:
    int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int fresh = 0;
        int time=0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) fresh++;
            }
        }

        while (!q.empty() && fresh > 0) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c=node.second;
                for(int ind=0;ind<4;ind++){
                    int nr=r+dir[ind][0];
                    int nc=c+dir[ind][1];
                    if(nr>=0 && nc>=0 && nr<rows && nc<cols && grid[nr][nc]==1){
                        q.push({nr,nc});
                        fresh--;
                        grid[nr][nc]=2;
                        
                    }
                }
            }
            time++;
        }

        return (fresh==0)?time:-1;
    }
};
