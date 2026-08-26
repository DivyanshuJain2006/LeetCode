class Solution {
public:
    int v;
    vector<list<int>>graph;
    void add_edge(int src,int dest){
        graph[src].push_back(dest);
    }
    bool topo_bfs(){
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
            int curr = qu.front();
            cnt++;
            qu.pop();
            for(auto neighbor:graph[curr]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    qu.push(neighbor);
                }
            }
        }
        if(cnt!=v) return false;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        v = numCourses;
        graph.resize(numCourses);
        for(int i=0;i<prerequisites.size();i++){
            add_edge(prerequisites[i][1],prerequisites[i][0]);
        }
        return topo_bfs();
    }
};