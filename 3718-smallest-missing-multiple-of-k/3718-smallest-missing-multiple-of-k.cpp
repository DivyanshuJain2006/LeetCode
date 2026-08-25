class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int x = k;
      
        while(1){
            if(s.find(x)==s.end()) return x;
            x+=k;
        }
        return -1;
    }
};