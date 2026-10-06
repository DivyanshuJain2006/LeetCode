class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for (auto ele : s) {
            if (ele == '(') open++;
            else if (open > 0) open--;
            else ans++;    
        }
        return ans + open;
    }
};