/*
 *  Separate chaining hashtable
 */

#ifndef __CHAINING_HASH_H
#define __CHAINING_HASH_H

 // Standard library includes
#include <iostream>
#include <vector>
#include <list>
#include <stdexcept>

// Custom project includes
#include "Hash.h"

// Namespaces to include
using std::vector;
using std::list;
using std::pair;

using std::cout;
using std::endl;

//
// Separate chaining based hash table - derived from Hash
//
template<typename K, typename V>
class ChainingHash : public Hash<K, V> {
private:
    int tableSize;
    int bucketCount;
    int numElements;
    vector<list<pair<K, V>>> table;

public:
    ChainingHash(int n = 11) {
        bucketCount = 0;
        numElements = 0;
        tableSize = n;
        table.resize(n);
    }

    //Destructor, clears table - Gabriel
    ~ChainingHash() {
        table.clear();
    }

    //Returns true - Gabriel
    bool empty() {
        return table.empty();
    }

    //Returns the table size - Gabriel
    int size() {
        return tableSize;
    }

    //Determine location to insert through hash function - Shira
    int getHashIdx(K key) {
        return (key) % tableSize;
    }

    //Returns the value at a certain key - Gabriel
    V& at(const K& key) {

        list<pair <K, V>> pList = table[getHashIdx(key)];

        for (auto it = pList.begin(); it != pList.end(); it++) {
            if (it->first == key) {
                return(it->second);
            }
        }
        //throw std::out_of_range("Key not in hash");
        std::cout << "Not found!\n";
    }

    //Returns the value at a certain key - Shira
    V& operator[](const K& key) {
        return at(key);
    }

    //Returns 1 if the key appears else return 0 - Shira
    int count(const K& key) {

        list<pair <K, V>> pList = table[getHashIdx(key)];

        for (auto it = pList.begin(); it != pList.end(); it++) {
            if (it->first == key) return 1;
        }
        return 0;
    }

    //Returns the number of buckets - Shira
    int bucket_count() {
        return bucketCount;
    }

    //Returns the number of elements divided by table size - Shira
    float load_factor() {
        return (numElements / ((float)tableSize));
    }

    //Adds pair to hash table - Shira
    void insert(const std::pair<K, V>& pair) {
        //The key already exist
        if (count(pair.first) == 1) {
            return;
        }
        //Checks if table needs to be rehashed
        float loadFactor = load_factor();
        if (loadFactor >= 0.75) {
            rehash();
        }
        numElements++;
        int idx = getHashIdx(pair.first);
        if (table[idx].empty()) {
            bucketCount++;
        }
        table[idx].push_back(pair);
    }

    //Makes a new pair and then inserts to the table - Gabriel
    void emplace(K key, V value) {
        pair<K, V> newPair(key, value);
        insert(newPair);
    }


    //Erases element with the given key - Shira
    void erase(const K& key) {
        int idx = getHashIdx(key);
        list<pair <K, V>> pList = table[idx];

        for (auto it = pList.begin(); it != pList.end(); it++) {
            if (it->first == key) {
                it = pList.erase(it);
                numElements--;
                if (pList.empty()) {
                    bucketCount--;
                }
                return;
            }
        }
    }

    //Clear the whole table - Shira
    void clear() {
        table.clear();
    }

    //Gets the bucket size - Shira
    int bucket_size(int n) {
        list<pair <K, V>> pList = table[getHashIdx(n)];
        return pList.size();
    }

    //Returns the bucket where the key is located - Shira
    int bucket(const K& key) {
        return getHashIdx(key);
    }

    //We are not using this function 
    void rehash(int n) {
        return;
    }

    //Makes a new hash table of the next prime number after doubling the old table size - Shira
    void rehash() {
        int originalTableSize = tableSize;
        tableSize = findNextPrime(tableSize * 2); //Gets the new table size
        table.resize(tableSize);

        pair<K, V> val;

        //Look for values require re-hashing (keys with value greater than old table size)
        for (int i = 0; i < originalTableSize; i++) {
            for (auto it = table[i].begin(); it != table[i].end(); it++) {
                val = *it;
                if (val.first >= originalTableSize) {
                    insert(val); 
                    numElements--;
                    it = table[i].erase(it);
                    if (table[i].empty()) {
                        bucketCount--;
                    }
                }
            }
        }
    }



private:
    int isPrime(int n)
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }



    int hash(const K& key) {
        return 0;
    }

};

#endif //__CHAINING_HASH_H