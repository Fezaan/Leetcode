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
    TreeNode* find(int &i, vector<int> &A, int lim){
        if(i==A.size() || A[i]>lim) return NULL;
        
        TreeNode* root=new TreeNode(A[i++]);
        root->left=find(i,A,root->val);
        root->right=find(i,A,lim);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& arr) {
        int ind=0;
        return find(ind,arr,INT_MAX);
    }
};