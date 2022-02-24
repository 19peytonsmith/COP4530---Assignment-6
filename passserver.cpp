#include "passserver.h"

// *****************************************************************
// * Function Name:  PassServer()                                  *
// * Description:  Constructor that creates hash table with size   *
// * parameter                                                     *
// * Parameter Description:  size - allocates size # of elements   *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
cop4530::PassServer::PassServer(size_t size) : HashTable(size) {
}

// *****************************************************************
// * Function Name:  ~PassServer()                                 *
// * Description:  Destructor that deletes all entries in          *
// * hash table                                                    *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
cop4530::PassServer::~PassServer() {
    HashTable::clear(); // Clear all entries in Hash Table
}

// *****************************************************************
// * Function Name:  load()                                        *
// * Description:  Loads data from file parameters into hash table *
// * Parameter Description:  filename - file used to import data   *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::load(const char *filename) {
    return HashTable::load(filename); // Load data from filename parameter
}

// *****************************************************************
// * Function Name:  addUser()                                     *
// * Description:  Adds username/password pair into hash table     *
// * Parameter Description: kv - key-value object pair             *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::addUser(pair<string, string> &kv) {
    // Create an object pair using the parameters and insert it into the Hash Table
    pair<string,string> object = make_pair(kv.first,encrypt(kv.second));
    return HashTable::insert(object);
}

// *****************************************************************
// * Function Name:  addUser()                                     *
// * Description:  Adds username/password pair into hash table -   *
// * move version                                                  *
// * Parameter Description: kv - key-value object pair             *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::addUser(pair<string, string> &&kv) {
    // Create an object pair using the parameters and insert it into the Hash Table
    pair<string,string> object = move(make_pair(kv.first,encrypt(kv.second)));
    return HashTable::insert(object);
}

// *****************************************************************
// * Function Name:  removeUser()                                  *
// * Description:  Removes user based on username parameter        *
// * Parameter Description: k - username                           *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::removeUser(const string &k) {
    return HashTable::remove(k); // Remove user from k parameter
}

// *****************************************************************
// * Function Name:  changePassword()                              *
// * Description:  Changes password from existing key-value pair   *
// * using newpassword parameter                                   *
// * Parameter Description: p - existing username/password pair,   *
// * newpassword - new password used to change                     *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::changePassword(const pair<string, string> &p, const string &newpassword) {
    // Checks to see if the username is valid
    if(find(p.first)){
        // Create object pair from first parameter
        pair<string, string> oldobject = make_pair(p.first, encrypt(p.second));
        // If current username/password pair match up...
        if(HashTable<string, string>::match(oldobject)){
            // Create new object pair using newpassword
            pair<string, string> object = make_pair(p.first, encrypt(newpassword));
            // If newpassword == oldpassword, return false
            if(HashTable::match(object)){
                return false;
            }else{ // Else insert the new object into the Hash Table
                return HashTable::insert(object);
            }
        }else{ // If the current username/password pair does not match, return false
            return false;
        }
    }else{ // If username is not found, return false
        return false;
    }
}

// *****************************************************************
// * Function Name:  find()                                        *
// * Description:  Finds username based on user parameter          *
// * Parameter Description: user - username used to find           *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::find(const string &user) {
    return HashTable::contains(user); // Check if user parameter is in the Hash Table
}

// *****************************************************************
// * Function Name:  dump()                                        *
// * Description:  Displays all entries in hash table              *
// * Parameter Description: No parameters                          *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
void cop4530::PassServer::dump() {
    HashTable::dump(); // Displays all entries in hash table
}

// *****************************************************************
// * Function Name:  size()                                        *
// * Description:  Returns hash table size                         *
// * Parameter Description: No parameters                          *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
size_t cop4530::PassServer::size() {
    return HashTable::size(); // Returns hash table size
}

// *****************************************************************
// * Function Name:  write_to_file()                               *
// * Description:  Writes data to file parameters from hash table  *
// * Parameter Description:  filename - file used to export data   *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
bool cop4530::PassServer::write_to_file(const char *filename) {
    return HashTable::write_to_file(filename); // Write to filename parameter
}

//
// class PassServer private member function
//


// ********************************************************************************
// * Function Name:  encrypt()                                                    *
// * Description:  Encodes str parameter to be used in hash table                 *
// * Parameter Description:  str - password used to encrypt                       *
// * Date:  02/21/2022                                                            *
// * Author:   Peyton J. Smith                                                    *
// * References:  Geeks-for-geeks website used to convert                         *
// * string input to character array and converting back to string                *
// * URL: https://www.geeksforgeeks.org/convert-string-char-array-cpp/            *
// * URL: https://www.geeksforgeeks.org/convert-character-array-to-string-in-c/   *
// ********************************************************************************
string cop4530::PassServer::encrypt(const string &str) {
    // Declare input/output arrays and the length of the str parameter
    int n = str.length();
    char input_array[n + 1];
    char output_array[n + 1];

    // Convert string parameter to char array (input_array)
    strcpy(input_array, str.c_str());

    // Call to base64_encode to encrypt input_array
    base64_encode(input_array, output_array, strlen(input_array), 1);

    // Convert char array (output_array) back to string
    string outputstring;
    int len = sizeof(output_array)/sizeof(output_array[0]);
    for (int i = 0; i < len; i++) {
        outputstring = outputstring + output_array[i];
    }

    return outputstring;
}