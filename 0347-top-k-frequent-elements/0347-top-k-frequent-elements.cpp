class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto ele:nums) mp[ele]++;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for (auto [ele,freq] : mp){
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};