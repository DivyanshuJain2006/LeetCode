class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cc = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                cc++;
                queue<pair<int,int>>qu;
                qu.push({i,j});
                grid[i][j] = '0';
                int dx[4] = {1,-1,0,0};
                int dy[4] = {0,0,1,-1};
                while(!qu.empty()){
                    auto [r,c] = qu.front();
                    qu.pop();
                    for(int k=0;k<4;k++){
                        int nr = r+dx[k];
                        int nc = c+dy[k];
                        if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]=='1'){
                            qu.push({nr,nc});
                            grid[nr][nc] = '0';
                        }
                    }
                }
            }
        }
        return cc;
    }
};