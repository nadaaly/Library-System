#include <iostream>
#include "BookList.h"
#include "UserList.h"
#include "Book.h"
#include "User.h"
#include <cstring>
using namespace std;
int UserList::arrayCount=0;
UserList::UserList(){

}

UserList::UserList(int capacity) /* this constructor assign capacity which passed as parameter to capacity member variable
                                    and initialize usersCount =0 and create array users from type User and take capacity as size of array*/
{
    this -> capacity = capacity;
    usersCount = 0;
    users = new User[capacity];
}

void UserList::addSize(int _size)
{
     capacity=_size;
    usersCount = 0;
    users = new User[capacity];
}

void UserList::addUser(User user)  /* this function take user from type User as a parameter and stores it in array users*/
{
    users[usersCount] = user;
    usersCount++;
    arrayCount= usersCount;

}

User& UserList::searchUser(string name)   /* this function take a parameter name from type string and compare this parameter with
                                            users[counter].getName and store users[counter].getId() in variable idDelete and return users[counter] if name and users[counter].getName are identical
                                            else print not found and exit this function*/
{
    for (int counter = 0 ; counter <usersCount ; counter++)
    {
        if( name == users[counter].getName() )
        {
            idDelete = users[counter].getId();
            return  users[counter];
        }
    }
}
User& UserList::searchUser(int id)           /* this function take a parameter id from type integer and compare this parameter with
                                            users[counter].getId and store users[counter].getId() in variable idDelete and return users[counter]
                                            if id and users[counter].getId are identical
                                            else print not found and exit this function*/
{
    for (int counter = 0 ; counter <usersCount ; counter++)
    {
        if( users[counter].getId() == id)
        {
            idDelete=users[counter].getId();
            return users[counter];
        }

    }
}

void UserList::deleteUser(int id)     /* this function take a parameter id from type integer and compare id with users[counter].getId()
                                        and if they are identical it will replace users[counter] by users[counter+1] else
                                            else print not found and exit this function*/
{

    for (int counter = 0 ; counter <usersCount ; counter++)
    {
        if( users[counter].getId() == id)
        {
            users[counter] = users[counter+1];
            usersCount--;
        }
    }

}
ostream &operator<<(ostream &output, const UserList &userList )             //to display all users
{
    for (int counter=0 ; counter<userList.usersCount ; counter++)
    {
        output<<userList.users[counter]<<endl;
    }
    return output;
}
/*
UserList::~UserList()               // delete dynamic array users from memory
{                                       // let the the user name to turn into garbage
    delete[] users;
}
*/
