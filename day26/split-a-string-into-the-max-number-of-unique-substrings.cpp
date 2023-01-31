class Solution {
public:
    int ans=0;
    void solve(int ind,string& s,unordered_map<string,int>& mp,int bucket){
        if(ind==s.size()){
            ans=max(ans,bucket);
            return;
        }
        string cur_string="";
        for(int i=ind;i<s.size();i++){
            cur_string+=s[i];

            if(mp[cur_string]>0) continue;
            else{
                mp[cur_string]++;
                solve(i+1,s,mp,bucket+1);
                mp[cur_string]--;
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int> mp;
        solve(0,s,mp,0);
        return ans;
    }
};
