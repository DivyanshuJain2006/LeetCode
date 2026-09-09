class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(),nums.end());
        int i=0;
        int j=1;
        while(j<n){
            ans += min(nums[i],nums[j]);
            i+=2;
            j+=2;
        }
        return ans;
    }
};