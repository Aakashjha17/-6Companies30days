class Solution {
public:
    bool isStrictlyPalindromic(int decimal) {
        long long int binary = 0, remainder, product = 1, rev = 0;
        for(int i=2; i<decimal; i++)
        {
          while (decimal != 0) {
            remainder = decimal % i;
            binary = binary + (remainder * product);
            decimal = decimal / i;
            product *= 10;
            rev = binary;
            
        }
        string str = to_string(rev);
        reverse(str.begin(),str.end());
        if(str != to_string(decimal))
        {
            return false;
        }
        
      }
      return true;
    }
};
