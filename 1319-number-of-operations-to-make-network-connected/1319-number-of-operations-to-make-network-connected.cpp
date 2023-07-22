class DisjointSet{
    public:
    vector<int> parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++)    parent[i]=i;
    }
    int uParent(int node){
        if(parent[node]==node)
            return node;
        return parent[node]= uParent(parent[node]);
    }
    void setUnionRank(int u,int v){
        int uu=uParent(u);
        int uv=uParent(v);
        if(rank[uu]==rank[uv]){
            parent[uu]=uv;
            rank[uv]++;
        }
        else if(rank[uu]<rank[uv])  parent[uu]=uv;
        else    parent[uv]=uu;
    }
    void setUnionSize(int u, int v){
        int uu=uParent(u);
        int uv=uParent(v);
        if(size[uu]<size[uv]){
            size[uv]+=size[uu];
            parent[uu]=uv;
        }
        else{
            size[uu]+=size[uv];
            parent[uv]=uu;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra=0, cnt=0;
        for(auto it: connections){
            int u=it[0],v=it[1];
            if(ds.uParent(u)==ds.uParent(v))    cntExtra++;
            else ds.setUnionSize(u,v);
        }
        for(int i=0;i<n;i++)
            if(ds.parent[i]==i) cnt++;
        if(cntExtra<cnt-1)    return -1;
        return cnt-1;
    }
};