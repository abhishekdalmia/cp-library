class TrieNode {
    public:
        bool found = false;
        vector <TrieNode*> children = vector <TrieNode*>(26, nullptr);
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currNode = root;
        for (auto ch: word)
        {
            int ind = ch-'a';
            if (currNode->children[ind] == nullptr) {
                currNode->children[ind] = new TrieNode;
            }
            currNode = currNode->children[ind];
        }
        currNode->found = true;
    }
    
    bool search(string word) {
        TrieNode* currNode = root;
        for (auto ch: word) {
            int ind = ch-'a';;
            if (currNode->children[ind] == nullptr) {
                return false;
            }
            currNode = currNode->children[ind];
        }
        return currNode->found;
    }
    
    bool startsWith(string prefix) {
        TrieNode* currNode = root;
        for (auto ch: prefix) {
            int ind = ch-'a';
            if (currNode->children[ind] == nullptr) {
                return false;
            }
            currNode = currNode->children[ind];
        }
        return true;
    }
};
