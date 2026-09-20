class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int ch = s[i];
            int indrev = 26-(ch-97);
            ans += indrev*(i+1);
        }
        return ans;
    }
};