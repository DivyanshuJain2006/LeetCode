class Solution {
public:
    vector<list<int>>graph;
    int v;
    void add_edge(int src,int dest,bool bi_dir=true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }
    void dfs(int src,unordered_set<int>&visited){
        visited.insert(src);
        for(auto neighbor : graph[src]){
            if(!visited.count(neighbor)){
                visited.insert(neighbor);
                dfs(neighbor,visited);
            }
        }
    }
    int connected_components(){
        unordered_set<int>visited;
        int cc = 0;
        for(int i=0;i<v;i++){
            if(!visited.count(i)){
                cc++;
                dfs(i,visited);
            }
        }
        return cc;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        v=n;
        graph.resize(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]) add_edge(i,j);
            }
        }
        int cc = connected_components();
        return n - cc;
    }
};