class Solution {
public:
    vector<string>ans;
   void generate(int idx, int n, string s) {
        if (idx == n) {
            ans.push_back(s);
            return;
        }
        generate(idx + 1, n, s + '1');
        if (idx == 0 || s[idx - 1] == '1') {
            generate(idx + 1, n, s + '0');
        }
    }
    vector<string> validStrings(int n) {
        string s="";
        generate(0,n,s);
        return ans;
    }
};