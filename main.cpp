#include <iostream>
#include "passserver.h"

using namespace std;
using namespace cop4530;

void Menu();

// *****************************************************************
// * Function Name:  main()                                        *
// * Description:  Driver that uses PassServer functionality       *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  None                                             *
// *****************************************************************
int main() {
    // Variable declarations
    char choice;
    size_t vector_size;
    string filename, username, password, newpassword;

    // Define Hash Table size
    cout << "Hash Table Size/Capacity: ";
    cin >> vector_size;

    PassServer hTable(vector_size); // Create Hash Table PassServer class object

    // do-while loop
    do{
        // Display menu and read in choice
        Menu();
        cin >> choice;

        if(choice == 'l'){ // If 'l', read in file name and try to load the file
            cout << "File Name: ";
            cin >> filename;
            if(hTable.load(filename.c_str())){
                cout << "Loaded from file" << endl;
            }else{
                cout << "Error: Could not load from file" << endl;
            }
        }else if(choice == 'a'){ // If 'a', read in username & password and try to add it to the server
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            if(hTable.addUser(make_pair(username, password))){
                cout << "Added user" << endl;
            }else{
                cout << "Error: Username/Password combination already exists" << endl;
            }
        }else if(choice == 'r'){ // If 'r', read in username and try to remove the user
            cout << "Enter Username: ";
            cin >> username;
            if(hTable.removeUser(username)){
                cout << "User deleted" << endl;
            }else{
                cout << "Error: Username not found" << endl;
            }
        }else if(choice == 'c'){ // If 'c', read in the username&password & newpassword and try to change the password
            cout << "Enter Username: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;
            cout << "Enter New Password: ";
            cin >> newpassword;
            if(hTable.changePassword(make_pair(username, password), newpassword)){
                cout << "Password changed" << endl;
            }else{
                cout << "Error: Could not change password" << endl;
            }
        }else if(choice == 'f'){ // If 'f', read in username and try to find the user
            cout << "Enter Username: ";
            cin >> username;
            if(hTable.find(username)){
                cout << "Username found" << endl;
            }else{
                cout << "Error: Username not found" << endl;
            }
        }else if(choice == 'd'){ // If 'd', dump the entries in the database to the screen
            cout << "All entries in database" << endl;
            hTable.dump();
        }else if(choice == 's'){ // If 's', display the size of the HashTable
            cout << "HashTable Size is: " << hTable.size() << endl;
        }else if(choice == 'w'){ // If 'w', read in filename and try to write to the file
            cout << "File Name: ";
            cin >> filename;
            if(hTable.write_to_file(filename.c_str())){
                cout << "Wrote to Password File" << endl;
            }else{
                cout << "Error: Could not write to file" << endl;
            }
        }else{ // If none of the above choices, then it is invalid
            cout << "Error: Invalid choice" << endl;
        }
    }while(choice != 'x'); // Break from loop when choice == x
    return 0;
}

// *****************************************************************
// * Function Name:  Menu()                                        *
// * Description:  Menu to display PassServer functions            *
// * Parameter Description:  No parameters                         *
// * Date:  02/21/2022                                             *
// * Author:   Peyton J. Smith                                     *
// * References:  Provided function from assignment write-up       *
// *****************************************************************
void Menu(){
    cout << "\n\n";
    cout << "l - Load From File" << endl;
    cout << "a - Add User" << endl;
    cout << "r - Remove User" << endl;
    cout << "c - Change User Password" << endl;
    cout << "f - Find User" << endl;
    cout << "d - Dump HashTable" << endl;
    cout << "s - HashTable Size" << endl;
    cout << "w - Write to Password File" << endl;
    cout << "x - Exit program" << endl;
    cout << "\nEnter choice : ";
};