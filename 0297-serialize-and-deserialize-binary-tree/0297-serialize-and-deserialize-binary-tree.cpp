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
        if(!root) return "N,";
        return to_string(root->val)+ ","+serialize(root->left) + serialize(root->right);

    }

    TreeNode* buildTree(queue<string>&tokens){
        string token = tokens.front();
        tokens.pop();

        if(token == "N") return nullptr;

        TreeNode* root= new TreeNode(stoi(token));
        root->left= buildTree(tokens);
        root->right  = buildTree(tokens);
        return root;
        

        

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       queue<string>tokens;
       string token;

       for(char c:data){
        if(c == ','){
            tokens.push(token);
            token ="";

        }
        else{
            token +=c;
        }
       }
       return buildTree(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));