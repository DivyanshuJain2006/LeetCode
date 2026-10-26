class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0){
                    long long sum = 0;
                    sum+=grid[i][j];
                    grid[i][j] = 0;
                    queue<pair<int,int>>qu;
                    qu.push({i,j});
                    int dx[4] = {1,-1,0,0};
                    int dy[4] = {0,0,1,-1};
                    while(!qu.empty()){
                        auto [r,c] = qu.front();
                        qu.pop();
                        for(int d=0;d<4;d++){
                            int nr = r+dx[d];
                            int nc = c+dy[d];
                            if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]>0){
                                sum+=grid[nr][nc];
                                grid[nr][nc] = 0;
                                qu.push({nr,nc});
                            }
                        }
                    }
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};