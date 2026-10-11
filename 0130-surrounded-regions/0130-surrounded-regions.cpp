class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>qu;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                qu.push({i,0});
                board[i][0] = 'a';
            }
            if(board[i][n-1]=='O'){
                qu.push({i,n-1});
                board[i][n-1] = 'a';
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                qu.push({0,j});
                board[0][j] = 'a';
            }
            if(board[m-1][j]=='O'){
                qu.push({m-1,j});
                board[m-1][j] = 'a';
            }
        }
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        while(!qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
            for(int k=0;k<4;k++){
                int nr = r+dx[k];
                int nc = c+dy[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and board[nr][nc]=='O'){
                    board[nr][nc] = 'a';
                    qu.push({nr,nc});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='a') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};