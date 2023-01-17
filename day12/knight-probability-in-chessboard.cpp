class Solution {
public:
    double solve(int n,int k,int r, int c,vector<vector<vector<double>>>& dp){
        if(isValid(r,c,n)==false) return 0;
        if(k==0) return 1;
        if(dp[k][r][c] != -1) return dp[k][r][c];
        double prob=0;
        int dx[8] = {-1,-1,-2,-2,1,2,2,1};
        int dy[8] = {-2,2,-1,1,-2,-1,1,2};
        for(int i=0;i<8;i++){
            prob += solve(n,k-1,r+dx[i],c+dy[i],dp)/8.0;
        }
        return dp[k][r][c]=prob;
    }
    bool isValid(int r,int c,int n){
        if(r<0 || c<0 || r>=n || c>=n){
            return false;
        }
        return true;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k+1,vector<vector<double>>(n,vector<double>(n,-1)));
        return solve(n,k,row,column,dp);
    }
};
