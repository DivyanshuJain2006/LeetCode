class Solution {
public:
    void nextPermutation(vector<int>& nums) {
       int n=nums.size();
       int pivot=-1;
       for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivot=i;
                break;
            }
       }
       if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        reverse(nums.begin()+pivot+1,nums.end());
        int j=-1;
        for(int k=pivot+1;k<n;k++){
            if(nums[pivot]<nums[k]){
            j=k;
            break;}
        }
        swap(nums[pivot],nums[j]);
    }
};