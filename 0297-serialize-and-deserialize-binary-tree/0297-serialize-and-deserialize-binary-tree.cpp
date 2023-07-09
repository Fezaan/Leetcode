/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)   return "";
        
        queue<TreeNode* > q;
        q.push(root);
        string res="";
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(!tmp)    res.append("#,");
            else res.append(to_string(tmp->val)+",");
            
            if(tmp){
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())    return NULL;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        queue<TreeNode*> q;
        TreeNode* root= new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#")    tmp->left=NULL;
            else{
                TreeNode* x=new TreeNode(stoi(str));
                tmp->left=x;
                q.push(x);
            }
            getline(s,str,',');
            if(str=="#")    tmp->right=NULL;
            else{
                TreeNode* x=new TreeNode(stoi(str));
                tmp->right=x;
                q.push(x);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));