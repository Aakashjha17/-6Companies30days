class Solution {
public:
    
    int solve(vector<bool> &n_bits, int ind, vector<vector<int>> &dp,int last){
        // if we have reached at the last bit 
        if(ind == n_bits.size()){
            return 1;
        }
        // if we are at starting index
        if(ind == 0){
            // here we have to put 1
            return solve(n_bits,ind+1,dp,1);
        }
        int ans = 0;
        if(n_bits[ind]){
            // current bit is 1 so we can add possible answers if we use 0 at this bit 
            ans += dp[0][n_bits.size()-ind-1];
            // now we check if have used last bit as 1 then we cannot add possible answers for 1 at this index
            // so return answer
            if(last) return ans;
            // but if previous bit was zero then we can solve for next
            ans += solve(n_bits,ind+1,dp,1);
            return ans;
        }
        // if current bit is 0 then we have to solve for n - ind bits
        return solve(n_bits,ind+1,dp,0);
    }
    
    int findIntegers(int n) {
        // consecutive 1 nahi hona chahiye
        // so numbers can be
        int bits = 0;
        vector<bool> n_bits; // to store bits of n
        int nc = n;
        while(nc){
            bits++;
            n_bits.push_back(nc&1);
            nc = nc>>1;
        }
        reverse(n_bits.begin() , n_bits.end());
        // dp for digits with bits number of significant bits
        vector<vector<int>> dp(2,vector<int>(bits,0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        // till nth end bits
        for(int i=1;i<bits;i++){
            dp[0][i] = dp[0][i-1] + dp[1][i-1];
            dp[1][i] = dp[0][i-1];
        }
        int ans = dp[0][bits-1];
        ans += solve(n_bits,0,dp,0);
        return ans;
    }
};
