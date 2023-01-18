/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {

      // Attaching one extra node at start of list : entire list make sum 0 then we have to previous node required for deletion 
      ListNode *dummy = new ListNode(0) , *curr = dummy;
      dummy->next = head;
      
      unordered_map<int,ListNode*> mp;
      int presum = 0 ; 
      while ( curr)
      {
          presum += curr->val;
          if(mp.count(presum)) // previously seen then deleted the 
          {
             int p = presum ;        
             curr = mp[presum]->next; // 1st elment to last delete 
             p += curr->val;
             while(p != presum  ) // other than prefix sum inbetween all delete from mp;
             {   
                mp.erase(p);
                curr = curr->next;
                p += curr->val;
             }
             mp[presum]->next = curr->next;
          }
          else 
            mp[presum ] = curr;

          curr = curr->next;
      } 
      return dummy->next;
    }
};
