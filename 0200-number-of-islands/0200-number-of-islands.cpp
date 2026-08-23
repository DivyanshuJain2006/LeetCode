class Solution {
public:
    set<pair<int,int>>visited;
    void dfs(vector<vector<char>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]=='0') return;
        if(visited.count({i,j})) return;
        visited.insert({i,j});
        dfs(grid,i+1,j),dfs(grid,i-1,j),dfs(grid,i,j+1),dfs(grid,i,j-1);
    }
    int connected(vector<vector<char>>&grid){
        int cc = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='0') continue;
                if(not visited.count({i,j})){
                    cc++;
                    dfs(grid,i,j);
                }
            }
        }
        return cc;
    }  
    int numIslands(vector<vector<char>>& grid) {
        return connected(grid);
    }
};