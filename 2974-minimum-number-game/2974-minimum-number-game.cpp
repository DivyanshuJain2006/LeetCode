class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int>arr;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(!pq.empty()){
            int first = pq.top();
                pq.pop();
                int second = pq.top();
                pq.pop();
                arr.push_back(second);
                arr.push_back(first);
        }
        return arr;
    }
};