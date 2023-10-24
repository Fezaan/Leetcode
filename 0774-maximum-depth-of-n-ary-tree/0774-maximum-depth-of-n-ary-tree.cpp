/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        int cnt=0;
        queue<Node*> q;
        if(!root)   return 0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* tmp=q.front();
                q.pop();
                for(auto it: tmp->children) q.push(it);
            }
            cnt++;
        }
        return cnt;
    }
};