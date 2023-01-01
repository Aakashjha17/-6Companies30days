class Solution {
public:
    void help(int sum, int size, int n, int i, vector<vector<int>>& res, vector<int> subset){
      //if sum ==0 and size of our subset is equal to given size then push this subset into ans array
        if(sum==0 && size==0){
            res.push_back(subset);
            return;
        }
       //checking if sum has gone to negative or size of our subset is less than 0 or i is greater than 9 then return 
        if(sum<0 || size<0 || i>n) return;
        
      //push the current i in the subset and reduce the sum by i and increase the i and reduce the size by 1 
         subset.push_back(i);
         help(sum-i, size-1, n, i+1, res, subset);
         subset.pop_back();
        
         if(n-i>=size)   
             help(sum, size, n, i+1, res, subset);
    }
    
    vector<vector<int>> combinationSum3(int size, int sum) {
        vector<vector<int>> res{};
        vector<int> subset{};
        
        help(sum, size, 9, 1, res, subset);
        return res;
    }
};
