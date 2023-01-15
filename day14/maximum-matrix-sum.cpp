//if number of negative term is even then we can create all the negative into positive and //return sum
//if number of negative is odd then we can make smallest value into negative and rest positive  
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        long long sum=0;
        int negative=0;
        int mi=INT_MAX;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum=sum+abs(matrix[i][j]);

                if(matrix[i][j]<0){
                    negative++;
                }
                mi=min(mi,abs(matrix[i][j]));
            }
        }
        if(negative%2==0){
            return sum;
        }else{
            return sum-2*mi;
        }
    }
};
