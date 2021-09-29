#ifndef USERLIST_H_INCLUDED
#define USERLIST_H_INCLUDED
#include "User.h"
class UserList
{
private:
    User* users;
    int capacity;
    int usersCount;
public:
    static int arrayCount;
    int idDelete;
    UserList();
    UserList(int capacity);
    void addUser(User user); // at the end of the array.
    User& searchUser(string name);
    User& searchUser(int id);
    void deleteUser(int id);
    friend ostream &operator<<( ostream &output, const UserList &userList );//to display all books
    void addSize(int _size);

   // ~UserList();  // let the the user name to turn into garbage


};
#endif
