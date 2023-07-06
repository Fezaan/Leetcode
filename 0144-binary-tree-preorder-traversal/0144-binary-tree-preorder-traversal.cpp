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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        if(root==NULL)  return res;
        
        st.push(root);
        while(!st.empty()){
            int n=st.size();
            
            for(int i=0;i<n;i++){
                TreeNode* tmp=st.top();
                st.pop();
                if(tmp->right)  st.push(tmp->right);
                if(tmp->left)   st.push(tmp->left);
                res.push_back(tmp->val);
            }
        }
        return res;
    }
};