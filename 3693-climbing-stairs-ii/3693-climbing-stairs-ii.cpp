class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        const int INF = INT_MAX / 2;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int jump = 1; jump <= 3 && i + jump <= n; ++jump) {
                int next = i + jump;
                int cost = costs[next - 1] + jump * jump;
                dp[next] = min(dp[next], dp[i] + cost);
            }
        }

        return dp[n];
    }
};