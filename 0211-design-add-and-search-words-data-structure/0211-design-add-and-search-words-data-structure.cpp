class TrieNode{
    public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode(){
        isEnd =false;

        for(int i=0;i<26;i++){
            child[i] = nullptr;
        }
    }
};


class WordDictionary {
public:
TrieNode*root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node =root;
        for(char c:word){
            int idx = c - 'a';

            if(!node->child[idx]) 
            node->child[idx] = new TrieNode();

            node  = node->child[idx];
        }
        node->isEnd =true;
    }

    bool dfs(string &word,int pos,TrieNode* node){
        if(!node) return false;

    if(pos == word.size())
    return node->isEnd;
    
    char c = word[pos];
    if(c == '.'){
        for(int i = 0;i<26;i++){
            if(dfs(word,pos+1,node->child[i]))
            return true;
        }
        return false;
    }   
    return dfs(word,pos+1,node->child[c-'a']);
     }
    
    bool search(string word) {
        return dfs(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */