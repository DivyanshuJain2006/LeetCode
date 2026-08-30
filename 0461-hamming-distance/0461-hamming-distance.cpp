class Solution {
public:
    string binary(int x){
        string ans = "";
        while(x>0){
            if(x%2==0) ans = '0'+ans;
            else ans = '1'+ans;  
            x/=2;
        }
        return ans;
    }
    int hammingDistance(int x, int y) {
        string a = binary(x);
        string b = binary(y);
        if(a.size()>b.size()){
            int size = a.size()-b.size();
            while(size--){
                b = '0'+b;
            }
        }
        else{
            int size = b.size()-a.size();
            while(size--){
                a = '0'+a;
            }
        }
        int count=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]) count++;
        }
        return count;
    }
};