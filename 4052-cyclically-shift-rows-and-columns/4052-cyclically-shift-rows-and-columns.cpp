class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>>ans(n,vector<int>(n));
        for(int i=0;i<grid.size();i++){
            int k = rowShift[i];
            for(int j=0;j<grid[0].size();j++){
                ans[i][(j-k+n)%n] = grid[i][j];
            }
        }
        vector<vector<int>>fans(n,vector<int>(n));
        for(int j=0;j<grid[0].size();j++){
            int k = colShift[j];
            for(int i=0;i<grid.size();i++){
                grid[(i - k + n) % n][j] = ans[i][j];
            }
        }
        return grid;
    }
};