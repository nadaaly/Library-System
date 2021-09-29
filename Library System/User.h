//
// Created by 20111 on 11/27/2020.
//

#ifndef MAIN_CPP_USER_H
#define MAIN_CPP_USER_H
#include <string>
#include <iostream>

using namespace std;

class User{
private:
    string name ;
    int age;
    string password;
    string email;
public:
    int id;
    static int count;
    User();
    User(string name, int age, string email, string password);
    User(const User &user);
    void setName(string name);
    string getName() const;
    void setPassword(string password);
    string getPassword();
    void setEmail(string email);
    string getEmail();
    void setAge(int age);
    int getAge();
    void setId(int i);
    int getId();
    bool operator==(const User& user);
    friend ostream &operator<<(ostream &output, const User &user );
    friend istream &operator>>( istream &input, User &user );
};
#endif //MAIN_CPP_USER_H
