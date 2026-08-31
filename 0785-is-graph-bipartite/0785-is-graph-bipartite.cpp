class Solution {
public:
    bool bfs(int src,vector<int>&color,vector<vector<int>>& graph){
        queue<int>qu;
        qu.push(src);
        color[src] = 0;
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto neighbor : graph[curr]){
                if(color[neighbor]==-1){
                    color[neighbor] = !color[curr];
                    qu.push(neighbor);
                }
                else if(color[neighbor]==color[curr]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(bfs(i,color,graph)==false) return false;
            }
    
        }
        return true;
    }
};