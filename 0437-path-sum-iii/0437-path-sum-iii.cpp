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
    int f(TreeNode* root, int k){
        if(!root || k<-19999999){
            return 0;
        }
        long long res=0;
        if(root->val==k)    res++;
        res+=f(root->left,k-root->val);
        res+=f(root->right,k-root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)   return 0;
        return pathSum(root->left,targetSum)+f(root,targetSum)+pathSum(root->right,targetSum);
    }
};