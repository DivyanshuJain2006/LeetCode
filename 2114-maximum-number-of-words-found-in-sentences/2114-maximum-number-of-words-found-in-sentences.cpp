class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int fans = 0;
        for(auto s : sentences){
            int ans = 0;
            for(char ch : s){
                if(ch==' ') ans++;
            }
            ans++;
            fans=max(ans,fans);
        }
        return fans;
    }
};