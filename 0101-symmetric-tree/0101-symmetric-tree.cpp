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
    bool find(TreeNode *p, TreeNode* q){
        if(!p || !q)  return p==q;
        if(p->val!=q->val)  return 0;
        return (find(p->left,q->right) && find(p->right,q->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)   return 0;
        return find(root->left,root->right);
    }
};