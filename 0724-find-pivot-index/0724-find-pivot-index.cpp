class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans = -1;
        int n = nums.size();
        for(int i=1;i<nums.size();i++){
            nums[i] = nums[i]+nums[i-1];
        }
        if(nums[n-1]-nums[0]==0) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] == nums[n-1]-nums[i]) return i;
        }
        return -1;
    }
};