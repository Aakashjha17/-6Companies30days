class Solution {
public:
vector<bool>vis;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(auto it:nums)
        sum+=it;
        if(sum%k)return false;
        sum/=k;//required sum
        vis.assign(n,false);
        return helper(nums,0,n,k,0,sum);//(nums,curr_indx,n,k,curr_sum,target)

    }
    bool helper(vector<int>&nums,int i,int n,int k,int curr_sum,int target)
    {
        if(k==1)
        return true;
        if(i==n)
        return false;
        //we found one subset with curr_sum=target
        if(curr_sum==target)
        return helper(nums,0,n,k-1,0,target);
        for(int j=i;j<n;j++)
        {
            if(vis[j]==false&&curr_sum+nums[j]<=target)
            {
                vis[j]=true;
                curr_sum+=nums[j];
                if(helper(nums,j+1,n,k,curr_sum,target))
                return true;
                vis[j]=false;
                curr_sum-=nums[j];
            }
        }
        return false;
    }
};
