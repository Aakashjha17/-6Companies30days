/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //pair<int,int> denotess {sum of nodes values in a subtree , number of nodes in subtree}
class Solution {
public:
    pair<int,int> solve(TreeNode* root,int &ans){
        if(!root)
            return {0,0};
        if(!root->left&&!root->right){
            ans+=1;
            return {root->val,1};
        }
        pair<int,int> l=solve(root->left,ans);
        pair<int,int> r=solve(root->right,ans);
        int avg=(root->val+l.first+r.first)/(l.second+r.second+1);
        if(avg==root->val)
            ans++;
        return {root->val+l.first+r.first,l.second+r.second+1};
        
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};
