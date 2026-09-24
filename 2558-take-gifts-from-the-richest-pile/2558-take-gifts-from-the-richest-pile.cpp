class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(int ele : gifts) pq.push(ele);
        while(k--){
            auto curr = pq.top();
            pq.pop();
            int rem = floor(sqrt(curr));
            pq.push(rem);
        }
        long long ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};