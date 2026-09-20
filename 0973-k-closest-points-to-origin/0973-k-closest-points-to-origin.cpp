class Solution {
public:
    typedef pair<int,int> pii;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pii>>pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            pq.push({dist,{x,y}});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto curr = pq.top();
            ans.push_back({curr.second.first,curr.second.second});
            pq.pop();
        }
        return ans;
    }
};