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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(!root)   return new TreeNode(x);
        TreeNode* tmp=root;
        while(1){
            if(tmp->val<=x){
                if(tmp->right!=NULL)    tmp=tmp->right;
                else{
                    tmp->right=new TreeNode(x);
                    break;
                }
            }
            else{
                if(tmp->left!=NULL) tmp=tmp->left;
                else{
                    tmp->left=new TreeNode(x);
                    break;
                }
            }
        }
        return root;
    }
};