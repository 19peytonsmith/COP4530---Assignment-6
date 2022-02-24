//
// class HashTable public member function definitions
//

// *****************************************************************
// * Function Name:  HashTable()                                   *
// * Description:  Constructor that allocates                      *
// * prime_below(size) elements in hash table                      *
// * Parameter Description:  size_t size, used to calculate        *
// * allocated space in hash table                                 *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  No References                                    *
// *****************************************************************
template<typename K, typename V>
HashTable<K, V>::HashTable(size_t size) {
    // Sets vector_size to 0 & allocates prime_below(size)
    // number of elements in hash table vector
    vector_size = 0;
    hTable.resize(prime_below(size));
}

// *****************************************************************
// * Function Name:  ~HashTable()                                  *
// * Description:  Destructor that deletes all elements in table   *
// * Parameter Description: No parameters                          *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  No References                                    *
// *****************************************************************
template<typename K, typename V>
HashTable<K, V>::~HashTable() {
    // Deletes all elements in hash table
    clear();
}

// *****************************************************************
// * Function Name:  contains()                                    *
// * Description:  Checks if key parameter is in table             *
// * Parameter Description:  k, key value                          *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::contains(const K &k) {
    // Create vector list at myhash(k) index
    auto & whichList = hTable[myhash(k)];

    // Loop through vector list
    for(auto & thisList : whichList) {
        // If the key matches with the parameter, return true
        if (thisList.first == k) {
            return true;
        }
    }
    return false; // Once here, then key does not match, return false
}

// *****************************************************************
// * Function Name:  match()                                       *
// * Description:  Checks if key value pair is in table            *
// * Parameter Description:  kv, key-value object pair             *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::match(const pair<K, V> &kv) {
    // Create vector list at myhash(k) index
    auto & whichList = hTable[myhash(kv.first)];

    // Loop through vector list
    for(auto & thisList : whichList){
        // If key matches with key parameter...
        if(thisList.first == kv.first){
            // If value matches with value parameter
            if(thisList.second == kv.second){
                return true;
            }
        }
    }
    return false;
}

// *****************************************************************
// * Function Name:  insert()                                      *
// * Description:  Inserts key value pair into hash table          *
// * Parameter Description:  kv, key-value object pair             *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::insert(const pair<K, V> &kv) {
    // Create vector list at myhash(k) index
   auto & whichList = hTable[myhash(kv.first)];

   // Loop through vector list
    for(auto & thisList : whichList){
        // If key matches with key parameter
        if(thisList.first == kv.first){
            // If value matches with value parameter
            if(thisList.second == kv.second){
                return false;
            }else{ // If key matches but values are different, update value
                thisList.second = kv.second;
                return true;
            }
        }
    }
    whichList.push_back(kv); // Push kv object to the vector list

    // If new size is out of bounds, rehash
    if(++vector_size > hTable.size()){
        rehash();
    }
    return true;
}

// *****************************************************************
// * Function Name:  insert()                                      *
// * Description:  Inserts keyvalue pair into hash table - move ver*
// * Parameter Description:  kv, key-value object pair             *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::insert(pair<K, V> &&kv) {
    // Create vector list at myhash(k) index
    auto & whichList = hTable[myhash(kv.first)];

    // Loop through vector list
    for(auto & thisList : whichList){
        // If key matches with key parameter
        if(thisList.first == kv.first){
            // If value matches with value parameter
            if(thisList.second == kv.second){
                return false;
            }else{ // If key matches but values are different, update value
                swap(thisList.second, kv.second);
                return true;
            }
        }
    }
    whichList.push_back(move(kv)); // Push kv object to the vector list

    // If new size is out of bounds, rehash
    if(++vector_size > hTable.size()){
        rehash();
    }
    return true;
}

// *****************************************************************
// * Function Name:  remove()                                      *
// * Description:  Removes kv pair based on key parameter          *
// * Parameter Description:  k - key value                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::remove(const K &k) {
    // Create vector list at myhash(k)
    auto & whichList = hTable[myhash(k)];
    int index = 0;

    // Loop through vector list
    for(auto & thisList : whichList){
        // If key matches parameter...
        if(thisList.first == k){
            // Advance the iterator index times, erase the value then decrement size
            auto itr = whichList.begin();
            advance(itr, index);
            whichList.erase(itr);
            --vector_size;
            return true;
        }
        index++; // Increment index each time
    }
    return false;
}

// *****************************************************************
// * Function Name:  clear()                                       *
// * Description:  Deletes all elements in hash table              *
// * Parameter Description: No parameters                          *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
template<typename K, typename V>
void HashTable<K, V>::clear() {
    makeEmpty(); // Delete all elements in hash table
}

// *****************************************************************
// * Function Name:  load()                                        *
// * Description:  Loads data from file into hash table            *
// * Parameter Description:  filename - file used to import data   *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Lecture Slides on Canvas                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::load(const char *filename) {
    // Open file from filename parameter
    ifstream input;
    input.open(filename);
    K key;
    V value;
    // If could not open, return false
    if(!input) {
        return false;
    }
    // Loop the file until empty
    while(!input.eof()){
        // Insert each key value pair into list
        input >> key >> value;
        insert(make_pair(key, value));
    }
    input.close(); // Close file
    return true;
}

// *****************************************************************
// * Function Name:  dump()                                        *
// * Description:  Displays all hash table entries                 *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Lecture Slides on Canvas                         *
// *****************************************************************
template<typename K, typename V>
void HashTable<K, V>::dump() {
    // Loop through hash table
    for(int i = 0; i < hTable.size(); i++){
        cout << "hTable[" << i << "]: ";
        // Loop through vector list at each bucket
        for(auto iterator = hTable[i].begin(); iterator != hTable[i].end(); ++iterator){
            // If iterator is different from beginning element, separate new value with ':'
            if(iterator != hTable[i].begin()) {
                cout << ":";
            }
            // Display the vector elements
            cout << iterator->first << " " << iterator->second;
        }
        cout << endl;
    }
}

// *****************************************************************
// * Function Name:  write_to_file()                               *
// * Description:  Writes hash table entries to file               *
// * Parameter Description:  filename - file used to export data   *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Lecture Slides on Canvas                         *
// *****************************************************************
template<typename K, typename V>
bool HashTable<K, V>::write_to_file(const char *filename) {
    // Open file from filename parameter
    ofstream output;
    output.open(filename);
    K key;
    V value;

    // If could not open, return false
    if(!output) {
        return false;
    }
    // Loop through hash table
    for(int i = 0; i < hTable.size(); i++){
        // Create vector list at each bucket
        auto & whichList = hTable[i];
        // Set iterator to be the beginning of the list
        auto iterator = whichList.begin();

        // As long as vector list is not empty...
        if(!whichList.empty()){
            // Write the vector element to the file
            output << iterator->first << " " << iterator->second << endl;
            while(++iterator != whichList.end()){
                output << iterator->first << " " << iterator->second << endl;
            }
        }
    }
    output.close(); // Close file
    return true;
}

// *****************************************************************
// * Function Name:  size()                                        *
// * Description:  Returns size of hash table                      *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
template<typename K, typename V>
size_t HashTable<K, V>::size() {
    return vector_size;
}

//
// class HashTable private member function definitions
//


// *****************************************************************
// * Function Name:  makeEmpty()                                   *
// * Description:  Deletes all elements in hash table              *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
void HashTable<K, V>::makeEmpty() {
    // Loop through hash table and delete each element
    for(auto & element : hTable){
        element.clear();
    }
    vector_size = 0; // Set size to 0
}

// *****************************************************************
// * Function Name:  rehash()                                      *
// * Description:  Rehashes elements in hash table                 *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
void HashTable<K, V>::rehash() {
    // Copy the old list
    auto oldLists = hTable;

    // Resize the hash table 
    hTable.resize(prime_below(2*hTable.size()));
    // Loop through hash table and delete each element
    for(auto & element : hTable){
        hTable.clear();
    }
    vector_size = 0; // Set size to 0
    
    // Loop through hash table copy
    for(auto & element : oldLists){
        // Loop through vector list at each bucket
        for(auto & x : element){
            // Insert each element into the hash table
            insert(move(x));
        }
    }
}

// *****************************************************************
// * Function Name:  myhash()                                      *
// * Description:  Encrypts k parameters to output an index        *
// * Parameter Description:  k - key used to encrypt               *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Textbook                                         *
// *****************************************************************
template<typename K, typename V>
size_t HashTable<K, V>::myhash(const K &k) {
    unsigned int hashVal = 0;
    // Hash the input parameter
    for(auto ch : k){
        hashVal = 37 * hashVal + ch;
    }
    return hashVal % hTable.size(); // Take modulo of hashVal with hash table size
}

// *****************************************************************
// * Function Name:  prime_below()                                 *
// * Description:  Calculates all primes below parameter n         *
// * Parameter Description:  n - value used in algorithm           *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Provided function from assignment write-up       *
// *****************************************************************
template<typename K, typename V>
unsigned long HashTable<K, V>::prime_below(unsigned long n) {
    if (n > max_prime)
    {
        std::cerr << "** input too large for prime_below()\n";
        return 0;
    }
    if (n == max_prime)
    {
        return max_prime;
    }
    if (n <= 1)
    {
        std::cerr << "** input too small \n";
        return 0;
    }

    // now: 2 <= n < max_prime
    std::vector <unsigned long> v (n+1);
    setPrimes(v);
    while (n > 2)
    {
        if (v[n] == 1)
            return n;
        --n;
    }

    return 2;
}

// *****************************************************************
// * Function Name:  setPrimes()                                   *
// * Description:  Used in prime_below function to initialize array*
// * Parameter Description:  vprimes - vector of primes            *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Provided function from assignment write-up       *
// *****************************************************************
template<typename K, typename V>
void HashTable<K, V>::setPrimes(std::vector<unsigned long> &vprimes) {
    int i = 0;
    int j = 0;

    vprimes[0] = 0;
    vprimes[1] = 0;
    int n = vprimes.capacity();

    for (i = 2; i < n; ++i)
        vprimes[i] = 1;

    for( i = 2; i*i < n; ++i)
    {
        if (vprimes[i] == 1)
            for(j = i + i ; j < n; j += i)
                vprimes[j] = 0;
    }
}