class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<pair<int,int>>visited;
        queue<pair<int,int>>qu;
        int moves = 0;
        if(grid[0][0]==0) qu.push({0,0});
        visited.insert({0,0});
        int dx[8] = {1,-1,0,0,-1,-1,1,1};
        int dy[8] = {0,0,1,-1,-1,1,-1,1};
        while(!qu.empty()){
           int size = qu.size();
           while(size--){
            auto [r,c] = qu.front();
            if(r==m-1 and c==n-1) return moves+1;
            qu.pop();
            for(int k=0;k<8;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==0 and !visited.count({nr,nc})) {
                    qu.push({nr,nc});
                    visited.insert({nr,nc});
                }
              }
           }
           moves++;
        }
        return -1;
    }
};