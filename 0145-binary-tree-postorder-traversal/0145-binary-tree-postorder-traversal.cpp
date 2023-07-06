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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode* > st1,st2;
        if(root==NULL)  return res;
        
        st1.push(root);
        while(!st1.empty()){
            TreeNode* tmp=st1.top();
            st1.pop();
            st2.push(tmp);
            if(tmp->left)   st1.push(tmp->left);
            if(tmp->right)   st1.push(tmp->right);
        }
        while(!st2.empty()){
            res.push_back(st2.top()->val);
            st2.pop();
        }
        return res;
    }
};