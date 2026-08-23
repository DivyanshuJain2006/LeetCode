class Solution {
public:
    void bfs(vector<vector<int>>& heights,queue<pair<int,int>>&qu,vector<vector<bool>>&vis){
        int m = heights.size();
        int n = heights[0].size();
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        while(not qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r +dr[k];
                int nc = c+dc[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and heights[nr][nc]>=heights[r][c] and !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    qu.push({nr,nc});
                }
            } 
        }
    }




    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        queue<pair<int,int>>pacQ;
        queue<pair<int,int>>atlQ;
        // Pacific Ocean
        for(int i=0;i<m;i++){
            pacific[i][0] = 1;
            pacQ.push({i,0});
        }
        for(int j=0;j<n;j++){
            pacific[0][j] = 1;
            pacQ.push({0,j});
        }
        // Atlantic Ocean
        for(int i=0;i<m;i++){
            atlantic[i][n-1] = 1;
            atlQ.push({i,n-1});
        }
        for(int j=0;j<n;j++){
            atlantic[m-1][j] = 1;
            atlQ.push({m-1,j});
        }
        bfs(heights,pacQ,pacific);
        bfs(heights,atlQ,atlantic);
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pacific[i][j] and atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
