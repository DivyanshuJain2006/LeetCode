class Solution {
public:
    vector<vector<int>>graph;
    int v;
    void add_edge(int src,int dest,bool bi_dir=true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }
    int bfs(){
        vector<int>indegree(v+1,0);
        vector<int>outdegree(v+1,0);
        for(int i=1;i<=v;i++){
            outdegree[i] = graph[i].size();
        }
        for(int i=1;i<=v;i++){
            for(auto neighbor : graph[i]){
                indegree[neighbor]++;
            }
        }
        for(int i=1;i<=v;i++){
            if(indegree[i]==v-1 and outdegree[i]==0) return i;
        }
        return -1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
        v = n;
        graph.resize(v+1);
        for(int i=0;i<trust.size();i++){
            add_edge(trust[i][0],trust[i][1],false);
        }
        return bfs();
    }
};