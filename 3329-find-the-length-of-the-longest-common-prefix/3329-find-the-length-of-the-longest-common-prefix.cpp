class TrieNode {
public:
    TrieNode* children[10];
    bool flag;
    
    TrieNode() {
        for (int i = 0; i < 10; ++i) {
            children[i] = nullptr;
        }
        flag = false;
    }
};

class Trie {
private:
    TrieNode* root;
    
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(const string& numb) {
        TrieNode* node = root;
        for (char ch : numb) {
            int idx = ch - '0';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->flag = true;
    }
    int getLongestCommonPrefix(const string& numb) {
        TrieNode* node = root;
        int commonLength = 0;
        
        for (char ch : numb) {
            int idx = ch - '0';
            if (node->children[idx]) {
                commonLength++;
                node = node->children[idx];
            } else {
                break;
            }
        }
        return commonLength;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie trie;
        for (int num : arr2) {
            trie.insert(to_string(num));
        }
        
        int mxl = 0;
        for (int num : arr1) {
            string numStr = to_string(num);
            int commonPrefixLength = trie.getLongestCommonPrefix(numStr);
            mxl = max(mxl, commonPrefixLength);
        }
        
        return mxl;
    }
};
