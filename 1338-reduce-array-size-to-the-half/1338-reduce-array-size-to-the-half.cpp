class Solution {
public:
    typedef pair<int,int> pii;
    int minSetSize(vector<int>& arr) {
        int x = arr.size()/2;
        int total = 0;
        int ans = 0;
        priority_queue<pii>pq;
        unordered_map<int,int>mp;
        for(auto ele : arr) mp[ele]++;
        for(auto [ele,freq] : mp) pq.push({freq,ele});
        while(!pq.empty()){
            auto [freq,ele] = pq.top();
            pq.pop();
            total += freq;
            if(total>=x){
                ans++;
                return ans;
            }
            ans++;
        }
        return -1;
    }
};