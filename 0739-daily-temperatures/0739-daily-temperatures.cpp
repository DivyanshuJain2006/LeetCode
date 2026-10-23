class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ngi(n);
        st.push(n-1);
        ngi[n-1] = -1;
        for(int i=n-2;i>=0;i--){
            while(st.size()>0 and arr[i]>=arr[st.top()]) st.pop();
            if(st.size()==0) ngi[i] = -1;
            else ngi[i] = st.top();
            st.push(i);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            if(ngi[i]==-1) ans[i]=0;
            else ans[i] = ngi[i]-i;
        }
        return ans;
    }
};