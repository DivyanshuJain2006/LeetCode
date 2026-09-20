class Solution {
public:
    typedef pair<int,int> pii;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        for(auto ele : nums) mp[ele]++;
        for(auto [ele,freq] : mp){
            pq.push({freq,ele});
            if(pq.size()>k) pq.pop();
        }
        vector<int>ans;
        while(!pq.empty()){
            auto [freq,ele] = pq.top();
            pq.pop();
            ans.push_back(ele);
        }
        return ans;
    }
};