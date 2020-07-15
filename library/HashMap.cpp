#include<bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 10000

template <typename K, typename V>
class Node {
    K key;
    V val;
    Node *next;

public:
    Node(const K &key, const V &val): key(key), val(val), next(NULL) {}

    K get_key() const {
        return key;
    }

    V get_val() const {
        return val;
    }

    void set_val(V val) {
        this->val = val;
    }

    Node *get_next() const {
        return this->next;
    }

    void set_next(Node *nextNode) {
        this->next = next;
    }
};

template<typename K>
struct KeyHash {
    unsigned long operator()(const K &key) {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

template<typename K, typename V, typename F=KeyHash<K>>
class HashMap {
    int table_size = 10000;
    F hash_func;
    vector<Node<K, V>*> table;

public:
    HashMap() {
        table = vector<Node<K, V>*>(table_size);
    }

    HashMap(int table_size): table_size(table_size) {
        table = vector<Node<K, V>*>(table_size);
    }
    
    bool get(const K &key, V &val) {
        unsigned long hash_value = hash_func(key);
        Node<K, V> *entry = table[hash_value];
        while (entry) {
            if (entry->get_key() == key) 
                val = entry->get_val();
                return true;
            entry->get_next();
        }
        return false;
    }

    void put(const K &key, const V &val) {
        unsigned long hash_value = hash_func(key);
        Node<K, V> *prev = nullptr;
        Node<K, V> *entry = table[hash_value];

        while (entry && entry->get_key() != key) {
            prev = entry;
            entry = entry->get_next();
        }

        if (!entry) {
            entry = new Node<K, V>(key, val);
            if (!prev) table[hash_value] = entry;
            else prev->set_next(entry);
        }
        else entry->set_val(val);
    }

    void remove(const K &key) {
        unsigned long hash_value = hash_func(key);
        Node<K, V> *entry = table[hash_value];
        Node<K, V> *prev = nullptr;

        while (entry && entry->get_key() != key) {
            prev = entry;
            entry = entry->get_next();
        }

        if (!entry) return;
        else {
            if (!prev) table[hash_value] = nullptr;
            else prev->set_next(entry->get_next());            
        }
    }
};

int main() {
    struct MyKeyHash {
        unsigned long operator()(const int& k) const {
            return k % 10;
        }
    };
    HashMap<int, string, MyKeyHash> hmap;
    hmap.put(1, "val1");
    hmap.put(2, "val2");
    hmap.put(3, "val3");

    string value;
    hmap.get(2, value);
    cout << endl << value << endl;
    bool res = hmap.get(3, value);
    if (res)
        cout << value << endl;
    hmap.remove(3);
    res = hmap.get(3, value);
    if (res)
        cout << value << endl;
    else 
        cout << "No value with key = " << 3 << "." << endl;
    return 0;
}