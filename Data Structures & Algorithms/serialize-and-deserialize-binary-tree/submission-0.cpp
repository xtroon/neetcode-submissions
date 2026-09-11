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
        if (!root) return "";

        string res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                res += "null,";
                continue;
            }

            res += to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return nullptr;

        //storing in vector
        vector<string> s;
        string curr = "";

        for(int i=0; i<data.size(); i++){
            if(data[i] == ','){
                s.push_back(curr);
                curr = "";
            }
            else curr += data[i];
        }

        TreeNode* root = new TreeNode(stoi(s[0]));

        queue<TreeNode*> q;
        q.push(root);
        int i =1;

        while(!q.empty() && i<s.size()){
            TreeNode* node = q.front(); 
            q.pop();

            //left
            if(s[i] != "null"){
                node->left = new TreeNode(stoi(s[i]));
                q.push(node->left);
            }
            i++;

            if(i<s.size() && s[i] != "null"){
                node->right = new TreeNode(stoi(s[i]));
                q.push(node->right);
            }
            i++;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));