class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int>mp;
        int slow=0;
        int maxLen=0;
        for(int fast=0;fast<fruits.size();fast++){
            int right=fruits[fast];
            mp[right]++;
            
            while(mp.size()>2){
                int left=fruits[slow];
                mp[left]--;
                if(mp[left]==0) mp.erase(left);
                slow++;
            }
            
            maxLen=max(maxLen,fast-slow+1);
        }
        return maxLen;
        
    }
};
