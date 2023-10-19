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
    bool f(TreeNode* root, int k){
        if(!root)   return 1;
        if(root->val!=k)    return 0;
        return f(root->left,k)&&f(root->right,k);
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root)   return 0;
        int val=root->val;
        return f(root,val);
    }
};