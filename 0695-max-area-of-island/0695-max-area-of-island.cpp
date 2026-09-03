class Solution {
public:
    int m;
    int n;
    int ans = 0;
    void bfs(int i,int j,vector<vector<int>>&grid){
        queue<pair<int,int>>qu;
        int area = 0;
        grid[i][j] = -1;
        qu.push({i,j});
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        area++;
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==1){
                    grid[nr][nc]=-1;
                    area++;
                    qu.push({nr,nc});
                }
            }
        }
        ans = max(area,ans);
    }
    void findArea(vector<vector<int>>&grid){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(i,j,grid);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        findArea(grid);
        return ans;
    }
};