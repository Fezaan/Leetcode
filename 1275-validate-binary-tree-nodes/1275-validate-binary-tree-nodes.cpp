class Solution {
public:
    int cnt(vector<int>& l, vector<int>& r, int root){
        if(root==-1)    return 0;
        return 1+cnt(l,r,l[root])+cnt(l,r,r[root]);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> vis(n,0);
        int root=-1;
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1 && vis[leftChild[i]]++==1) return 0;
            if(rightChild[i]!=-1 && vis[rightChild[i]]++==1) return 0;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(root==-1)    root=i;
                else    return 0;
            }
        }
        if(root==-1)    return 0;
        return cnt(leftChild,rightChild,root)==n;

        return 1;
    }
};