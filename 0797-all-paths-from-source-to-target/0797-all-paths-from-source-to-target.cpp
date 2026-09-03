class Solution {
public:
    vector<vector<int>>result;
    unordered_set<int>visited;
    void dfs(int curr,int end,vector<int>&path,vector<vector<int>>& graph){
        if(curr==end){
            path.push_back(curr);
            result.push_back(path);
            path.pop_back();
            return;
        }
        visited.insert(curr);
        path.push_back(curr);
        for(auto neighbor : graph[curr]){
            dfs(neighbor,end,path,graph);
        }
        path.pop_back();
        visited.erase(curr);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>v;
        dfs(0,n-1,v,graph);
        return result;
    }
};