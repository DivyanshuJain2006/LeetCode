class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void bfs(vector<vector<int>>&grid,int i,int j,queue<pair<int,int>>&quu){
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        qu.push({i,j});
        quu.push({i,j});
        grid[i][j] = 2;
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==1){
                    grid[nr][nc] = 2;
                    qu.push({nr,nc});
                    quu.push({nr,nc});
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>quu;
        bool found = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    bfs(grid,i,j,quu);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int moves = 0;
        while(!quu.empty()){
            int size = quu.size();
            while(size--){
                auto [r,c] = quu.front();
                quu.pop();
                for(int k=0;k<4;k++){
                    int nr = r+dx[k];
                    int nc = c+dy[k];
                    if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]!=2){
                        if(grid[nr][nc]==1) return moves;
                        grid[nr][nc] = 2;
                        quu.push({nr,nc});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};