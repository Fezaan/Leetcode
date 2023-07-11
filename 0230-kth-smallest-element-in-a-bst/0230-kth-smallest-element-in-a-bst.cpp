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
    TreeNode* find(TreeNode* root, int &k){
        if(!root)   return root;
        TreeNode* left=find(root->left,k);
        if(left)    return left;
        k--;
        if(k==0)    return root;
        return find(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)   return 0;
        TreeNode* tmp=find(root,k);
        return tmp->val;
    }
};