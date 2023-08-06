class Node {
public:
    Node * children[26];
    bool isEnd;
    Node()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};

class Trie {
    Node * root;
public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            int ind=word[i]-'a';
            if(!node->children[ind])    node->children[ind]=new Node();
            node=node->children[ind];
        }
        node->isEnd=1;
    }
    
    bool search(string word) {
        if(!root)   return 0;
        Node* node=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(!node->children[ind])    return 0;
            node=node->children[ind];
        }
        return node->isEnd;
    }
    
    bool startsWith(string word) {
        if(!root)   return 0;
        Node * node=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(!node->children[ind])    return 0;
            node=node->children[ind];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */