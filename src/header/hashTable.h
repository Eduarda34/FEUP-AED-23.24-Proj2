
#ifndef AIRPORT_HASHTABLE_H
#define AIRPORT_HASHTABLE_H

#include <iostream>
#include <list>
#include <vector>
#include <functional>

template<typename K, typename V>
struct KeyValuePair {
    K key;
    V value;
};

template<typename K, typename V>
class HashTable {
private:
    std::vector<std::list<KeyValuePair<K, V>>> table;
    size_t size;

    size_t hashFunction(const K& key) const {
        return std::hash<K>{}(key) % size;
    }

public:
    HashTable(size_t initialSize = 3037) : size(initialSize), table(initialSize) {}


    void insert(const K& key, const V& value) {
        size_t index = hashFunction(key);
        table[index].push_back({key, value});
    }

    V get(const K& key) const {
        size_t index = hashFunction(key);
        for (const auto& pair : table[index]) {
            if (pair.key == key) {
                return pair.value;
            }
        }
    }

    void remove(const K& key) {
        size_t index = hashFunction(key);
        table[index].remove_if([&](const KeyValuePair<K, V>& pair) { return pair.key == key; });
    }


};


#endif //AIRPORT_HASHTABLE_H
