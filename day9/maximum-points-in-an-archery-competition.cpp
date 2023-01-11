class Solution {
public:
    int maxscore=0;
    vector<int> ans;
    void solve(int ind,int numArrows,vector<int>& aliceArrows,vector<int>&  bob,int sum){
        if(ind==-1 || numArrows==0){
            if(sum > maxscore){
                maxscore = sum;
                if(numArrows>0){
                    bob[0]+=numArrows;
                }
                ans=bob;
            }
            return; 
        }
        if(aliceArrows[ind]+1<=numArrows){
            bob[ind]=aliceArrows[ind]+1;
            solve(ind-1,numArrows-bob[ind],aliceArrows,bob,sum+ind);
            bob[ind]=0;
        }
        solve(ind-1,numArrows,aliceArrows,bob,sum);
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> bob(12,0);
        solve(11,numArrows,aliceArrows,bob,0);
        return ans;
    }
};
