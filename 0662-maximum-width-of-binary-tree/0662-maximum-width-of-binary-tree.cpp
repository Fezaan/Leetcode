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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)   return 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            int mind=q.front().second;
            int l=0,r=0;
            for(int i=0;i<n;i++){
                long long curr=q.front().second-mind;
                TreeNode* tmp=q.front().first;
                q.pop();
                if(i==0)    l=curr;
                if(i==n-1)  r=curr;
                
                if(tmp->left)   q.push({tmp->left,curr*2+1});
                if(tmp->right)  q.push({tmp->right,curr*2+2});
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};