class Solution {
public:
    string customSortString(string order, string s) {
        string ans="";
        map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        for(auto it: order){
            if(mp.find(it)!=mp.end()){
                int count=mp[it];
                string str(count,it);
                ans+=str;
                mp.erase(it);
            }
        }
        for(auto it: mp){
            string str(it.second,it.first);
            ans+=str;
        }
        return ans;
    }
};
