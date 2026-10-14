class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int remaining = target-nums[i];
            if(m.find(remaining)!=m.end()){
                ans.push_back(m[remaining]);
                ans.push_back(i);
                return ans;
            }
            else m[nums[i]]=i;
        }
        return ans;
    }
};