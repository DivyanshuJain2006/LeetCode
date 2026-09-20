class KthLargest {
public:
    int k;
    priority_queue<int,vector<int>,greater<int>>pq;
    KthLargest(int kalu, vector<int>& nums) {
       k = kalu;
       for(auto ele : nums) pq.push(ele);
    }
    int add(int val) {
        pq.push(val);
        while(pq.size()>k) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */