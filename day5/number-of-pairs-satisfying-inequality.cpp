/*
Given that we have to find i , j such that 0 <= i < j <= n - 1 and
nums1[i] - nums1[j] <= nums2[i] - nums2[j] + diff
Step 1::
Rewriting the inequality--
(nums1[i] - nums2[i]) <= (nums1[j] - nums2[j]) + diff

Step 2::
Make a new array/vector c which stores nums1[i]-nums2[i].
or c[i] = nums1[i]-nums2[i] for 0 <= i <= n - 1.

Step 3::
Problem reduces to find i , j such that 0 <= i < j <= n - 1 and
c[i] <= c[j] + diff

Now, This can be solved by using merge sort (Similar to inversion counting )
*/

class Solution {
public:
    long long int count;
    void check(vector<int>& nums,int start,int mid,int end,int diff){
        int l=start,r=mid+1;
        while(l<=mid && r<=end){
            if(nums[l]<=(nums[r]+diff)){
                count+=(end-r+1);
                l++;
            }else{
                r++;
            }
        }
        sort(nums.begin() + start, nums.begin() + end + 1);
        return;
    }
    void  mergesort(vector<int>& nums,int start,int end,int diff){
        if(start==end){
            return;
        }
        int mid=(start+end)/2;
        mergesort(nums,start,mid,diff);
        mergesort(nums,mid+1,end,diff);

        check(nums,start,mid,end,diff);
        return;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        count=0;
        int n=nums1.size();
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=nums1[i]-nums2[i];
        }
        mergesort(nums,0,n-1,diff);
        return count;
    }
};
