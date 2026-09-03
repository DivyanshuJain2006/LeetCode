class Solution {
public:
    void bfs(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    grid[i][j] = 0;
                    qu.push({i,j});
                }
                else grid[i][j] = -1;
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto[r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r +dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==-1){
                    qu.push({nr,nc});
                    grid[nr][nc] = 1+grid[r][c];
                }
            }
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bfs(grid);
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>ans) ans = grid[i][j];
            }
        }


    if(ans == 0)

        return -1;
        return ans;
    }
};