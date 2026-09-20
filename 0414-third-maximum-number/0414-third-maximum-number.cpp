class Solution {
public:
    int thirdMax(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi = INT_MIN;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(auto ele : nums){
            mp[ele]++;
            if(mp[ele]==1){
                maxi = max(ele,maxi);
                pq.push(ele);
                if(pq.size()>3) pq.pop();
            }
        }
        if(pq.size()==3) return pq.top();
        return maxi; 
    }
};