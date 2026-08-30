class Solution {
public:
    int fun(int x){
        int count = 0;
        while(x>0){
            if(x%2==1) count++;
            x/=2;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            ans[i] = fun(i);
        }
        return ans;
    }
};