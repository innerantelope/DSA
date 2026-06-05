class TrieNode {
public:
    TrieNode* children[26];
    bool isend;
    TrieNode() {
        isend = false;
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    // Trie* children[26];
    // bool isend;
    TrieNode* root;
    Trie() {
            // isend=false;
            // for(int i=0;i<26;i++){
            // children[i]=nullptr;
            root=new TrieNode();
        } 
    void insert(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr){
                curr->children[c-'a']=new TrieNode();
            }
            curr=curr->children[c-'a'];
        }
        curr->isend=true;
    }
    
    bool search(string word) {
        TrieNode* curr=root;
        for(char c:word){
            if(curr->children[c-'a']==nullptr) return false;
            curr=curr->children[c-'a'];
        }
        return curr->isend;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr=root;
        for(char c:prefix){
            if(curr->children[c-'a']==nullptr) return false;
            curr=curr->children[c-'a'];
        }

        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */