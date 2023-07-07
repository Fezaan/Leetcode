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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)   return res;
        map<int,int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root,0});
        while(!q.empty()){
            int lvl=0,n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front().first;
                int x=q.front().second;
                q.pop();
                lvl=tmp->val;
                if(tmp->left)   q.push({tmp->left,x+1});
                if(tmp->right)  q.push({tmp->right,x+1});
            }
            res.push_back(lvl);
        }
        return res;
    }
};