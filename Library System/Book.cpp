#include <iostream>
#include "BookList.h"
#include "UserList.h"
#include "Book.h"
#include "User.h"
using namespace std;

int Book::count = 1;  // initialize the static member to 1 so it helps in id

Book::Book()          // default constructor that set the title to empty strings as well as increasing the id
{
    title = "";
    averageRating=0.0;
    id=0;
    sum=0.0;
    counter=1;
};


Book::Book(string title, string isbn, string category)       /* parameterized constructor that takes from the book title,isbn and category
                                                                and then sets them to the private member function using "this ->"  which is used
                                                                to assign the parameter variable to the member variable when they have the same name
                                                                and the set the count to id to increase it every time a new user enters their info*/
{
    this->title = title;
    this->isbn = isbn;
    this->category = category;

    averageRating=0.0;
    sum=0.0;
    counter=1;
};

Book::Book(const Book& book)         // copy constructor that works for the "=" assignment that helps in taking the data
// from the left side and puts it to the right side
{
    title = book.title;
    isbn = book.isbn;
    category = book.category;

    averageRating=0.0;
    id=book.id;
    sum=0.0;
    counter=1;
};

void Book::setTitle(string title)  //assigning the member variable title
{
    this->title = title;
};

string Book::getTitle()    // return title as string
{
    return title;
};

void Book::setISBN(string isbn)     //assigning the member variable isbn
{
    this->isbn = isbn;
};

string Book::getISBN()      // return isbn as string
{
    return isbn;
};

void Book::setId(int id)       //assigning the member variable id
{
    this->id = id;
};

int Book::getId()   //return id as integer
{
    return id;
};

void Book::setCategory(string category)  //assigning the member variable category
{
    this->category = category;
};

string Book::getCategory()     // return category as string
{
    return category;
};

void Book::setAuthor(User user)         //assigning the member variable user and store it in author
{
    author= user;
};

User Book::getAuthor()  // return author as User
{
    return author;
};

void Book::rateBook(int rating)     // update average rating to a new rating,summation rating which in the same object and calculate average
{

    sum+=rating;

    averageRating=sum/counter;
    counter++;

};
double Book::getRate()
{
    return averageRating;
}
void Book::setBookAuthor(string bookAuthor){this->bookAuthor=bookAuthor;}
string Book::getBookAuthor() {return bookAuthor;}

bool Book::operator==(const Book& book)        /* to check if two books are identical by checking their title, isbn, category and
                                                    author and return true if they are identical*/
{
    return (title==book.title)&&(isbn==book.isbn)
           &&(category==book.category)
           &&(author==book.author);
};

ostream& operator<<(ostream& output, const Book& book)     //display info to user and return output as ostream
{
    cout<<"======= Book"<<" "<<book.id<<" "<<"Info ======="<<endl;

    output <<"Title:" <<book.title<<"|"
           <<"ISBN:"<< book.isbn<<"|"
           <<"ID:" <<book.id<<"|"
           <<"Category:"<< book.category<<"|"
           <<"Avg Rating:"<< book.averageRating<<endl;

    cout<<"======================================="<<endl;
    cout<<endl;

    return output;

};



istream& operator>>(istream& input, Book& book)         // allow user to enter variable and return input as istream
{
    cout<<"Enter the book information in this order"<<endl;
    cout<<"Title"<<"  "<<"ISBN"<<"  "<<"Category"<<"(Space separated)"<<endl;
    cout<<endl;
    input >> book.title
          >> book.isbn
          >>book.category ;
    book.id = book.count;
    book.count++;

    return input;
};
