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
    bool isleaf(TreeNode* root){
        return !root->left && !root->right;
    }
    int minDepth(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int mind=INT_MAX;
        while(!q.empty()){
            TreeNode* tmp=q.front().first;
            int x=q.front().second;
            q.pop();
            if(isleaf(tmp)) mind=min(mind,x);
            
            if(tmp->left)   q.push({tmp->left,x+1});
            if(tmp->right)  q.push({tmp->right,x+1});
        }
        return mind+1;
    }
};