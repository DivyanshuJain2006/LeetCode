class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = prices[n-1];
        vector<int>maxRight(n);
        maxRight[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            maxRight[i] = maxi;
            maxi = max(maxi,prices[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans,maxRight[i]-prices[i]);
        }
        return ans;
    }
};