class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        long long odd = 0, even = 1; // Empty prefix has even sum
        long long answer = 0;
        int parity = 0;

        for (int x : arr) {
            parity ^= (x & 1);

            if (parity == 1) {
                answer = (answer + even) % MOD;
                ++odd;
            } else {
                answer = (answer + odd) % MOD;
                ++even;
            }
        }

        return static_cast<int>(answer);
    }
};
