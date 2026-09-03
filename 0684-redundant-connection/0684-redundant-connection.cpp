class Solution {
public:
vector<int> result = vector<int>(2);
    int find(vector<int>&par,int x){
        if(par[x]==x) return x;
        return par[x] = find(par,par[x]);
    }
    void Union(vector<int>&par,vector<int>&rank,int a,int b){
        int parA = find(par,a);
        int parB = find(par,b);
        if(parA==parB){
            result[0] = a;
            result[1] = b;
            return;
        }
        if(rank[parA]>rank[parB]) par[parB] = parA;
        else if(rank[parB]>rank[parA]) par[parA] = parB;
        else{
            rank[parA]++;
            par[parB] = parA;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>rank(n+1,0);
        vector<int>par(n+1);
        for(int i=1;i<=n;i++){
            par[i]=i;
        }
        for(int i=0;i<n;i++){
            Union(par,rank,edges[i][0],edges[i][1]);
        }
        return result;
    }
};