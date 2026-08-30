class Solution {
public:
    #define ll long long
    int find(vector<int>&parent,int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent,parent[x]);
    }
    void Union(vector<int>&par,vector<int>&rank,int a,int b){
        a = find(par,a);
        b = find(par,b);
        if(a==b) return;
        if(rank[a]>rank[b]) par[b] = a;
        else if(rank[b]>rank[a]) par[a] = b;
        else{
            rank[a]++;
            par[b] = a;
        }
    }
    struct Edge{
        int src;
        int dest;
        int wt;
    };
    static bool cmp(Edge e1,Edge e2){
        return e1.wt<e2.wt;
    }
    ll kruskals(vector<Edge>&input,int n){
        sort(input.begin(),input.end(),cmp);
        vector<int>par(n+1);
        vector<int>rank(n+1,0);
        for(int i=1;i<=n;i++){
            par[i] = i;
        }
        int edgeCount = 0;
        ll ans = 0;
        int i=0;
        while(edgeCount<n-1){
            Edge curr = input[i];
            int srcPar = find(par,curr.src);
            int srcDest = find(par,curr.dest);
            if(srcPar!=srcDest){
                Union(par,rank,srcPar,srcDest);
                edgeCount++;
                ans+=curr.wt;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
         vector<Edge>edges;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt = abs(points[i][0] - points[j][0])
               + abs(points[i][1] - points[j][1]);
                edges.push_back({i, j, wt});
            }
         }
         return kruskals(edges,n);
    }
};