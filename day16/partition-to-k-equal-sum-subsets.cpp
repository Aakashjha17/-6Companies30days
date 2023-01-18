class Solution {
public:
    bool isValid(vector<int>& nums, vector<int>& dp, int mask, int currentSum, int totalSum, int part, int total, int index){
        if(part == total){
            return true;
        }
        
        if(currentSum == totalSum){
            return isValid(nums, dp, mask, 0, totalSum, part + 1, total, 0);
        }
        
        if(index == nums.size()){
            return false;
        }
        
        if(dp[mask] != -1){
            return dp[mask] == 1;
        }
        
        int i, j;
        j = 1 << index;
        
        bool result = false;
        if((j & mask) != 0 && nums[index] + currentSum <= totalSum){
            result = isValid(nums, dp, mask - j, currentSum + nums[index], totalSum, part, total, index + 1);
        }
        if(result){
            dp[mask] = 1;
            return true;
        }
        
        result = isValid(nums, dp, mask, currentSum, totalSum, part, total, index + 1);
        dp[mask] = result ? 1 : 0;
        return result;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = 0;
        int i, j;
        int len = nums.size();
        
        for(i = 0; i < len; i++){
            total += nums[i];
        }
        if(total % k != 0){
            return false;
        }
        
        int mask = 1 << len;
        vector<int> dp(mask, -1);
        
        return isValid(nums, dp, mask - 1, 0, total / k, 0, k, 0);
    }
};
