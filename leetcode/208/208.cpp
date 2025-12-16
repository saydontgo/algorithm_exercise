#include <iostream>
#include <map>
#include <memory>
using namespace std;
struct TrieNode {
    map<char, shared_ptr<TrieNode>> children;
    char val;
    bool word;
    TrieNode(char c, bool w) : val(c), word(w) {}
    TrieNode(char c) : val(c), word(false) {}
    TrieNode() : val('#'), word(false) {}
};
class Trie {
public:
    Trie() {
        root_ = make_shared<TrieNode>();
    }
    
    void insert(string word) {
        auto cursor = root_;
        int index = 0;
        int size = word.size();

        while (cursor != nullptr) {
            auto it = cursor->children.find(word[index]);
            if (it == cursor->children.end()) {
                cursor->children[word[index]] = make_shared<TrieNode>(word[index]);
                cursor = cursor->children[word[index]];
            } else {
                cursor = it->second;
            }
            index++;
            if (index == size) {
                cursor->word = true;
                break;
            }
        }
        
        while (index < size) {
            cursor->children[word[index]] = make_shared<TrieNode>(word[index]);
            cursor = cursor->children[word[index]];
            index++;
        }
        cursor->word = true;
    }
    
    bool search(string word) {
        auto cursor = root_;
        int index = 0;
        int size = word.size();

        while (cursor != nullptr) {
            auto it = cursor->children.find(word[index]);
            if (it == cursor->children.end()) {
                return false;
            }

            cursor = it->second;
            index++;
            if (index == size) {
                return cursor->word;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        auto cursor = root_;
        int index = 0;
        int size = prefix.size();

        while (cursor != nullptr) {
            auto it = cursor->children.find(prefix[index]);
            if (it == cursor->children.end()) {
                return false;
            }

            cursor = it->second;
            index++;
            if (index == size) {
                return true;
            }
        }
        return false;
    }
private:
    shared_ptr<TrieNode> root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */