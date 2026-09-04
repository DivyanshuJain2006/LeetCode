class Solution {
public:
    int totalMoney(int n) {
        int money = 1;
        int ans = 0;
        int x = 1;
          int count=0;
        while(n--){
            if(count==7){
                money++;
                x = money;
                count = 0;
            }
            ans+=x;
            x++;
            count++;
        }  
        return ans; 
    }
};