class Solution {
public:
    void dfs(vector<vector<int>>&image,int cr,int cc,int initialColor,int newColor){
        int m = image.size(),n=image[0].size();
        if(cr<0 or cc<0 or cr>=m or cc>=n) return;
        if(image[cr][cc]!=initialColor) return;
        image[cr][cc] = newColor;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        for(int k=0;k<4;k++){
            int nr = cr + dx[k];
            int nc = cc + dy[k];
            dfs(image,nr,nc,initialColor,newColor);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};