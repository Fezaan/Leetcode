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
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;
        int ans=0,level=0;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            level++;
            int sum=0;
            for(int i=q.size();i>0;i--){
                TreeNode *tmp=q.front();
                q.pop();
                sum+=tmp->val;
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
            if(maxsum<sum){
                maxsum=sum;
                ans=level;
            }
        }
        return ans;
        
    }
};