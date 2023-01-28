class Solution {
private:
    void solve(string s, vector<string> &IPs, vector<string> temp, int index){
        if(index==s.length() && temp.size()==4){
            string validIP = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            IPs.push_back(validIP);
            return;
        }

        string tempStr="";
        for(int i=index; i<s.size() && temp.size()<4; i++){
            tempStr += s[i];
            int tempInt = stoi(tempStr);

            if(tempInt>=0 && tempInt<=255){
                temp.push_back(tempStr);
                solve(s, IPs, temp, i+1);
                temp.pop_back();
            }

            if(tempInt<=0 || tempInt>255)
               break;
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> IPs;
        vector<string> temp;
        solve(s, IPs, temp, 0);

        return IPs;
    }
};
