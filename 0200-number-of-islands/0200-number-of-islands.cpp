class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int cc = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>>qu;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    cc++;
                    grid[i][j]='0';
                    qu.push({i,j});
                    while(!qu.empty()){
                        auto [r,c] = qu.front();
                        qu.pop();
                        for(int k=0;k<4;k++){
                            int nr = r+dx[k];
                            int nc = c+dy[k];
                            if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]=='1'){
                                grid[nr][nc]='0';
                                qu.push({nr,nc});
                            }
                        }
                    }
                }
            }
        }
        return cc; 
    }
};