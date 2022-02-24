#ifndef PASSSERVER_H
#define PASSSERVER_H

#include "hashtable.h"
#include "base64.h"
#include <cstring>

using namespace std;

namespace cop4530{

    class PassServer : public HashTable <string, string> {
    public:
        PassServer(size_t size = 101);
        ~PassServer();
        bool load(const char *filename);
        bool addUser(pair<string, string> &kv);
        bool addUser(pair<string, string> &&kv);
        bool removeUser(const string &k);
        bool changePassword(const pair<string, string> &p, const string & newpassword);
        bool find(const string &user);
        void dump();
        size_t size();
        bool write_to_file(const char *filename);
    private:
        string encrypt(const string & str);
    };
}
#endif