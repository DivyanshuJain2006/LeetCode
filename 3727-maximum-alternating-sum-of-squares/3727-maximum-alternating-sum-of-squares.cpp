class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++) nums[i] = abs(nums[i]);
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = n/2;
        long long ans = 0;
        while(j<nums.size()){
            ans += nums[j]*nums[j];
            j++;
            if(i==n/2) break;
            ans -= nums[i]*nums[i];
            i++;
        }
        return ans;
    }
};