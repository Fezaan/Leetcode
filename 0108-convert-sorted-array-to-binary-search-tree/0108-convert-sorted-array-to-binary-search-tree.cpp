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
    TreeNode* zorojuro(int i,int n, vector<int>& arr){
        if(i>n)   return NULL;
        int pos=(i+n)/2;
        TreeNode* root=new TreeNode(arr[pos]);
        root->left=zorojuro(i,pos-1,arr);
        root->right=zorojuro(pos+1,n,arr);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return zorojuro(0,nums.size()-1,nums);
    }
};