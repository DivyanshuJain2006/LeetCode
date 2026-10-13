class Solution {
public:
    void bfs(vector<vector<int>>&grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        qu.push({i,j});
        grid[i][j]=1;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==0){
                    grid[nr][nc] = 1;
                    qu.push({nr,nc});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(grid[0][i]==0){
                grid[0][i]=2;
                q.push({0,i});
            }
            if(grid[m-1][i]==0){
                grid[m-1][i]=2;
                q.push({m-1,i});
            }
        }
        for(int j=0;j<m;j++){
            if(grid[j][0]==0){
                grid[j][0]=2;
                q.push({j,0});
            }
            if(grid[j][n-1]==0){
                grid[j][n-1]=2;
                q.push({j,n-1});
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==0){
                    grid[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }


        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
    return ans;
    }
};