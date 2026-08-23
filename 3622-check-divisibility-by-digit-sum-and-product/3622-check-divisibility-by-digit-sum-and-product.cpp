class Solution {
public:
    int sumOfDigit(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int productOfDigit(int n){
        if(n==0) return 0;
        int prod = 1;
        while(n>0){
            prod *= n%10;
            n/=10;
        }
        return prod;
    }
    bool checkDivisibility(int n) {
        int sum = sumOfDigit(n);
        int prod = productOfDigit(n);
        return (n%(sum+prod)==0);
    }
};