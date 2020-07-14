#include<bits/stdc++.h>
using namespace std;

// Implementation using an array for lowercase characters
class Trie {
    Trie *next[26]= {};
    bool is_word = false;
    
public:
    void insert(string word) {
        Trie *cur = this;
        for (char c: word) {
            c -= 'a';
            if (!cur->next[c]) cur->next[c] = new Trie();
            cur = cur->next[c];
        }
        cur->is_word = true;
    }

    bool search_word(string word) {
        Trie *cur = this;
        for (char c: word) {
            c -= 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return cur->is_word;
    }

    bool search_prefix(string prefix) {
        Trie *cur = this;
        for (char c: prefix) {
            c -= 'a';
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return true;
    }
};

// Implementation with an unordered_map for more characters

class Trie_map {
    unordered_map<char, Trie_map*> next;
    bool is_word = false;
public:

    Trie_map() {}

    void insert(string word) {
        Trie_map *cur = this;
        for (char c: word) {
            if (!cur->next[c]) cur->next[c] = new Trie_map();
            cur = cur->next[c];
        }
        cur->is_word = true;
    }

    bool search_word(string word) {
        Trie_map *cur = this;
        for (char c: word) {
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return cur->is_word;
    }

    bool search_prefix(string prefix) {
        Trie_map *cur = this;
        for (char c: prefix) {
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return true;
    }
};


// recursive and not optimal implementation
class Trie_recursive {
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
    Trie_recursive() {
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
    trie.insert("apple");
    cout << trie.search_word("apple") << endl;
    cout << trie.search_word("app") << endl;
    cout << trie.search_prefix("app") << endl;
    trie.insert("app");
    cout << trie.search_word("app") << endl;
    return 0;
}