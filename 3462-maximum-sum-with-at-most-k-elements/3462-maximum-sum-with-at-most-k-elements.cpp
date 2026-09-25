class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        long long ans = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        
        for(int i=0;i<grid.size();i++){
            priority_queue<int,vector<int>,greater<int>>dq;
            int limit = limits[i];
            for(int j=0;j<grid[0].size();j++){
                dq.push(grid[i][j]);
                if(dq.size()>limit) dq.pop();  
            }
             while(dq.size()>0){
                    pq.push(dq.top());
                    dq.pop();
                }
        }
        while(pq.size()>k) pq.pop();
        while(pq.size()>0){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};