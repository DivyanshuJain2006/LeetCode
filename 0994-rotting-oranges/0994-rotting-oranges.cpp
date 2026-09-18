class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int,int>>qu;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    qu.push({i,j});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        int minutes = 0;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                auto [r,c] = qu.front();
                qu.pop();
                for(int k=0;k<4;k++){
                    int nr = r+dx[k];
                    int nc = c+dy[k];
                    if(nr>=0 and nc >=0 and nr<m and nc<n and grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        qu.push({nr,nc});
                    }
                }
            }
            minutes++;
        }
        return (fresh==0)?minutes-1:-1;
    }
};