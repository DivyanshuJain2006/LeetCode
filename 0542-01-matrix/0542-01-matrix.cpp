class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>>qu;
        vector<vector<int>>ans(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    qu.push({i,j});
                
                }
            }
        }
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        while(not qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and ans[nr][nc]==-1){
                    ans[nr][nc] = 1+ans[r][c];
                    qu.push({nr,nc});
                }
            }
        }
        return ans;
    }
};