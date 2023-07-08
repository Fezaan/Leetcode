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
    TreeNode* getTree(vector<int> & post, int posts, int poste, vector<int> & in, int ins, int ine, map<int,int> & mp){
        if(posts>poste || ins>ine)    return NULL;
        TreeNode* root= new TreeNode(post[poste]);
        int roots=mp[root->val];
        int len=roots-ins;
        root->left=getTree(post,posts,posts+len-1,in,ins,roots-1,mp);
        root->right=getTree(post,posts+len,poste-1,in,roots+1,ine,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++)   mp[inorder[i]]=i;
        int n=postorder.size()-1;
        int m=inorder.size()-1;
        TreeNode* root=getTree(postorder,0,n,inorder,0,m,mp);
        return root;
    }
};