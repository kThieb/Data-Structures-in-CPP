#include<bits/stdc++.h>
using namespace std;

class Trie {
    class Node {
        public:
        bool is_word;
        unordered_map<char, Node*> children;

        Node() {
            is_word = false;
        }
    };

    Node *root;

    void add_word_helper(string word, int i, Node* cur) {
        if (i == word.size()) {
            cur->is_word = true;
            return;
        }
        else if (!cur->children.count(word[i])) {
            Node *child = new Node();
            cur->children[word[i]] = child;
        }
        add_word_helper(word, i + 1, cur->children[word[i]]);
    }

    bool search_word_helper(string word, int i, Node *cur) {
        if (i == word.size() && cur->is_word) return true;
        else if (i == word.size()) return false;
        else {
            if (!cur->children.count(word[i])) return false;
            else return search_word_helper(word, i + 1, cur->children[word[i]]);
        } 
    }

    bool search_prefix_helper(string word, int i, Node *cur) {
        if (word.size() == i) return true;
        else {
            if (!cur->children.count(word[i])) return false;
            else return search_prefix_helper(word, i + 1, cur->children[word[i]]);
        }
    }

    public:
    Trie() {
        root = new Node();
    }

    void add_word(string word) {
        add_word_helper(word, 0, root);
    }

    bool search_word(string word) {
        return search_word_helper(word, 0, root);
    }

    bool search_prefix(string prefix) {
        return search_prefix_helper(prefix, 0, root);
    }
};


int main() {
    Trie trie;
    trie.add_word("apple");
    cout << trie.search_word("apple") << endl;
    cout << trie.search_word("app") << endl;
    cout << trie.search_prefix("app") << endl;
    trie.add_word("app");
    cout << trie.search_word("app") << endl;
    return 0;
}