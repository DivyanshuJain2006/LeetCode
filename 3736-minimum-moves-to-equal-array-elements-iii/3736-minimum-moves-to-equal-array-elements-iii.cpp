class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int Max = INT_MIN;
        for(int i=0;i<nums.size();i++){
            Max = max(Max,nums[i]);
        }
         for(int i=0;i<nums.size();i++){
            ans += Max - nums[i];
        }
        return ans;
    }
};