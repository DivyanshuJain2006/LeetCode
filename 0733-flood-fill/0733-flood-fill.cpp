class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;
        int initialColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>qu;
        //set<pair<int,int>>visited;
        qu.push({sr,sc});
        //visited.insert({sr,sc});
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        image[sr][sc] = color; 
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 and nc>=0 and nr<m and nc<n and image[nr][nc]==initialColor){
                    image[nr][nc] = color;
                    qu.push({nr,nc});
                }
            }
        }
        return image;
    }
};