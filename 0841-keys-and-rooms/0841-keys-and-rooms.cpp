class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m = rooms.size();
        unordered_set<int>visited;
        queue<int>qu;
        qu.push(0);
        visited.insert(0);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto neighbor:rooms[curr]){
                if(!visited.count(neighbor)){
                    visited.insert(neighbor);
                    qu.push(neighbor);
                }
            }
        }
        return visited.size()==rooms.size();

    }
};