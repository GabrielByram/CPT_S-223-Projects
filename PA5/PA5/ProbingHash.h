#ifndef __PROBING_HASH_H
#define __PROBING_HASH_H

#include <vector>
#include <stdexcept>

#include "Hash.h"

using std::vector;
using std::pair;

template<typename K, typename V>
class ProbingHash : public Hash<K,V> { // derived from Hash

private:
    int tableSize;
    int numElements;
    vector<pair<pair<K,V>, EntryState>> table;

public:
    ProbingHash(int n = 11) {
        tableSize = n;
        numElements = 0;

        //Resizes the table
        table.resize(tableSize);
    }

    //Destructor - deallocates memory - Shira
    ~ProbingHash() {
        table.clear();
        
    }

private:
    //Determine location to insert through hash function - Gabriel
    int hash(const K& key) {
        return key % tableSize;
    }

    //Finds prime number that is in next sequential order after n
    int findNextPrime(int n)
    {
        while (!isPrime(n))
        {
            n++;
        }
        return n;
    }


    // returns true if the number passed in is prime
    // returns false otherwise
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

public:
    //Checks if the hash table (vector) is empty - Shira
    bool empty() {
        return table.empty();
    }

    //Returns the size of the table - Shira
    int size() {
        return tableSize;
    }

    // Returns the value with key k - Gabriel
    V& at(const K& key) {
        // Iterate through hash table starting from where the key would be placed
        // Returns the value for the corresponding key if found
        int newIndex;
        for (int i = 0; i < tableSize; i++) {
            newIndex = (hash(key) + i) % tableSize;
            if (table[newIndex].first.first == key)
                return table[newIndex].first.second;
        }
        //throw std::out_of_range("Key not in hash");
        std::cout << "Not found!\n";
    }

     //Returns the value at a certain key - Shira
    V& operator[](const K& key) { 
        return at(key);
    }

    //Returns the number of elements in table with the specified key - Gabriel
    int count(const K& key) {
        int numberFound = 0, newIndex;

        // iterates through table and increments numberFound if key is found
        for(int i = 0; i < tableSize; i++) {
            newIndex = (hash(key) + i) % tableSize;
            if (table[newIndex].first.first == key)
                numberFound++;
        }
        return numberFound;
    }

    // Returns the load factor of the hash - Shira
    float load_factor(){
        return (numElements / (float)tableSize);
    }

    // inserts a pair into the hash table in the correct position
    // calls rehash if needed - Gabriel
    void insert(const std::pair<K, V> & firstPair) {
        // Determine location to insert through hash function
        int index = hash(firstPair.first);

        // iterate through table until we find the correct index to place our key into
        // Resolve conflicts through linear probing
        while (table[index].second != EMPTY && table[index].second != DELETED)
            index = (index + 1) % tableSize;

        // make new pair to hold key, value, and state
        pair<pair<K, V>, EntryState> fullPair = {firstPair, VALID};

        // insert our new pair with key, value, and state into the hash table
        table[index] = fullPair;
        numElements++;

        // call rehash if load factor is above 0.75
        if (load_factor() > 0.75)
            rehash();
    }

    //Creates a new pair and then places it in the table - Shira
    void emplace(K key, V value) {
        pair<K, V> newPair;
        newPair.first = key;
        newPair.second = value;
        insert(newPair);
    }

    // Removes all (if any) entries with key k through lazy deletion - Gabriel
    void erase(const K& key) {
        // Iterate through hash table starting from where the key would be placed
        // Returns the value for the corresponding key if found
        int newIndex;
        for (int i = 0; i < tableSize; i++) {
            newIndex = (hash(key) + i) % tableSize;
            if (table[newIndex].first.first == key && table[newIndex].second == VALID) {
                table[newIndex].second = DELETED;
                numElements--;
            }
        }
    }

    // Empties the hash - Gabriel
    void clear() {
        table.clear();
    }

    // Returns the number of buckets allocated (size of the hash vector) - Gabriel
    int bucket_count() {
        return tableSize;
    }

    // Returns the number of elements in bucket n (0 or 1) - Gabriel
    int bucket_size(int n) {
        if (table[n].second == 2)
            return 0;
        else
            return table[n].second;
    }

    // Returns the bucket number of key (or throws std::out_of_range if key not found) - Gabriel
    int bucket(const K& key) {
        // Iterate through hash table starting from where the key would be placed
        // Returns the value for the corresponding key if found
        for (int i = 0; i < tableSize; i++) {
            if (table[(hash(key) + i) % tableSize].first.first == key)
                return (hash(key) + i) % tableSize;
        }
        // throws out of bounds exception if key not found
        //throw std::out_of_range("Key not in hash");
        std::cout << "Not Found!\n";
        
    }

    // Resizes the hash to contain at least n buckets - Gabriel
    void rehash() {
        // save old value of table size
        int oldTableSize = tableSize;

        // doubles hash table size then keeps increasing until next prime number is found
        this->tableSize *= 2;
        while (!isPrime(tableSize))
            this->tableSize++;

        // create copy of table to read into new larger table
        vector<pair<pair<K, V>, EntryState>> tableCopy;
        tableCopy.resize(oldTableSize);

        for (int i = 0; i < oldTableSize; i++) {
            tableCopy[i] = table[i];
        }

        // clear table and resize memory for new table size
        table.clear();
        table.resize(tableSize);

        // re-insert all values back into hash table in correct new places
        for (int i = 0; i < oldTableSize; i++) {
            if (tableCopy[i].second == VALID)
                this->insert(tableCopy[i].first);
        }

        // delete our table copy
        tableCopy.clear();

        //delete newTable;
    }

    // Resizes to next prime starting from n and going up - Gabriel
    void rehash(int n) {
        // save old value of table size
        int oldTableSize = tableSize;

        // increases hash size to n then keeps increasing until next prime number is found
        tableSize = n;
        while (!isPrime(tableSize))
            tableSize++;

        // create new table
        vector<pair<pair<K, V>, EntryState>> newTable;

        newTable.resize(tableSize);

        // re-insert all values back into hash table in correct new places
        for (int i = 0; i < oldTableSize; i++) {
            if (table[i].second == 1)
                newTable[hash(table[i].first.first)] = table[i];
        }

        // delete our old table 
        table.clear();
        // also call delete?

        // set our hash table to be the new table
        table = newTable;
    }

};
#endif //__PROBING_HASH_H