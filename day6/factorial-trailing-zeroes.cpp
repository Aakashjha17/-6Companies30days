/*
trailing 0's are produced by multiples of 10, and pairs of 2 and 5 make up multiples of 10 .. we know in factorial there will be more factors of 2 than 5, 
so the max pairs we can have depends on the multiples of 5 present in factorial(n), so we only need to count the multiples of 5 (to be more efficient). 
However, some multiples of 5 contribute more than 1 trailing 0, for example, 25 = 5x5, which contributes 2 trailing 0's, and 125 = 5x5x5 which 
contributes 3.. the pattern here is that powers of 5 produce additional trailing 0's, which is why we also check for the number of multiples of powers of 
5 to ensure we account for the additional trailing 0's. When doing n/5 for example, we are accounting for all the factors of 5 including 10,20,30,40 ..
*/
class Solution {
public:
    int trailingZeroes(int n) {
        int cnt = 0;
        while(n>0){
            cnt += n/5;
            n/=5;
        }
        return cnt;
    }
};
