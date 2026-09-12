class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count = 0;
        for(auto [val,freq] : mp){
            if(freq==3){
                vector<int>v;
                for(int i=0;i<nums.size();i++){
                    if(nums[i]==val) v.push_back(i);
                }
                if(v[2]-v[1]==v[1]-v[0]) count++;
            }
        }
        return count;
    }
};