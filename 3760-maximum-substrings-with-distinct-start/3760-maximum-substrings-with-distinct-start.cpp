class Solution {
public:
    int maxDistinct(string s) {
        unordered_set<char>se;
        for(auto ele:s){
            se.insert(ele);
        }
        return se.size();
    }
};