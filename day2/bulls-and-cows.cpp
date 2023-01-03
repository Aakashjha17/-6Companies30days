class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> firstfr (10,0);
        vector<int> secondfr (10,0);

        int bulls=0,cows=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                firstfr[secret[i]-'0']++;
                secondfr[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;i++){
            cows+=min(firstfr[i],secondfr[i]);
        }
        return to_string(bulls) + 'A'+ to_string(cows) + 'B';
    }
};
