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
class Solution {
public:
    vector<int> inorder(TreeNode* root){
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* node=root;
        while(true){
            if(node!=NULL){
                s.push(node);
                node=node->left;
            }else{
                if(s.empty()==true) break;
                node=s.top();
                s.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1,arr2;
        arr1=inorder(root1);
        arr2=inorder(root2);
        int n=arr1.size();
        int m=arr2.size();
        int gap = ceil((float)(n + m) / 2);
        while (gap > 0) {
            int i = 0;
            int j = gap;
            while (j < (n + m)) {
                if (j < n && arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
                else if (j >= n && i < n && arr1[i] > arr2[j - n]) {
                    swap(arr1[i], arr2[j - n]);
                }
                else if (j >= n && i >= n && arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
                j++;
                i++;
            }
            if (gap == 1) {
                gap = 0;
            } else {
                gap = ceil((float) gap / 2);
            }
        }
        for(int i=0;i<m;i++){
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};
