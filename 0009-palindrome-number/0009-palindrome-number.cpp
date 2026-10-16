class Solution {
public:
    bool f(int n){
        long long ans=0;
        long long y = n;
        while(n>0){
            long long x = n%10;
            ans = ans*10+x;
            n/=10;
        }
        return ans==y;
    }
    bool isPalindrome(int x) {
        if(x<0) return false;
        return f(x);
    }
};