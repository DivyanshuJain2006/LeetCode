class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        deque<pair<int,int>>dq;
        dq.push_back({0,0});
        dist[0][0]=0;
        while(!dq.empty()){
            auto [r,c] = dq.front();
            dq.pop_front();
            int dir = grid[r][c];
            for(int i=0;i<4;i++){
                int nr = r+dx[i];
                int nc = c+dy[i];
                int edgewt = 1;
                if(i+1==dir) edgewt=0;
                if(nr<n and nc<m and nr>=0 and nc>=0){
                    if(dist[nr][nc]>dist[r][c]+edgewt){
                        dist[nr][nc]=dist[r][c]+edgewt;
                        if(edgewt==1){
                            dq.push_back({nr,nc});
                        }
                        else{
                            dq.push_front({nr,nc});
                        }
                    }
                
                }
            }
        }
        return dist[n-1][m-1];
    }
};