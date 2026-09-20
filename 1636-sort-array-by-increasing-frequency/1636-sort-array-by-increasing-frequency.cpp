class Solution {
public:
    typedef pair<int,int>pii;
    struct cmp{
        bool operator()(pii a,pii b){
            if(a.first==b.first) return b.second>a.second;
            return a.first>b.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto ele:nums) mp[ele]++;
        priority_queue<pii,vector<pii>,cmp>pq;
        for(auto [ele,freq] : mp) pq.push({freq,ele});
        vector<int>ans;
        while(!pq.empty()){
            auto [freq,ele] = pq.top();
            pq.pop();
            while(freq--) ans.push_back(ele);
        }
        return ans;
    }
};