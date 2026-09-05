class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxi(n);
        vector<int>mini(n);
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(nums[i],mx);
            maxi[i] = mx;
        }
        int mn = INT_MAX;
        for(int i=n-1;i>=0;i--){
            mn = min(mn,nums[i]);
            mini[i] = mn;
        }
        for(int i=0;i<n;i++){
            if(maxi[i]-mini[i]<=k) return i;
        }
        return -1;
    }
};