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
    bool ans(TreeNode* root, int &Max, int &Min) {
        if(root->left == NULL && root->right == NULL) {
            Max = max(Max, root->val);
            Min = min(Min, root->val);
            return true;
        }
        else if(root->left == NULL) {
            bool temp = ans(root->right, Max, Min);
            if(!temp || Min <= root->val) return false;
            Max = max(Max, root->val);
            Min = min(Min, root->val);
            return true;
        }
        else if(root->right == NULL) {
            bool temp = ans(root->left, Max, Min);
            if(!temp || Max >= root->val) return false;
            Max = max(Max, root->val);
            Min = min(Min, root->val);
            return true;
        }
        else {
            bool temp1 = ans(root->right, Max, Min);
            if(!temp1 || Min <= root->val) return false;

            int Max_temp = INT_MIN;
            bool temp2 = ans(root->left, Max_temp, Min);
            if(!temp2 || Max_temp >= root->val) return false;
            Max = max(Max, max(Max_temp, root->val));
            Min = min(Min, root->val);
            return true;
        }
    }
    bool isValidBST(TreeNode* root) {
        int Min=INT_MAX,Max=INT_MIN;
        return ans(root,Max,Min);
    }
};