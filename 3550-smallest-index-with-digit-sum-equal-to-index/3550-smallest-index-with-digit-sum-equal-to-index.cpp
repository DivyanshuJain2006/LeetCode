class Solution {
public:
    int add_digits(int nums){
        int sum = 0, x=1;
        while(nums>0){
            sum += nums%10 * x;
            nums/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int y = 0;
        for(int i=0;i<nums.size();i++){
           if(add_digits(nums[i])==i) return i;
        }
        return -1;
    }
};