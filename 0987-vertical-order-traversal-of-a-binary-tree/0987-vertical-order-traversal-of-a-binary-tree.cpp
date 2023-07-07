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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)   return res;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* tmp=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            mp[x][y].insert(tmp->val);
            if(tmp->left)   q.push({tmp->left,{x-1,y+1}});
            if(tmp->right)  q.push({tmp->right,{x+1,y+1}});
        }
        for(auto i: mp){
            vector<int> tmp;
            for(auto j: i.second){
                tmp.insert(tmp.end(),j.second.begin(),j.second.end());
            }
            res.push_back(tmp);
        }
    return res;
    }
};