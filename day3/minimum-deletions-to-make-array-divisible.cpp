class Solution {
public:
    int gcd(int a, int b){
        return (b)?gcd(b, a%b):a;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int gc = numsDivide[0];
        for(int i = 1; i < numsDivide.size(); ++i){
            gc = gcd(gc, numsDivide[i]);
        }
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(gc%nums[i]) ans++;
            else return ans;
        }
        return -1;
    }
};
