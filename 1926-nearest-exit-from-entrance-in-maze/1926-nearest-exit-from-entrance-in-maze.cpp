class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int,int>>qu;
        qu.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = 0;
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                auto [r,c] = qu.front();
                qu.pop();
                if ((r != entrance[0] || c != entrance[1]) && (r == 0 || c == 0 || r == m-1 || c == n-1)) return ans;
                for(int k=0;k<4;k++){
                    int nr = r+dx[k];
                    int nc = c+dy[k];
                    if(nr>=0 and nc>=0 and nr<m and nc<n and maze[nr][nc]=='.'){
                        qu.push({nr,nc});
                        maze[nr][nc] = '+';
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};