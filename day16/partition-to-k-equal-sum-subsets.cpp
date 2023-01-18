class Solution {
public:
    bool check_special(vector<int>& sp,vector<int>& needs){
        for(int i=0;i<needs.size();i++){
            if(needs[i]<sp[i]){
                return false;
            }
        }
        return true;
    }
    int solve(int ind,vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        if(ind==special.size()){
            int sum=0;
            for(int i=0;i<needs.size();i++){
                if(needs[i]>0){
                    sum+=needs[i]*price[i];
                }
            }
            return sum;
        }
        int nottake=solve(ind+1,price,special,needs);
        int take=INT_MAX;
        if(check_special(special[ind],needs)==true){
            for(int i=0;i<needs.size();i++){
                needs[i]-=special[ind][i];
            }
            take=special[ind][needs.size()]+solve(ind,price,special,needs);
            for(int i=0;i<needs.size();i++){
                needs[i]+=special[ind][i];
            }
        }
        return min(take,nottake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(0,price,special,needs);
    }
};
