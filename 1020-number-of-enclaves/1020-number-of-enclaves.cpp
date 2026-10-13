class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                grid[0][i]=0;
                qu.push({0,i});
            }
            if(grid[m-1][i]==1){
                grid[m-1][i]=0;
                qu.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                grid[i][0]=0;
                qu.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1]=0;
                qu.push({i,n-1});
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto[r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==1){
                    grid[nr][nc]=0;
                    qu.push({nr,nc});
                }
            }
        }
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) ans++;
            }
        
        }
        return ans;
    }

};