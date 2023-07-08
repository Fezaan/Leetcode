/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root, TreeNode* target, unordered_map<TreeNode* , TreeNode*> & parent){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp->left){
                parent[tmp->left]=tmp;
                q.push(tmp->left);
            }
            if(tmp->right){
                parent[tmp->right]=tmp;
                q.push(tmp->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root,target,parent);
        unordered_map<TreeNode*, bool> visit;
        queue<TreeNode*> q;
        q.push(target);
        int dist=0;
        visit[target]=true;
        while(!q.empty()){
            int n=q.size();
            if(dist==k) break;
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left && !visit[tmp->left]){
                    q.push(tmp->left);
                    visit[tmp->left]=true;
                }
                if(tmp->right && !visit[tmp->right]){
                    q.push(tmp->right);
                    visit[tmp->right]=true;
                }
                if(parent[tmp] && !visit[parent[tmp]]){
                    q.push(parent[tmp]);
                    visit[parent[tmp]]=true;
                }
            }
            dist++;
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }
};