class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if(numerator==0){
            return "0";
        }
        string ans="";
        if(numerator<0 && denominator>0){
            ans+="-";
        }else if(numerator>0 && denominator<0){
            ans+="-";
        }
        int64_t num=abs(numerator),den=abs(denominator);
        ans+=to_string(num/den);
        if(num%den==0) return ans;
        ans+='.';
        unordered_map<int,int> mp;
        int64_t rem=num%den;
        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                int pos=mp[rem];
                ans.insert(pos,"(");
                ans.append(")");
                break;
            }else{
                mp[rem] = ans.size();
                rem*=10;
                ans+=to_string(rem/den);
                rem=rem%den;
            }
        }
        return ans;
    }
};
