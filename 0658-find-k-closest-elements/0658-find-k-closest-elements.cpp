class Solution {
public:
    typedef pair<int,int>pii;
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pii>pq;
        for(int i=0;i<arr.size();i++){
            int dist = abs(arr[i]-x);
            pq.push({dist,arr[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [dist,ele] = pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};