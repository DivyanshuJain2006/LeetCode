class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>visited;
        visited.insert(0);
        queue<int>qu;
        qu.push(0);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            for(auto neighbor : rooms[curr]){
                if(!visited.count(neighbor)){
                    qu.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }
        return (visited.size()==rooms.size());
    }
};