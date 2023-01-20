class Solution {
public:
    bool check(int num){
        if(num<2) return false;
        if(num==2) return true;
        for(int i=2;i<num;i++){
            if(num%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int a=-1,b=-1,diff=INT_MAX,last=-1;
        for(int i=left;i<=right;i++){
            if(check(i)){
                if(a==-1) a=i;
                else if(b==-1){
                    b=i;
                    diff=b-a;
                }
                else if(i-last<diff){
                    a=last;
                    b=i;
                    diff=b-a;
                }
                last=i;
            }
            if(diff<=2) return {a,b};
        }
        if(a==-1 || b==-1) return {-1,-1};
        else return{a,b};
    }
};
