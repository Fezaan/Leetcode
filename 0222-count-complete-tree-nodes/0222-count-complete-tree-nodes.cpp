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
    void pre(TreeNode* root, int & res){
        if(!root)   return;
        res++;
        pre(root->left,res);
        pre(root->right,res);
    }
    int countNodes(TreeNode* root) {
        if(!root)   return 0;
        int cnt=0;
        pre(root,cnt);
        return cnt;
    }
};