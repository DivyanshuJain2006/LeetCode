class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        while(k--){
            int ele = pq.top();
            pq.pop();
            sum-=ele;
            pq.push(-1*ele);
            sum += (-1*ele);
        }
        return sum;
    }
};