class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        return n - 999;
        int count = 0;
        for(int i = 1 ; i<=n;i++)
        {
            
            if(i>999) count ++ ;
        }
        return count ;
        
    }
};