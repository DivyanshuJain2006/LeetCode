class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n);
        int mx = INT_MIN;
        for(int i=0;i<nums.size();i++){
            mx = max(mx,nums[i]);
            maxi[i] = mx;
        }
        int mn = INT_MAX;
        vector<int>mini(n);
        for(int i=n-1;i>=0;i--){
            mn = min(mn,nums[i]);
            mini[i] = mn;
        }
        for(int i=0;i<n;i++){
            nums[i] = maxi[i]-mini[i];
            if(nums[i]<=k) return i;
        }
        return -1;
    }
};