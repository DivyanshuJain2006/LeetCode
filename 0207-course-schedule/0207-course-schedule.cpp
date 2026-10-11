class Solution {
public:
    vector<list<int>>graph;
    int v;
    void add_edge(int src,int dest,bool bi_dir = true){
        graph[src].push_back(dest);
        if(bi_dir) graph[dest].push_back(src);
    }
    int topo_BFS(){
        vector<int>indegree(v,0);
        for(int i=0;i<v;i++){
            for(auto neighbor : graph[i]){
                indegree[neighbor]++;
            }
        }
        queue<int>qu;
        for(int i=0;i<v;i++){
            if(indegree[i]==0) qu.push(i);
        }
        int cnt = 0;
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            cnt++;
            for(auto neighbor : graph[curr]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0) qu.push(neighbor);
            }
        }
        return cnt;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        v = numCourses;
        graph.resize(v);
        for(int i=0;i<prerequisites.size();i++){
            add_edge(prerequisites[i][1],prerequisites[i][0],false);
        }
        if(topo_BFS()==numCourses) return true;
        return false;
    }
};