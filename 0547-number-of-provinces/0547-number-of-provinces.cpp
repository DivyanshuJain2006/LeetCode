class Solution {
public:
    vector<list<int>>graph;
    int v;
    void add_edge(int src,int dest,bool bi_dir = true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }
    void dfs(int src,unordered_set<int>&visited){
        visited.insert(src);
        for(auto neighbor : graph[src]){
            if(!visited.count(neighbor)) dfs(neighbor,visited);
        }
    }
    int connected_component(){
        unordered_set<int>visited;
        int cc = 0;
        for(int i=0;i<v;i++){
            if(not visited.count(i)){
                cc++;
                dfs(i,visited);
            }
        }
        return cc;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        v=n;
        graph.resize(n);
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1) add_edge(i,j);
            }
        }
        return connected_component();
    }
};
