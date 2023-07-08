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
    TreeNode* getTree(vector<int> & pre, int pres, int pree, vector<int> & in, int ins, int ine, map<int,int> & mp){
        if(pres>pree || ins>ine)    return NULL;
        TreeNode* root= new TreeNode(pre[pres]);
        int roots=mp[root->val];
        int len=roots-ins;
        root->left=getTree(pre,pres+1,len+pres,in,ins,roots-1,mp);
        root->right=getTree(pre,pres+len+1,pree,in,roots+1,ine,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]]=i;
        int n=preorder.size()-1;
        int m=inorder.size()-1;
        TreeNode* root=getTree(preorder,0,n,inorder,0,m,mp);
        return root;
    }
};