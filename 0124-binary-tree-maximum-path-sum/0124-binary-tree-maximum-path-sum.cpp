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
    int in(TreeNode* root, int& sum){
        if(!root)   return 0;
        int l=in(root->left,sum);
        int r=in(root->right,sum);
        sum=max(sum,l+r+root->val);
        return (root->val+max(l,r)<0)? 0: root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        if(!root)   return 0;
        int x=in(root,sum);
        return sum;
    }
};