#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <list>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

static const unsigned int max_prime = 1301081;

namespace cop4530{

    template <typename K, typename V>
    class HashTable{

    public:
        HashTable(size_t size = 101);
        ~HashTable();
        bool contains(const K & k);
        bool match(const pair<K, V> & kv);
        bool insert(const pair<K, V> & kv);
        bool insert(pair<K, V> && kv);
        bool remove(const K & k);
        void clear();
        bool load(const char *filename);
        void dump();
        bool write_to_file(const char *filename);

        size_t size();

    private:
        void makeEmpty();
        void rehash();
        size_t myhash(const K &k);
        unsigned long prime_below(unsigned long n);
        void setPrimes(std::vector<unsigned long>& vprimes);
        vector<list<pair<K, V>>> hTable;

        size_t vector_size;
    };

#include "hashtable.hpp"

} // end of namespace 4530

#endif //HASHTABLE_H