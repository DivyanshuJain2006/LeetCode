class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    qu.push({i,j});
                   // grid[i][j] = 0;
                }
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r + dx[k];
                int nc = c + dy[k];
                if(nr<0 || nc < 0 || nr >=m || nc>=n || grid[nr][nc]==0) ans++;
            }
        }
        return ans;
    }
};