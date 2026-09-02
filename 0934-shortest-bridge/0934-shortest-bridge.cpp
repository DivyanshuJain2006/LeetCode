class Solution {
public:
    queue<pair<int,int>>qu;
    int m;
    int n;
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    void marksIsland(vector<vector<int>>&grid,int r,int c){
        queue<pair<int,int>>q;
        qu.push({r,c});
        q.push({r,c});
        grid[r][c] = 2;
        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==1){
                    qu.push({nr,nc});
                    q.push({nr,nc});
                    grid[nr][nc] = 2;
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        bool found = false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    found =true;
                    marksIsland(grid,i,j);
                    break;
                }
            }
            if(found) break;
        }
        int moves = 0;
        while(!qu.empty()){
            int size = qu.size();
            
            while(size--){
                auto[r,c] = qu.front();
                qu.pop();
                for(int k=0;k<4;k++){
                    int nr = r+dx[k];
                    int nc= c+dy[k];
                    if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]!=2){
                        if(grid[nr][nc]==1) return moves;
                        grid[nr][nc] = 2;
                        qu.push({nr,nc});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};