class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        //sort the given array
        sort(nums.begin(),nums.end());
        int n=nums.size();
        //create two array 1. to store maximum size 2. to store last indexx
        vector<int> dp(n,1),hash(n);
        int maxi=1;
        //initially lastindex will be 0
        int lastindex=0;
        //start the loop from 0->n
        for(int i=0;i<n;i++){
            //number will be itself divisible by themselve hence the hash of the array will be their index 
            hash[i]=i;
            //start the loop from 0->i-1
            for(int prev=0;prev<i;prev++){
                //checking if the current element is divisible by prev element and update the size of subset
                if(nums[i]%nums[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            //update the maximum
            if(dp[i]>maxi){
                maxi=dp[i];
                lastindex=i;
            }
        }
        //creating a new array to store the ans
        vector<int> temp;
        temp.push_back(nums[lastindex]);
        while(hash[lastindex]!=lastindex){
            lastindex=hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        return temp;
    }
};
