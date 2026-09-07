class Solution {
public:
    bool halvesAreAlike(string s) {
        int ans1=0;
        int ans2=0;
        for(int i=0;i<s.size();i++){
           if(s[i]=='a' ||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A' || s[i]=='E' || s[i]=='I'|| s[i]=='O' || s[i]=='U'){
            if(i<(s.size()/2)) ans1++;
            else ans2++;
           }
        }
        return ans1==ans2;
    }
};