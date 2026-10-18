class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<int>ans = {0,0};
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>qu;
        vector<vector<int>>visited(m,vector<int>(n,0));
        qu.push({0,0});
        visited[0][0] = 1;
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            int nr,nc;
            if(grid[r][c]=='L'){
                 nr = r;
                 nc = c-1;
            }
            else if(grid[r][c]=='R'){
                 nr = r;
                 nc = c+1;
            }
            else if(grid[r][c]=='U'){
                 nr = r-1;
                 nc = c;
            }
            else {
                 nr = r+1;
                 nc = c;
            }
            if(nr>=0 and nc>=0 and nr<m and nc<n and visited[nr][nc]==0){
            qu.push({nr,nc});
            visited[nr][nc] = 1;
            ans[0]=nr;
            ans[1]=nc;
            }
        }
    return ans;
    }
};