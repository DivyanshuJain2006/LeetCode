class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int answer = INT_MAX;

        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;

            for (int end = start; end < nums.size() && end - start + 1 <= r; ++end) {
                sum += nums[end];
                int length = end - start + 1;

                if (length >= l && sum > 0) {
                    answer = min(answer, sum);
                }
            }
        }

        return answer == INT_MAX ? -1 : answer;
    }
};