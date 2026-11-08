class Solution {
public:
    int countServers(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        vector<int> row(n,0), col(m,0);
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<m;++j){
                count+=arr[i][j];
            }
            row[i]=count;
        }
        for(int j=0;j<m;++j){
            int count=0;
            for(int i=0;i<n;++i){
                count+=arr[i][j];
            }
            col[j]=count;
        }

        int count=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(arr[i][j]==1 && (row[i]>1 || col[j]>1)) count++;
            }
        }
        return count;


    }
};