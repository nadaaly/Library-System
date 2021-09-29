#include <iostream>
#include "BookList.h"
#include "UserList.h"
#include "Book.h"
#include "User.h"
using namespace std;
int User::count = 1;    // initialize the static member to 1 so it helps in id

User::User()    // default constructor that set the name to empty strings as well as increasing the id
{
	name = " ";
	age=0;
	id = 0;
};

User::User(string name, int age, string email, string password)    /* parameterized constructor that takes from the user name,age,email, and password
and then sets them to the private member function using "this ->"  which is used
to assign the parameter variable to the member variable when they have the same name
and the set the count to id to increase it every time a new user enters their info*/
{

	this->name = name;
	this->age = age;
	this->email = email;
	this->password = password;
};

User::User(const User& user)    // copy constructor that works for the "=" assignment that helps in taking the data
                                // from the left side and puts it to the right side
{


	name = user.name;
	age = user.age;
	email = user.email;
	password = user.password;
	id = user.id;
};

bool condition = false;

bool User::operator==(const User& user)       // operator overloading function used to check if two users are identical
                                                // by checking their names,email, and age
{
	if (name == user.name && age == user.age && email == user.email)
		condition = true;
	return condition;
};

void User::setName(string name)     //assigning the member variable name
{
	this->name = name;
};

string User::getName() const
{
	return name;
};

void User::setPassword(string password)      // assigning the member variable password
{
	this->password = password;
};

string User::getPassword()
{
	return password;
};

void User::setEmail(string email)    // assigning the member variable email
{
	this->email = email;
};

string User::getEmail()
{
	return email;
};

void User::setAge(int age)       // assigning the member variable age
{
	this->age = age;
};

int User::getAge()
{
	return age;
};

void User::setId(int id)     // assigning the member variable id
{
	this->id = id;
};

int User::getId()
{
	return id;
};

ostream& operator<<(ostream& output, const User& user)        // display info such as Name, Age, Id, and Email to user
                                                             // and it returns the ostream variable output
{
    cout<<"======= User"<<" "<<user.id<<" " <<"Info ======="<<endl;

        output << "Name:"<<user.name<<"|" <<"Age:"<< user.age<<"|"<<"ID:"
            << user.id <<"|"<<"Email:"<< user.email <<endl;

    cout<<"======================================="<<endl;
    cout<<endl;

	return output;
};

istream& operator>>(istream& input, User& user)             // allow user to enter info such as name, age, email, and passowrd
                                                            // and it returns the istream variable input
{
	cout<<"Enter the user information in this order"<<endl;
    cout<<"Name"<<"  "<<"Age"<<"  "<<"Email"<<"  "<<"password"<<"  "<<"(Space separated)"<<endl;
    cout<<endl;
user.id = user.count;
    user.count++;
	input >> user.name >> user.age >> user.email >> user.password;
	return input;
};
