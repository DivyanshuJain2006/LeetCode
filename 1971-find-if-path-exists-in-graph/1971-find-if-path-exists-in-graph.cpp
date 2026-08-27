class Solution {
public:
    vector<list<int>>graph;
    unordered_set<int>visited;
    void add_edge(int src,int dest,bool bi_dir = true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }
    bool dfs(int src,int destination){
        if(src == destination) return true;
        visited.insert(src);
        for(auto neighbor : graph[src]){
            if(!visited.count(neighbor)){
            if(dfs(neighbor,destination)) return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            add_edge(edges[i][0],edges[i][1]);
        }
        return dfs(source,destination);
    }
};