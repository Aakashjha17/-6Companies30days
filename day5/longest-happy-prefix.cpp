//kmp alogorithm

class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        int index=0;
        vector<int> kmp(n,0);
        for(int i=1;i<n;){
            if(s[i]==s[index]){
                index++;
                kmp[i]=index;
                i++;
            }else{
                if(index!=0)
                    index=kmp[index-1];
                else
                    i++;
            }
        }
        return s.substr(0, kmp.back());
    }
};
