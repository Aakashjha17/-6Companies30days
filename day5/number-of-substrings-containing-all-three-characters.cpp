/*
This is a very good hashmap problem
Problem description is quite clear : we have to count all those substring of a given string s which have atleast single['a' and 'b' and 'c']
Now the problem we face here is that finding all substrings of a string actually takes O(N*2) time , but we don't need to generate all substrings , Yes in problem we are just required to return number of substrings fulfilling given condtion!!!
Ok but how can we find number of substrings without actually finding all substrings!!!
We will use sliding window technique to solve this problem in O(N) time + we use frequency map to maintain counts of ['a' , 'b' and 'c']
NOTE : string s will only contain [a,b and c] as characters , so size of frequency map will always be 3 , so Space is O(1)
Ok how we can use sliding window to find number of substrings fulfilling condition?
Ans :
        => let good window : window fulfilling condition
        while(right != s.size())
        {
              We tries to form a good window of any size
              Now once we have a good window , we add (1 + (end - right)) to count and then shrink this good window from front and form a new window [if new window is also a good window we repeat the same process]
              Above line in code is like this!!!
              while(window is good)
              {
                  count += (1 + (end - right));
                  shrink window from front to form new window
              }
        }
      [v. imp] why we are adding extra (end - right) to count?
          Ans : because by adding this we are actually considering all those substrings which are bigger in size than current substring and also fully contains our current substring!!!
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , right = 0 , end = s.size() - 1;
        unordered_map<char,int> map;
        
        int count = 0;
        
        while(right != s.size())
        {
            map[s[right]] += 1; // adding new element to window
            
            while(map['a'] and map['b'] and map['c']) // while(window is good)
            {
                count += 1 + (end - right);
                
				// removing first element[means shrinking window from front to form new window]
                map[s[left]] -= 1; 
                left++;
            }
            right++;
        }
        return count;
    }
};
