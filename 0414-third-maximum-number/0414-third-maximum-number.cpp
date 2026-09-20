class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int> s;

for(auto x : nums) {
    s.insert(x);
    if(s.size() > 3)
        s.erase(s.begin());
}

if(s.size() == 3)
    return *s.begin();

return *s.rbegin();
    }
};