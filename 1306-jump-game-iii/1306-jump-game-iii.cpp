class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>qu;
        qu.push(start);
        while(!qu.empty()){
            auto curr = qu.front();
            qu.pop();
            if(arr[curr]==0) return true;
            if(arr[curr]==-1) continue;
            if(curr+arr[curr]<n) qu.push(curr+arr[curr]);
            if(curr-arr[curr]>=0) qu.push(curr-arr[curr]);
            arr[curr]=-1;
        }
        return false;
    }
};