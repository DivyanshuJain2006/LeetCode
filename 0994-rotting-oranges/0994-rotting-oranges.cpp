class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minutes = 0;
        int fresh = 0;
        queue<pair<int,int>>qu;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2) qu.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }
        if(fresh==0) return 0;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==1){
                    qu.push({nr,nc});
                    fresh--;
                    grid[nr][nc]=2;
                }
            }
        }
        minutes++;
      }
        return (fresh==0) ? minutes-1 : -1;
    }
};