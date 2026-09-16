class Solution {
public:
    vector<string>fans;
    void generate(int n,int open, int close,string ans){
        if(close==n){
            fans.push_back(ans);
            return;
        }
        if(open<n) generate(n,open+1,close,ans+'(');
        if(open>close) generate(n,open,close+1,ans+')');
    }
    vector<string> generateParenthesis(int n) {
        string ans;
        generate(n,0,0,ans);
        return fans;
    }
};