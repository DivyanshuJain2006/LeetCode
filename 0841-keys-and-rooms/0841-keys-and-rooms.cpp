class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int>visited;
        queue<int>qu;
        visited.insert(0);
        qu.push(0);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto neighbors : rooms[curr]){
                if(!visited.count(neighbors)){
                    visited.insert(neighbors);
                    qu.push(neighbors);
                }
            }
        }
        return visited.size()==n;
    }
};