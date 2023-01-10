// Given eqn is nums[i]+rev(nums[j])==nums[j]+rev(nums[i])
// After rearranging the eqn nums[i]-rev(nums[i])==rev(nums[j])-nums[j]
// We will store the frequency of nums[i]-rev(nums[i]);
// 42 11 1 97 nums
// 18 0  0  18 map
// We have to count the total pairs which is basically Nc2(n*(n-1)/2);
class Solution {
public:
    int reverse(int n){
        int rev=0, rem; 
        while(n!=0){    
            rem=n%10;      
            rev=rev*10+rem;    
            n/=10;    
        }
        return rev;    
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int r=reverse(nums[i]);
            mp[nums[i]-r]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            
            ans=(ans%1000000007+((x.second)*1LL*(x.second-1)/2)%1000000007)%1000000007;
        }
        return ans;
    }
};
