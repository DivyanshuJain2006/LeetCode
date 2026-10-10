class Solution {
public:
    void bfs(vector<vector<int>>& image,int cr,int cc,int initialColor,int color){
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>qu;
        qu.push({cr,cc});
        image[cr][cc] = color;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and image[nr][nc]==initialColor){
                    image[nr][nc] = color;
                    qu.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        bfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};