class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>>qu;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                board[i][0] = 'a';
                qu.push({i,0});
            }
            if(board[i][n-1]=='O'){
                board[i][n-1] = 'a';
                qu.push({i,n-1});  
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                board[0][j] = 'a';
                qu.push({0,j});
            }
             if(board[m-1][j]=='O'){
                board[m-1][j] = 'a';
                qu.push({m-1,j});
            }
        }
       
        int dr[] = {1,-1,0,0};
        int dc[] = {0,0,1,-1};
        while(not qu.empty()){
            auto [r,c] = qu.front();
            qu.pop();
           
            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];
                if(nr>=0 and nc>=0 and nr<m and nc<n and board[nr][nc]=='O'){
                    qu.push({nr,nc});
                    board[nr][nc] = 'a';
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='a') board[i][j] = 'O';
                else if(board[i][j]=='O') board[i][j] ='X';
            }
        }
    }
};