class Solution {
public:
    int maxArea(vector<vector<int>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1;
        grid[i][j]=0;
        queue<pair<int,int>>qu;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        qu.push({i,j});
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc >=0 and nr<m and nc<n and grid[nr][nc]==1){
                    ans++;
                    grid[nr][nc]=0;
                    qu.push({nr,nc});
                }
            }
        }
        return ans ;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int finalAns = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    finalAns = max(maxArea(grid,i,j),finalAns);
                }
            }
        }
        return finalAns;
    }
};