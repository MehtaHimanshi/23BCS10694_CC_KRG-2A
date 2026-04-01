class Solution {
public:
    int triangularSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<nums.size()-i;j++){
                nums[j-1]=(nums[j]+nums[j-1])%10;
            }
        }
        return nums[0];
    }
};