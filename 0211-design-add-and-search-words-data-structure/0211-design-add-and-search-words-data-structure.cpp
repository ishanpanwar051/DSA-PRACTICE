class Node{
    public:
    char data;
    bool terminal;
    unordered_map<char,Node*>children;

    Node(char ch)
    {
        data=ch;
        terminal =false;

    }
};

class WordDictionary {
public:
Node* root;

    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
        Node* curr =root;

        for(char ch: word){
            if(curr->children.count(ch) == 0){
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->terminal = true;
    }
    bool dfs(Node* curr,string&word,int idx){
if(idx == word.size()) return curr->terminal;

char ch =word[idx];

if(ch != '.'){
    if(curr->children.count(ch) == 0)return false;
    return dfs(curr->children[ch],word,idx+1);
}
 for(auto &child : curr->children) {
        if(dfs(child.second, word, idx + 1))
            return true;
    }

    return false;
}
    
    
    
    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */