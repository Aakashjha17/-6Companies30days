class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());

        int n = piles.size();
        int ans = 0;
        int j = n-2;
        n = n/3;
        while(n--){
            ans += piles[j];
            j =j- 2;
        }
        return ans;
    }
};
