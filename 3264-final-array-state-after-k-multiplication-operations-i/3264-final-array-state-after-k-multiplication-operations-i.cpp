class Solution {
public:
    typedef pair<int,int>pii;
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        for(int i=0;i<nums.size();i++) pq.push({nums[i],i});
        while(k--){
            auto [ele,idx] = pq.top();
            pq.pop();
            pq.push({multiplier*ele,idx});
        }
        
        while(!pq.empty()){
            auto [ele,idx] = pq.top();
            pq.pop();
            nums[idx] = ele;
        }
        return nums;
    }
};