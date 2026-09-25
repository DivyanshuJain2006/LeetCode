class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[0]<b[0];
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int,int>mp;
        for(auto ele : items1) mp[ele[0]]+=ele[1];
        for(auto ele : items2) mp[ele[0]]+=ele[1];
        vector<vector<int>>ans;
        for(auto [ele,freq]:mp){
            ans.push_back({ele,freq});
        }
        sort(ans.begin(),ans.end(),cmp);
        return ans;
    }
};