class Solution {
public:
    typedef pair<int,string> pis;
    struct cmp{
        bool operator()(pis a,pis b){
            if(a.first==b.first) return a.second<b.second;
            return a.first>b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pis,vector<pis>,cmp>pq;
        unordered_map<string,int>mp;
        for(auto ele:words) mp[ele]++;
        for(auto [s,freq]:mp){
            pq.push({freq,s});
            if(pq.size()>k) pq.pop();
        }   
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};