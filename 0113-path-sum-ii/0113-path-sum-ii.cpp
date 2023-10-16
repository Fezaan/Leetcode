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
    void f(TreeNode* root ,int k, vector<vector<int>>& res, vector<int> ds){
        if(!root->left && !root->right){
            if(k==root->val){
                ds.push_back(root->val);
                res.push_back(ds);
                ds.pop_back();
            }    
            return;
        }
        if(root->left){
            ds.push_back(root->val);
            f(root->left, k-root->val,res,ds);
            ds.pop_back();
        } 
        if(root->right){
            ds.push_back(root->val);
            f(root->right, k-root->val,res,ds);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if(!root)   return res;  
        vector<int> ds;
        f(root,targetSum,res,ds);
        return res;
    }
};